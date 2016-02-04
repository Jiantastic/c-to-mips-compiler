(*
 * Polygen
 * env.ml: environment
 *
 * Alvise Spano' (2002)
 *)

open Prelude
open Prelude
open Absyn

module Env =
  struct

    type 'a t = (symbol * 'a) list

    let empty : 'a t = []

    let bind (env : 'a t) xs =  xs @ env

    let lookup (env : 'a t) = function
        Path ([], sym) -> List.assoc sym env
      | Path (_, _)    -> raise (Unexpected "env.ml: lookup")

    (*let find (env : 'a t) f x =
        let sym = fst (List.find (fun (_, x') -> x = f x') env)
        in
            Path ([], sym)*)

  end

