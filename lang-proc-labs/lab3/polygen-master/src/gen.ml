(*
 * Polygen
 * gen.ml: generator
 *
 * Alvise Spano' (2002)
 *)

open List

open Prelude
open Prelude
open Absyn
open Err
open Env
open Lazy

module Gen =
  struct
    module A = Absyn1
    module B = Absyn2

    (* global settings *)

    let do_shuffle = ref true


    (* postprocessor *)

    let rec post cap spc l =
        match l with
            []                 -> ""
          | B.Epsilon :: l'    -> post cap spc l'
          | B.Concat :: l'     -> post cap "" l'
          | B.Capitalize :: l' -> post String.capitalize spc l'
          | B.Term s :: l'     -> spc ^ (cap s) ^ (post (fun s -> s) " " l')


    (* selectors *)

    let plain_select seqs = nth seqs (Random.int (length seqs))

    let shuffle_select seqs =
        let seqs' = sort (fun (A.Seq (_, _, r1)) (A.Seq (_, _, r2)) -> compare !r1 !r2) seqs in
        let A.Seq (_, _, max) = nth seqs' (length seqs' - 1) in
        let rec seek seqs n =
            match seqs with
                []  -> raise (Unexpected "gen.ml: select")
              | [x] -> x
              | (A.Seq (_, _, r) as x) :: ps ->
                    let n' = n - (!max - !r + 1)
                    in
                        if n' <= 0 then x else seek ps n'
        in
        let n = fold_left (fun z (A.Seq (_, _, r)) -> z + (!max - !r + 1)) 0 seqs' in
        let A.Seq (_, _, r) as x = seek seqs' (Random.int (n + 1))
        in
            r := !r + 1; x


    (* generator *)

    let gen lbs decls sym =

		let select = if !do_shuffle then shuffle_select else plain_select in

    	let rec declare env lbs decls =
    		let rec env'= lazy (Env.bind env (map f decls))
    		and f = function
    			A.Bind (A.Def, sym, p)    -> (sym, fun lbs -> gen_prod (force env') lbs p)
    		 |  A.Bind (A.Assign, sym, p) ->
    		 		let x = ref None
    		 		in
    		 			(sym, fun _ -> match !x with
    		 								None    -> let x' = gen_prod (force env') lbs p
    		 										   in
    		 										       x := Some x'; x'
    		 							  | Some x' -> x')
    		in
    			force env'

        and gen_atom env lbs a =
            match a with
            	A.Terminal t ->
            		(match t with
            			A.Epsilon    -> [B.Epsilon]
              	      | A.Concat     -> [B.Concat]
              		  | A.Capitalize -> [B.Capitalize]
              		  | A.Term sym   -> [B.Term sym])

              | A.NonTerm path       -> (Env.lookup env path) lbs
              | A.Sel (a', None)     -> gen_atom env LabelSet.empty a'
              | A.Sel (a', Some lb)  -> gen_atom env (LabelSet.add lb lbs) a'
              | A.Sub (decls, p)     -> gen_prod (declare env lbs decls) lbs p

        and gen_seq env lbs (A.Seq (_, atoms, _)) = flatten (map (gen_atom env lbs) atoms)

        and gen_prod env lbs (A.Prod seqs) =
            let seqs' = if LabelSet.is_empty lbs then seqs
            			else let f (A.Seq (lbo, _, _)) =
                             	match lbo with
                                	None    -> true
                                  | Some lb -> LabelSet.mem lb lbs
                             in
                             	filter f seqs
            in
                match seqs' with
                    [] -> [B.Epsilon]
                  | _  -> gen_seq env lbs (select seqs')

        in
        	let env = declare Env.empty lbs decls in
        	let terms = gen_atom env lbs (A.NonTerm (Path ([], sym)))
        	in
            	post (fun x -> x) "" terms
  end