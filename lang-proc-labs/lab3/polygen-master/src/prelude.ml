(*
 * Polygen
 * prelude.ml: misc stuff
 *
 * Alvise Spano' (2002)
 *)

module Prelude =
  struct

    (* global exceptions *)
    exception Unexpected of string

    (* either parametric type *)
    type ('a, 'b) either = Former of 'a | Latter of 'b

    let is_former e =
        match e with
            Former _ -> true
          | _        -> false

    let is_latter e = not (is_former e)

    let surely_former e =
        match e with
            Former x -> x
          | _        -> raise (Unexpected "prelude.ml: surely_former")

    let surely_latter e =
        match e with
            Latter x -> x
          | _        -> raise (Unexpected "prelude.ml: surely_latter")

    (* type for symbols *)
    type symbol = string

    (* side-effect the latter and return the former *)
    let before a b = b; a

    (* function composition *)
    let ($) f g x = f (g x)

    (* check whether an element occurs in a list *)
    let occurs l x = List.exists ((=) x) l

    (* check whether two lists are disjoint *)
    let disjoint (=) l1 l2 = List.for_all (fun x -> not (List.exists ((=) x) l1)) l2

    (* link strings within a list interleaving with a space char *)
    let rec flatten_strings spc l =
        match l with
            []      -> ""
          | s :: [] -> s
          | s :: l' -> s ^ spc ^ (flatten_strings spc l')

    let mappen_strings f spc l = flatten_strings spc (List.map f l)

    (* assoc on lists/arrays raising Unexpected *)
    let surely_assoc x l =
        try List.assoc x l
        with Not_found -> raise (Unexpected "prelude.ml: surely_assoc")


    (* functorial cache *)

    module type CacheKey =
      sig
      	type t
      	val (=) :  t -> t -> bool
      end

    module Cache : functor (Key : CacheKey) ->
      sig
      	type 'v t
      	val init : unit -> 'v t
      	val load : 'v t -> Key.t -> 'v Lazy.t -> 'v
      end
      = functor (Key : CacheKey) ->
      struct
      	module HashKey : Hashtbl.HashedType with type t = Key.t =
      	  struct
      	  	type t = Key.t
      	  	let equal = Key.(=)
      	  	let hash = Hashtbl.hash
      	  end

      	module Tbl = Hashtbl.Make (HashKey)

      	type 'v t = 'v option Tbl.t

      	let init () = Tbl.create 100

      	let load tbl x suspension =
        	try
            	match Tbl.find tbl x with
            	    None   -> Lazy.force suspension
            	  | Some y -> y

        	with Not_found ->
            	let _ = Tbl.add tbl x None in
            	let y = Lazy.force suspension in
            	let _ = Tbl.replace tbl x (Some y)
            	in
                	y
      end

 	(* label set *)

    module Label : Set.OrderedType with type t = symbol =
	  struct
	  	type t = symbol
	  	let compare lb1 lb2 = compare lb1 lb2
	  end

	module LabelSet =
	  struct
	  	include Set.Make (Label)

	  	let of_labels labels = List.fold_left (fun lbs lb -> add lb lbs) empty labels
	  	let occurs = mem
        let pretty lbs = "{" ^ (flatten_strings ", " (elements lbs)) ^ "}"
	  end

	(* mapfst & mapsnd *)
    let mapfst f (a, b) = (f a, b)
    let mapsnd f (a, b) = (a, f b)

    (* extract Some of an option *)
    let surely_some o =
        match o with
            Some x -> x
          | None   -> raise (Unexpected "prelude.ml: surely_some")

    (* return tail segment of list l after the first verification of predicate p *)
    let tail_segment p l =
        let rec recur r = function
            []      -> []
          | x :: xs -> let r' = x :: r
                       in
                           if p x then r' else recur r' xs
    in
        recur [] l

    (* tabulate a list *)
    let rec tab f n = if n = 0 then [] else let n = n - 1 in (f n) :: tab f n

  end
