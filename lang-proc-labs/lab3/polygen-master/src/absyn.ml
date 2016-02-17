(*
 * Polygen
 * absyn.ml: abstract syntax definition
 *
 * Alvise Spano' (2002)
 *)

open Prelude
open Prelude
open List

(* path type for non-terminal symbols *)

type path = Path of symbol list * symbol

let pretty_path (Path (ps, sym)) =
    match ps with
        [] -> sym
      | _  -> (flatten_strings "/" ps) ^ "/" ^ sym


module Absyn0 =
  struct
  	type sub_mode = Std | Mob

  	type bind_mode = Def | Assign

    type atom' =
        Terminal of terminal
      | Sel of atom * symbol option
      | Fold of unfoldable
      | Unfold of unfoldable
      | Lock of unfoldable


    and terminal =
        Epsilon
      | Concat
      | Capitalize
      | Term of symbol

    and unfoldable =
        NonTerm of path
      | Sub of sub_mode * decl list * prod

    and seq' = Seq of symbol option * atom list

    and prod' = Prod of seq list

    and decl' = Bind of bind_mode * symbol * prod
              | Import of symbol * decl list

    and atom = atom' * Err.loc

    and seq = seq' * Err.loc

    and prod = prod' * Err.loc

    and decl = decl' * Err.loc


  end

module Absyn1 =
  struct
  	type bind_mode = Def | Assign

    type atom =
        Terminal of terminal
      | NonTerm of path
      | Sel of atom * symbol option
      | Sub of decl list * prod

    and terminal =
        Epsilon
      | Concat
      | Capitalize
      | Term of symbol

    and seq = Seq of symbol option * atom list * int ref

    and prod = Prod of seq list

    and decl = Bind of bind_mode * symbol * prod


    (* pretty stringing *)

    let tab ind s = ind ^ (String.make (String.length s) ' ')

    let rec pretty_atom ind a =
        match a with
            Terminal t    -> pretty_terminal t
          | NonTerm path  -> pretty_path path
          | Sel (a', lbo) ->
                let suff = match lbo with
                              None    -> "."
                            | Some lb -> "." ^ lb
                in
                    (pretty_atom ind a') ^ suff

          | Sub ([], (Prod [_] as p)) -> "(" ^ (pretty_prod ind p) ^ ")"

          | Sub (decls, p) ->
                let tabs = "( " in
                let ind' = tab ind tabs in
                let d = match decls with
                            [] -> ""
                          | _  -> (pretty_decls ind' decls) ^ ind'
                in
                    tabs ^ d ^ (pretty_prod ind' p) ^ " )"

    and pretty_terminal t =
        match t with
            Epsilon       -> "_"
          | Concat        -> "^"
          | Capitalize    -> "\\"
          | Term s	      -> "\"" ^ (String.escaped s) ^ "\""

    and pretty_seq ind (Seq (lbo, atoms, r)) =
        let lb = match lbo with
                    None    -> ""
                  | Some lb -> lb ^ ": "
        in
          	lb ^ (mappen_strings (pretty_atom ind) ("\n" ^ ind) atoms)

    and pretty_prod ind (Prod p) = mappen_strings (pretty_seq ind) ("\n" ^ ind ^ "\b\b| ") p

    and pretty_decl ind (Bind (dm, sym, p)) =
      	let b = match dm with
           	       Def    -> "::="
               	 | Assign -> ":="
       	in
        let tabs = sym ^ " " ^ b ^ " "
        in
            tabs ^ (pretty_prod (tab ind tabs) p)

    and pretty_decls ind decls =
        (mappen_strings (pretty_decl ind) (";\n" ^ ind) decls) ^ ";\n"

  end

module Absyn2 =
  struct
    type terminal =
        Epsilon
      | Concat
      | Capitalize
      | Term of symbol
  end
