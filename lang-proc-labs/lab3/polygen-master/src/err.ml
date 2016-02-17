(*
 * Polygen
 * err.ml: error handlers
 *
 * Alvise Spano' (2002-03)
 *)

open Printf
open List

(* error locations *)

type loc = string * int * int * int * int

type jump = {file: string; lines: int list ref}

let jumps : jump Stack.t = Stack.create ()

let jump file = Stack.push {file = file; lines = ref [0]} jumps

let jump_back () = ignore (Stack.pop jumps)

let next_line lexbuf =
    let lines = (Stack.top jumps).lines
    in
        lines := (Lexing.lexeme_end lexbuf) :: !lines

let localize (s, e) =
    let j = Stack.top jumps in
    let clip x =
        let lines' = filter (fun y -> y <= x) !(j.lines) in
        let base = hd lines'
        in
            (length lines', x - base)
    in
    let (ls, cs) = clip s in
    let (le, ce) = clip e
    in
        (j.file, ls, cs, le, ce)


(* errors *)

let max_warning_level = 3
let warning_level = ref 1

let uwarning lv s = if lv <= !warning_level then eprintf "warning: %s\n" s else ()

let uerror s = eprintf "error: %s\n" s; exit 1

let localized_prompt s (file, ls, cs, le, ce) =
    let locs =
        match (ls = le, cs = ce) with
            (true, true)  -> sprintf "at line %d, col %d" ls cs
          | (true, false) -> sprintf "at line %d, col %d-%d" ls cs ce
          | _              -> sprintf "from line %d, col %d to line %d, col %d" ls cs le ce
    in
        sprintf "%s: %s %s" file s locs

let localized_msg (file, ls, cs, le, ce) =
    let locs =
        match (ls = le, cs = ce) with
            (true, true)  -> sprintf "at line %d, col %d" ls cs
          | (true, false) -> sprintf "at line %d, col %d-%d" ls cs ce
          | _              -> sprintf "from line %d, col %d to line %d, col %d" ls cs le ce
    in
        "in file " ^ file ^ " " ^ locs

let error loc s = uerror (localized_prompt s loc)

let warning lv loc s = uwarning lv (localized_prompt s loc)

let info (file, _, _, _, _) s = printf "%s: %s\n" file s 

let merror loc s ss =
	error loc s;
	iter (fun s -> eprintf "       %s\n" s) ss

let mwarning lv loc s ss =
	warning lv loc s;
	iter (fun s -> eprintf "         %s\n" s) ss

let minfo ((file, _, _, _, _) as loc) s ss =
    let tab = String.make (String.length file + 2) ' '
    in
        info loc s;
        iter (fun s -> printf "%s%s\n" tab s) ss

let syntax_error file lexbuf s =
    error (localize (Lexing.lexeme_start lexbuf, Lexing.lexeme_end lexbuf)) s

let io_error s = uerror s

let arg_error s = uerror s
