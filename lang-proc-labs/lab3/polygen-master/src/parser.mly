/*
 * Polygen
 * parser.mly: parser definition for Yacc
 *
 * Alvise Spano' (2002-03)
 */

%{
open Absyn
open Absyn.Absyn0
open List
open Prelude
open Prelude
open Parsing

let load_decls = ! Fake.load_decls


(* localize *)

let localizes n m = Err.localize (rhs_start n, rhs_end m)
let localize n = localizes n n


(* reserved symbol *)

let reserved_sym = "__R"


(* shortcuts and sugars *)

let seq a loc = (Seq (None, [(a, loc)]), loc)
let sub seqs loc = Sub (Std, [], (Prod seqs, loc))
let optsub a loc = sub [seq (Terminal Epsilon) loc; seq a loc] loc
let add_decl d (ds, p) = (d :: ds, p)
let reserved_nonterm = Fold (NonTerm (Path ([], reserved_sym)))

(* a.(l1|...|ln) ---> (X ::= a; X.l1 | ... | X.ln) *)
let multisel loc a lbs =
	let f lb = seq (Sel ((reserved_nonterm, loc), Some lb)) loc in
	let b = Bind (Def, reserved_sym, (Prod [(Seq (None, [a]), loc)], loc))
	in
    	Fold (Sub (Std, [(b, loc)], (Prod (map f lbs), loc)))

let posel loc atomss =
	let n = fold_left (fun z atoms -> max z (length atoms)) 1 atomss
	in
		if n = 1 then map hd atomss
		else
			let f n = function
				[atom] -> atom
			  | atoms  -> try nth atoms n
			  			  with _ -> Err.error loc "etherogeneous number of positional atoms in production"
			in
			let seqs = tab (fun n -> (Seq (None, map (f n) atomss), loc)) n
			in
				[(Fold (Sub (Std, [], (Prod seqs, loc))), loc)]


(* plus/minus expander *)

let expand l =
    let rec make n x = if n = 0 then [] else x :: (make (n-1) x) in
    let k =
        let l' = sort (fun (n, _) (n', _) -> compare n n') l
        in
            match l' with
                []          -> raise (Unexpected "parser.mly: expand")
              | (k, _) :: _ -> k
    in
        fold_left (fun z (n, x) -> z @ (make (n-k+1) x)) [] l


(* deep unfolder *)

let rec deep_unfold_unfoldable u =
    match u with
        NonTerm _          -> u
      | Sub (sm, decls, p) -> Sub (sm, decls, deep_unfold_prod p)

and deep_unfold_atom (a, loc) =
    match a with
        Fold u
      | Unfold u      -> (Unfold (deep_unfold_unfoldable u), loc)
      | Sel (a', lbo) -> (Sel (deep_unfold_atom a', lbo), loc)
      | _             -> (a, loc)

and deep_unfold_seq (Seq (lbo, atoms), loc) = (Seq (lbo, map deep_unfold_atom atoms), loc)

and deep_unfold_prod (Prod seqs, loc) = (Prod (map deep_unfold_seq seqs), loc)

%}

%token EOF EOL
%token <string> NONTERM TERM QUOTE DOTLABEL
%token DEF ASSIGN PIPE SQBRA SQKET BRA KET GT GTGT CBRA CKET DOT PLUS MINUS COMMA
       COLON CAP UNDERSCORE DOTBRA BACKSLASH LTLT LT IMPORT AS SLASH STAR

%start source
%type <Absyn0.decl list> source
%start quote
%type <string> quote

%%

quote:
    QUOTE                   { $1 }
;

file:
	QUOTE					{ $1 }
;

source:
	decls EOF 				{ $1 }
;

decls:
    decl EOL                { [($1, localize 1)] }
  | decl EOL decls          { ($1, localize 1) :: $3 }
;

decl:
	NONTERM DEF prod        { Bind (Def, $1, $3) }
  | NONTERM ASSIGN prod     { Bind (Assign, $1, $3) }
  | IMPORT file AS NONTERM	{ Import ($4, load_decls $2) }
;

op:
    PLUS                    { 1 }
  | MINUS                   { -1 }
;

modif:
    op                      { $1 }
  | op modif                { $1 + $2}
;

atom:
	atom_					{ ($1, localize 1) }
