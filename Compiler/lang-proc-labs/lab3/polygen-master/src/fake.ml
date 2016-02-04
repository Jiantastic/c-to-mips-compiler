(*
 * Polygen
 * fake.ml: fakes dued to system lacks
 *
 * Alvise Spano' (2003)
 *)


(* ugly workaround for Parser <-> Io mutual recursion *)
let load_decls : (string -> Absyn.Absyn0.decl list) ref = ref (fun x -> [])

