(*
 * Polygen
 * pre.ml: preprocessor
 *
 * Alvise Spano' (2002)
 *)

open Absyn
open List
open Prelude
open Prelude
open Env
open Lazy

module Pre =
  struct
    module A = Absyn0
    module B = Absyn1

    (* generate all combos of the elements of a list of lists *)

    let rec comb ll =
        match ll with
            []      -> []
          | [xs]    -> map (fun x -> [x]) xs
          | xs::lls ->
                let ll' = comb lls
                in
                    flatten (map (fun x -> map (fun l -> x::l) ll') xs)


    (* permutator *)

    let rec permute l =
        match l with
            []      -> []
          | [x]     -> [[x]]
          | _       -> let perm h x t =
                           map (fun l -> x::l) (permute (h @ t))
                       in
                       let rec expl l h =
                          match l with
                              []    -> []
                            | x::xs -> expl xs (x::h) @ perm h x xs
                       in
                           expl l []

    let arrange mseq =
        let rec proj mseq mseq' =
            match mseq with
                []              -> []
              | (Former _) :: l -> surely_former (hd mseq') :: (proj l (tl mseq'))
              | (Latter a) :: l -> a :: (proj l mseq')
        in
            match permute (filter is_former mseq) with
                []     -> [proj mseq []]
              | mseqs' -> map (proj mseq) mseqs'


    (* preprocessor
     *
     * NOTE: Former denotes mobile atoms
     *       Latter denotes fixed atoms
     *)

    (*type bound = RecClosure of bound Env.t * (symbol * A.prod) list*)

    let pre decls =

    	let rec declare env decls =
            let f (decl, _) =
    			match decl with
    				A.Bind (_, sym, p) -> (sym, p)
                 |  A.Import _		   -> raise (Unexpected "import not supported")
            (*in
            let rc = RecClosure (env, map f decls) in
            let f (decl, _) =
    			match decl with
    				A.Bind (_, sym, _) -> (sym, rc)
                 |  A.Import _		   -> raise (Unexpected "import not supported")*)
            in
                Env.bind env (map f decls)
    		
       	and pre_atom env (a, _) =
    		match a with
       	    	A.Terminal A.Epsilon        -> [Latter (B.Terminal B.Epsilon)]
       	      | A.Terminal A.Concat         -> [Latter (B.Terminal B.Concat)]
          	  | A.Terminal A.Capitalize     -> [Latter (B.Terminal B.Capitalize)]
          	  | A.Terminal (A.Term sym)     -> [Latter (B.Terminal (B.Term sym))]

              | A.Sel (a', lbo) ->
                    let f ma =
                        match ma with
                            Former a -> Former (B.Sel (a, lbo))
                          | Latter a -> Latter (B.Sel (a, lbo))
                    in
                        map f (pre_atom env a') 

              | A.Lock u
              | A.Fold u ->
                    (match u with
                        A.NonTerm path -> [Latter (B.NonTerm path)]

                      | A.Sub (m, decls, p) ->
                      		let env' = declare env decls in
                      		let sub' = B.Sub (pre_decls env' decls, pre_prod env' p)
                      		in
                      			(match m with
                      				A.Mob -> [Former sub'] 
                      			  | A.Std -> [Latter sub']))

              | A.Unfold u ->
                    (match u with
                        A.NonTerm path ->
                            (*let RecClosure (env', bs) = Env.lookup env path in
                            let env =
                                let f (sym, p) = (sym, RecClosure (env, bs))
                                in
                                Env.bind env' (map (fun (sym, p) -> (sym, Rec in
                            let B.Prod seqs = pre_prod env p*)
                            let B.Prod seqs = pre_prod env (Env.lookup env path)
                            in
                                map (fun seq -> Latter (B.Sub ([], B.Prod [seq]))) seqs

                      | A.Sub (m, decls, p) ->
                      		let env' = declare env decls in
                      		let sub' seq = B.Sub (pre_decls env' decls, B.Prod [seq]) in
                      		let B.Prod seqs = pre_prod env' p
                      		in
                      			(match m with
                      				A.Mob -> map (fun seq -> Former (sub' seq)) seqs
    							  | A.Std -> map (fun seq -> Latter (sub' seq)) seqs))


    	and pre_seq env (A.Seq (lbo, atoms), _) =
            let mseqs = comb (map (pre_atom env) atoms) in
            let new_seqs lbo seqs = map (fun seq -> B.Seq (lbo, seq, ref 0)) seqs in
            let seqs = map (fun mseq -> [B.Sub ([], B.Prod (new_seqs None (arrange mseq)))]) mseqs
            in
				new_seqs lbo seqs


        and pre_prod env (A.Prod seqs, _) = B.Prod (flatten (map (pre_seq env) seqs))


        and pre_decls env decls =
        	let f (decl, _) =
        		match decl with
        			A.Bind (A.Def, sym, p)    -> B.Bind (B.Def, sym, pre_prod env p)
                 |  A.Bind (A.Assign, sym, p) -> B.Bind (B.Assign, sym, pre_prod env p)
                 |  A.Import _                -> raise (Unexpected "pre.ml: pre_decl")
    		in
        		map f decls

       	in
       		pre_decls (declare Env.empty decls) decls

  end

