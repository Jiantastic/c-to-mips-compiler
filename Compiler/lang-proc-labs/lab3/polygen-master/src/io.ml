(*
 * Polygen
 * io.ml: I/O functions
 *
 * Alvise Spano' (2002)
 *)

open List
open Prelude
open Prelude
open Lexer
open Parser
open Err
open Absyn

module A = Absyn0

(* load/store compiled grammar *)

let __obj = ".o"

type 'a obj = { sum : string; data : 'a }

let sum = Ver.ver

let make_obj data = { sum = sum; data = data }

let check_obj obj =
	if obj.sum = sum then ()
	else raise (Failure "incompatible compiled grammar object file format")


let load_obj source =
	let file = source ^ __obj in
	let _ = try Unix.access file [Unix.F_OK]
			with _ -> raise (Failure ("compiled grammar object file \"" ^ file ^ "\" does not exist"))
	in
	try
    	let _ =	if (Unix.stat file).Unix.st_mtime < (Unix.stat source).Unix.st_mtime then
            		raise (Failure ("compiled grammar \"" ^ file ^ "\" is older than source grammar"))
            	else ()
        in
    	let ic = open_in_bin file in
    	let obj = (Marshal.from_channel ic : 'a obj) in
    	let _ = check_obj obj;
    			close_in ic
    	in
        	obj.data

    with Unix.Unix_error (e, _, _) ->
    	 io_error ("cannot read file: " ^ (Unix.error_message e))

      |  Sys_error s -> io_error ("cannot read file: " ^ s)


let store_obj source (data : 'a) =
	let file = source ^ __obj in
    try
        let tmp = Printf.sprintf "%s.%d" file (Unix.getpid ()) in
        let oc = open_out_gen [Open_wronly; Open_binary; Open_creat; Open_trunc] 0o600 tmp in
        let obj = make_obj data
        in
            Marshal.to_channel oc obj [];
            close_out oc;
            Unix.chmod tmp 0o666;
            Unix.rename tmp file

    with Unix.Unix_error (e, _, _) ->
    	io_error ("cannot write file: " ^ (Unix.error_message e))

      |  Sys_error s -> io_error ("cannot write file: " ^ s)



(* load grammar source *)

let load_decls file =
    try
        let _ = jump file in
        let ic = open_in file in
        let lexbuf = Lexing.from_channel ic
        in
        try
            let decls = Parser.source Lexer.token lexbuf in
            let _ = close_in ic in
            let _ = jump_back ()
            in
            	decls

        with Failure s -> syntax_error file lexbuf s

          |  Parsing.Parse_error ->
                let s = String.escaped (Lexing.lexeme lexbuf)
                in
                    syntax_error file lexbuf ("unexpected " ^ (if s = "" then "empty token"
                      else "token \"" ^ s ^ "\""))

    with Sys_error s -> io_error ("cannot parse from file \"" ^ s ^ "\"")


(* ugly workaround for Parser <-> Io mutual recursion *)

let _ = Fake.load_decls := load_decls