;

seq:
	seq_					{ ($1, localize 1) }
;

prod:
	prod_					{ ($1, localize 1) }
;

atom_:
    terminal                { Terminal $1 }
  | unfoldable              { Fold $1 }
  | GT unfoldable           { Unfold $2 }
  | LT unfoldable           { Lock $2 }
  | atom DOT                { Sel ($1, None) }
  | atom DOTLABEL           { Sel ($1, Some $2) }
  | atom DOTBRA labels KET  { multisel (localizes 1 4) $1 $3 }
;

terminal:
    term                    { Term $1 }
  | CAP                     { Concat }
  | UNDERSCORE              { Epsilon }
  | BACKSLASH               { Capitalize }
;

unfoldable:
    path                    { NonTerm (Path (tl $1, hd $1)) }

  | BRA sub KET             { let (decls, p) = $2 in
                                Sub (Std, decls, p) }

  /*  (D; P)+ ---> (X ::= (D; P) (_ | X); X) */
  | BRA sub KET PLUS        { let (decls, p) = $2 in
  							  let loc = localize 2 in
                              let sub' = (Fold (Sub (Std, decls, p)), loc) in
                              let x = reserved_nonterm in
                              let seq' = (Seq (None, [sub'; (Fold (optsub x loc), loc)]), loc) in
                              let decl = (Bind (Def, reserved_sym, (Prod [seq'], loc)), loc) in
                              let p = (Prod [seq x loc], loc)
                              in
                                  Sub (Std, [decl], p) }

  /* [D; P] ---> ((D; P) | _) */
  | SQBRA sub SQKET         { let (decls, p) = $2 in
                                optsub (Fold (Sub (Std, decls, p))) (localize 2) }

  | CBRA sub CKET           { let (decls, p) = $2 in
                                Sub (Mob, decls, p) }

  /* >> D; P << ---> (D; >> P <<) */
  | GTGT sub LTLT           { let (decls, p) = $2 in
                                Sub (Std, decls, (deep_unfold_prod p)) }
;

/* the following replication is needed for making Yacc lookahead */
sub:
	prod							 { ([], $1) }
  |	NONTERM DEF prod EOL prod    	 { ([(Bind (Def, $1, $3), localizes 1 3)], $5) }
  | NONTERM DEF prod EOL sub    	 { add_decl (Bind (Def, $1, $3), localizes 1 3) $5 }
  |	NONTERM ASSIGN prod EOL prod   	 { ([(Bind (Assign, $1, $3), localizes 1 3)], $5) }
  | NONTERM ASSIGN prod EOL sub   	 { add_decl (Bind (Assign, $1, $3), localizes 1 3) $5 }
  | IMPORT file AS NONTERM EOL prod  { ([(Import ($4, load_decls $2), localizes 1 4)], $6) }
  | IMPORT file AS NONTERM EOL sub   { add_decl (Import ($4, load_decls $2), localizes 1 4) $6 }
;

atoms:
	atom					{ [$1] }
  | atom COMMA atoms		{ $1 :: $3 }
;

seq0:
    atoms                   { [$1] }
  | atoms seq0              { $1 :: $2 }
;

seq_:
    seq0                    { Seq (None, posel (localize 1) $1) }
  | label COLON seq0       	{ Seq (Some $1, posel (localizes 1 3) $3) }
;

modif_seq:
    seq                    	{ (0, $1) }
  | modif seq              	{ ($1, $2) }
;

prod0:
    modif_seq               { [$1] }
  | modif_seq PIPE prod0    { $1 :: $3 }
;

prod_:
    prod0                   { Prod (expand $1) }
;

label:
    NONTERM                 { $1 }
  | TERM                    { $1 }
;

modif_label:
    label                  	{ (0, $1) }
  | modif label            	{ ($1, $2) }
;

multilabels:
    modif_label                   { [$1] }
  | modif_label PIPE multilabels  { $1 :: $3 }
;

labels:
    multilabels             { expand $1 }
;

term:
    TERM                    { $1 }
  | QUOTE                   { $1 }
  | IMPORT                  { "import" }
  | AS                      { "as" }
;

path:
    NONTERM                 { [$1] }
  | path SLASH NONTERM      { $3 :: $1 }
;

%%

