(*
 * Polygen
 * check.ml: grammar checker
 *
 * Alvise Spano' (2002)
 *)

open List
open Printf
open Prelude
open Prelude
open Absyn
open Env
open Err

module Check =
  struct

    module A = Absyn0

    (* global settings *)

    let do_report_groups = ref false


  	(* LabelSet with loc *)

  	module LabelLoc : Set.OrderedType with type t = symbol * Err.loc option =
	  struct
	  	type t = symbol * Err.loc option
	  	let compare (lb1, _) (lb2, _) = compare lb1 lb2
	  end

	module LabelLocSet =
	  struct
	  	include Set.Make (LabelLoc)

	  	let of_labels labels = List.fold_left (fun lbs lb -> add (lb, None) lbs) empty labels
	  	let occurs lb lbs = mem (lb, None) lbs
        let pretty lbs = "{ " ^ (flatten_strings ", " (map fst (elements lbs))) ^ " }"
	  end


    (* label group and group set *)

    type group = Closed of LabelSet.t | Open of LabelSet.t

    module Group =
	  struct
	  	type t = group

        let pretty = function
            Closed lbs -> LabelSet.pretty lbs
          | Open lbs   -> "?" ^ (LabelSet.pretty lbs)

      	let compare g1 g2 =
            match (g1, g2) with
                (Open lbs1, Open lbs2)
              | (Closed lbs1, Closed lbs2) -> LabelSet.compare lbs1 lbs2
              | _                          -> 1
	  end

	module GroupSet = Set.Make (Group)


	(* unique ids *)

    type uid = path * int

	let counter = ref 0
	let fresh sym = (Path ([], sym), (incr counter; !counter))


    (* branch and circuits *)

    module Branch =
	  struct
	  	type t = uid * LabelLocSet.t
	  	let (=) (uid, lbs) (uid', lbs') = uid = uid' && LabelLocSet.equal lbs lbs'
	  end

    module BranchCache = Prelude.Cache (Branch)

	let pretty_branches bs =
	    let paths = map (fun ((path, _), _) -> path) bs in
	    let pathss = map pretty_path ((nth paths (length paths - 1)) :: paths)
	    in
	        flatten_strings "->" pathss


	(* termination magic ring *)

    type termination =
	    Zero
	  | Epsilon of Err.loc
	  | WeakEpsilon of Err.loc
	  | Term
	  | Unterm of Err.loc * Branch.t list

	let reduce_seq = function
	    (Zero, t)
	  | (t, Zero)					 		-> t

	  | (Unterm (loc, bs), Unterm _) 		-> Unterm (loc, bs)

	  | (Epsilon loc, Epsilon _) 	 		-> Epsilon loc

	  | (WeakEpsilon loc, WeakEpsilon _)

	  | (Epsilon _, WeakEpsilon loc)
	  | (WeakEpsilon loc, Epsilon _)		-> WeakEpsilon loc

	  | (Unterm (loc, bs), _)
	  | (_, Unterm (loc, bs))				-> Unterm (loc, bs)

	  | (Term, _)
	  | (_, Term)							-> Term

	let reduce_prod = function
	    (Zero, t)
	  | (t, Zero)							-> t

	  | (Unterm (loc, bs), Unterm _) 		-> Unterm (loc, bs)

	  | (Epsilon loc, Epsilon _) 	 		-> Epsilon loc

	  | (WeakEpsilon loc, WeakEpsilon _)	-> WeakEpsilon loc

	  | (Epsilon _, WeakEpsilon loc)
	  | (WeakEpsilon loc, Epsilon _)		-> WeakEpsilon loc

	  | (Term, Term)     	 				-> Term

	  | (Unterm _, t)
	  | (t, Unterm _)						-> t

	  | (Term, Epsilon loc)
	  | (Term, WeakEpsilon loc)
	  | (Epsilon loc, Term)
	  | (WeakEpsilon loc, Term)	 			-> WeakEpsilon loc


	(* side checkers *)

	let check_override decls =
	    let f (nonterms, imports) (decl, loc) =
	    	match decl with
	        	A.Bind (_, sym, _) ->
	        	    if exists ((=) sym) nonterms then error loc (sprintf "overriding of non-terminal symbol '%s'" sym)
	            	else (sym :: nonterms, imports)

		      | A.Import (sym, _) ->
	    	  		if exists ((=) sym) imports then error loc (sprintf "overriding of import path symbol '%s'" sym)
	        	   	else (nonterms, sym :: imports)

	    in
	        ignore (fold_left f ([], []) decls)


	let check_useless_permutations atoms =
	    let f z (a, loc) =
	        let rec recur a =
	        	match a with
	            	( A.Fold (A.Sub (A.Mob, _, _))
	            	| A.Unfold (A.Sub (A.Mob, _, _))
	            	| A.Lock (A.Sub (A.Mob, _, _)))  -> true

	          	  | A.Sel ((a', _), _)               -> recur a'
	          	  | _                                -> false
	        in
	            if recur a then loc :: z else z
	    in
	        match fold_left f [] atoms with
	            [loc] -> warning 2 loc "useless permutation"
              | _     -> ()


	let check_useless_unfoldings (a, loc) =
		match a with
			A.Unfold (A.Sub (_, _, (A.Prod seqs, _))) ->
				if length seqs == 1 then warning 2 loc "useless unfolding"
				else ()

		  | _ -> ()


	(*
     * checkers
     *)

    (* flat checker:
     *   existence of non-terminals
     *   useless permutations
     *)

    let rec check_flat decls =

		let declare env decls =
			let f (decl, _) =
				match decl with
					A.Bind (_, sym, p) -> (sym, p)
				  | A.Import _		   -> raise (Unexpected ("import not supported yet"))
			in
				Env.bind env (map f decls)
		in

		let rec check_decls env decls =
			let f (decl, _) =
				match decl with
					A.Bind (_, _, p) -> check_prod env p
				  | A.Import _	     -> raise (Unexpected ("import not supported yet"))
            in
                iter f decls

		and check_prod env (A.Prod seqs, _) = iter (check_seq env) seqs

		and check_seq env (A.Seq (_, atoms), _) =
			check_useless_permutations atoms;
	        iter (check_atom env) atoms

		and check_atom env (a, loc) =
			match a with
				A.Terminal _ -> ()

			  | A.Sel (a, _) -> check_atom env a

			  |	A.Lock (A.NonTerm path)
		      | A.Fold (A.NonTerm path)
		      | A.Unfold (A.NonTerm path) ->
		      		(try ignore (Env.lookup env path)
	        		with Not_found -> error loc (sprintf "undefined non-terminal symbol '%s'" (pretty_path path)))
	                
		      | A.Lock (A.Sub (_, decls, p))
		      | A.Fold (A.Sub (_, decls, p))
		      | A.Unfold (A.Sub (_, decls, p)) ->
                    let env' = declare env decls in
                    let _ = check_decls env' decls
                    in
                        check_prod env' p

		in
			check_decls (declare Env.empty decls) decls
            

    (* unfolding checker:
     *   cyclic unfoldings
     *   useless unfoldings
     *)

	let rec check_unfolding decls =

		let declare env decls =
			let f (decl, _) =
				match decl with
					A.Bind (m, sym, p) -> (sym, (fresh sym, m, p))
				  | A.Import _		   -> raise (Unexpected ("import not supported yet"))
			in
				Env.bind env (map f decls)
		in

		let rec check_decls env uids decls =
			let f (decl, _) =
				match decl with
					A.Bind (_, sym, p) -> 
                        let (uid, _, _) = Env.lookup env (Path ([], sym))
                        in
                            check_prod env (uid :: uids) p
                            
				  | A.Import _		   -> raise (Unexpected ("import not supported yet"))
            in
                iter f decls

		and check_prod env uids (A.Prod seqs, _) = iter (check_seq env uids) seqs

		and check_seq env uids (A.Seq (_, atoms), _) = iter (check_atom env uids) atoms

		and check_atom env uids (a, loc) =
			let _ = check_useless_unfoldings (a, loc)
	    	in
	    	match a with
				A.Terminal _ -> ()

			  | A.Sel (a, _) -> check_atom env uids a

			  |	A.Lock (A.NonTerm _)
		      | A.Fold (A.NonTerm _) -> ()

		      | A.Unfold (A.NonTerm path) ->
		      		let (uid, m, p) = Env.lookup env path
	                in
                    let _ = match m with
	        					A.Assign -> warning 2 loc (sprintf "unfolding of assignment-bound symbol '%s'" (pretty_path path))
	        			      | _ 		 -> ()
	        		in
	        			if occurs uids uid then
		      				error loc (sprintf "cyclic unfolding of symbol '%s'" (pretty_path path))
		      			else
		      				check_prod env (uid :: uids) p

		      | A.Lock (A.Sub (_, decls, p))
		      | A.Fold (A.Sub (_, decls, p))
		      | A.Unfold (A.Sub (_, decls, p)) ->
                    let env' = declare env decls in
                    let _ = check_decls env' uids decls
                    in
                        check_prod env' uids p

		in
			check_decls (declare Env.empty decls) [] decls


    (* termination checker
     *   destructive selection
     *   cyclic recursion
     *   epsilon-production
     *   label group inference
     *)
    
	let report_groups (sym, loc) gs =
        if !do_report_groups then
            let gs = filter (fun (Open lbs | Closed lbs) -> not (LabelSet.is_empty lbs)) (GroupSet.elements gs) in
            let gs =
                let f = function Open _ -> true | Closed _ -> false in
                let (ogs, cgs) = partition f gs
                in
                    cgs @ ogs
            in
            let prefix = sym ^ " :: " in
            let tab = String.make (String.length prefix) ' '
            in
                match gs with
                    []      -> info loc (prefix ^ "?{}")
                  | g :: gs -> minfo loc (prefix ^ (Group.pretty g)) (map (fun g -> tab ^ (Group.pretty g)) gs)
        else ()

    let report_termination sym t =
		match t with
	    	Zero 			 -> raise (Unexpected ("check.ml: report"))
	      | Unterm (loc, bs) -> error loc (sprintf "cyclic recursion over circuit %s" (pretty_branches bs))
  		  | Epsilon loc 	 -> error loc (sprintf "symbol '%s' always produces nothing" sym)
  		  | WeakEpsilon loc  -> warning 1 loc (sprintf "symbol '%s' may produce nothing" sym)
  		  | Term 			 -> ()

   	type args = { lbs      : LabelLocSet.t;
	              branches : Branch.t list;
	              env      : (uid * A.prod) Env.t }

	let cache : (GroupSet.t * termination) BranchCache.t = BranchCache.init ()

    let check_termination lbs decls start =

		let rec declare env decls =
			let _ = check_override decls in
			let f (decl, _) =
				match decl with
			    	A.Bind (_, sym, p) -> (sym, (fresh sym, p))
		      	|	A.Import _  	   -> raise (Unexpected "import not supported yet")
			in
				Env.bind env (map f decls)

        and check_bind r (sym, loc) = branch (r, loc, Path ([], sym))

		and check_nested_decls r decls =
			let f r (decl, loc) =
				match decl with
	        		A.Bind (A.Assign, sym, _) -> let (_, t) = check_bind r (sym, loc)
                                                 in
                                                    report_termination sym t
                  | A.Bind (A.Def, _, _)      -> ()
                  | A.Import (_, decls')      -> check_nested_decls {branches = []; env = Env.empty; lbs = LabelLocSet.empty} decls'
	    	in
	    		iter (f r) decls

        and check_global_decls r decls =
            let report sym loc =
                let (gs, t) = check_bind r (sym, loc)
                in
                    report_termination sym t;
                    report_groups (sym, loc) gs
            in
			let f r (decl, loc) =
				match decl with
	        		A.Bind (A.Assign, sym, _)               -> report sym loc
                  | A.Bind (A.Def, sym, _) when sym = start -> report sym loc
                  | A.Bind (A.Def, _, _)                    -> ()
                  | A.Import (_, decls')                    -> check_global_decls {branches = []; env = Env.empty; lbs = LabelLocSet.empty} decls'
	    	in
	    		iter (f r) decls

	    and check_atom r (a, loc) =
	    	match a with
		        A.Terminal t -> (match t with
		                            A.Epsilon
		                          | A.Capitalize
		                          | A.Concat     -> (GroupSet.empty, Epsilon loc)
		                          | A.Term sym   -> (GroupSet.empty, Term))


		      | A.Sel (a', None)    -> check_atom {r with lbs = LabelLocSet.empty} a'
		      | A.Sel (a', Some lb) ->
		      		let (gs, t) = check_atom {r with lbs = LabelLocSet.add (lb, Some loc) r.lbs} a' in
		      		let gs' = GroupSet.filter (fun (Closed lbs | Open lbs) -> not (LabelSet.occurs lb lbs)) gs
                    in
		      			(gs', t)

		      | A.Lock (A.NonTerm path)
		      | A.Fold (A.NonTerm path)
		      | A.Unfold (A.NonTerm path) -> branch (r, loc, path)

			  | A.Lock (A.Sub (_, decls, p))
		      | A.Fold (A.Sub (_, decls, p))
		      | A.Unfold (A.Sub (_, decls, p)) ->
                    let r' = {r with env = declare r.env decls} in
		      		let _ = check_nested_decls r' decls
		      		in
		      		    check_prod r' p


	    and check_seq r (A.Seq (_, atoms), _) =
	        let f (gs, t) a =	let (gs', t') = check_atom r a
	        					in
	        						(GroupSet.union gs gs', reduce_seq (t, t'))
	        in
	            fold_left f (GroupSet.empty, Zero) atoms


	    and check_prod r (A.Prod seqs, loc) =
	    	let g =
	    		let lbs = let f z = function (A.Seq (None, _), _)    -> z
	    						         |   (A.Seq (Some lb, _), _) -> LabelSet.add lb z
	    				  in
	    				      fold_left f LabelSet.empty seqs
	    		in
	    			if let f = function (A.Seq (None, _), _)   -> true
	    							|   (A.Seq (Some _, _), _) -> false
	    			   in
	    			   	   exists f seqs
	    			then Open lbs
	    			else Closed lbs
	    	in
	    	let (gs, t) =
	    		let seqs' = if LabelLocSet.is_empty r.lbs then seqs
	    					else let f (A.Seq (lbo, _), _) =
	              	  				match lbo with
	                          	  		None    -> true
	                        	      | Some lb -> LabelLocSet.occurs lb r.lbs
	                      	  	 in
	                          	 	filter f seqs
	    		in
	    			if length seqs' = 0 then
	            		let ss =
                            let f (lb, loco) =
	            			    let where = match loco with
	            								Some loc -> localized_msg loc
	            							  | None	 -> "at top level"
	            		        in
	            			        "'" ^ lb ^ "' activated " ^ where
                            in
                                map f (LabelLocSet.elements r.lbs)
	            		in
                            mwarning 1 loc "destructive selection" ("due to current label environment:" :: ss);
	            			(GroupSet.empty, Epsilon loc)
                    else
	    				let f (gs, t) seq =
                            let (gs', t') = check_seq r seq
	        				in
	       					    (GroupSet.union gs gs', reduce_prod (t, t'))
                        in
	        				fold_left f (GroupSet.empty, Zero) seqs'
	        in
	        	(GroupSet.add g gs, t)


	    and branch (r, loc, path) =
	    	let (uid, p) = Env.lookup r.env path
	        in
		   		BranchCache.load cache (uid, r.lbs) (lazy (branch_ (r, loc, uid, p)))

	    and branch_ (r, loc, uid, p) =
	    	match tail_segment (Branch.(=) (uid, r.lbs)) r.branches with
		    	[] 	     -> check_prod {r with branches = (uid, r.lbs) :: r.branches} p
		      | branches -> (GroupSet.empty, Unterm (loc, branches))

		in
            let r = { lbs = LabelLocSet.of_labels (LabelSet.elements lbs);
					  branches = [];
					  env = declare Env.empty decls }
			in
                check_global_decls r decls
                
            (*let (_, loc) = find (function (A.Bind (_, sym, _), _) -> sym = start | _ -> false) decls
            in*)
                
                (*let (gs, t) = check_bind r (start, loc)
                in
                    report_termination start t;
                    report_groups (start, loc) gs*)
            	
                



   	(* main check *)

   	let check lbs decls start =
        let _ = try ignore (find (function (A.Bind (_, sym, _), _) -> sym = "I" | _ -> false) decls)
                with Not_found -> uwarning 1 "undefined symbol 'I': option -info won't work"
        in
        let _ = try find (function (A.Bind (_, sym, _), _) -> sym = start | _ -> false) decls
                with Not_found -> uerror (sprintf "undefined start symbol '%s'" start)
        in
            check_flat decls;
            check_unfolding decls;
   		    (*check_termination lbs decls start;*)

  end
