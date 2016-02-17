(*
 * Polygen
 * main.ml: main code
 *
 * Alvise Spano' (2002-03)
 *)

open Printf
open List

open Prelude
open Prelude
open Absyn
open Check
open Pre
open Gen
open Err
open Io


(* argument parsing *)

type mode = Check | Preprocess | Generate

let mode     = ref Generate
let times    = ref 1
let start    = ref "S"
let sources  = ref []
let dest     = ref stdout
let ps       = ref false
let seed     = ref None
let help     = ref false
let eof      = ref "\n"
let verbose  = ref false
let lbs      = ref LabelSet.empty

let specl = [("-eof", Arg.String (fun s -> eof := let lexbuf = Lexing.from_string ("\"" ^ s ^ "\"") in
                                                      try Parser.quote Lexer.token lexbuf
                                                      with Failure s -> arg_error (s ^ " in -eof argument")
                                                        |  Parsing.Parse_error -> arg_error "parse error in -eof argument"),
                  "STR  use string STR as end-of-file (default: STR = \"\\n\")");

             ("-help", Arg.Set help,
                   "    display this help message");

             ("-info", Arg.Unit (fun () -> start := "I"),
                   "    alias for '-S I'");

             ("-l", Arg.String (fun s -> lbs := LabelSet.add s !lbs),
                "LABEL  add LABEL to initial active label environment");

             ("-o", Arg.String (fun s -> dest := try open_out s with Sys_error _ ->
                                                 	io_error ("cannot open file '" ^ s ^ "' for output")),
                "DEST   output to DEST file");

             ("-pedantic", Arg.Unit (fun () -> Err.warning_level := Err.max_warning_level),
                       "set warning level to maximum");

             ("-pre", Arg.Unit (fun () -> mode := Preprocess),
                  "     output preprocessed source grammar");

             ("-seed", Arg.Int (fun n -> seed := Some n; Gen.do_shuffle := false),
                   "N   pass unsigned integer N as random seed");

             ("-S", Arg.String (fun s -> start := s),
                "SYM    use SYM as starting non-terminal symbol (default: SYM = S)");

             ("-t", Arg.Unit (fun () -> mode := Check; Check.do_report_groups := true),
                "       check source grammar and output inferred global label groups");

             ("-v", Arg.Set verbose,
                "       be verbose");

             ("-X", Arg.Int (fun n -> times := n),
                "N      iterate generation for N times (default: N = 1)");

             ("-W", Arg.Int (fun n -> Err.warning_level := n),
                "N      set warning pedantry at level N (default: N = 1)");
             ]

let usage = (sprintf "Polygen (type 2) v%s built %s - http://www.polygen.org\n" Ver.ver Ver.date)
          ^ "Manta/Spinning Kids alias Alvise Spano' anno MMII ac insequenti fecit.\n\n"
          ^ "usage: polygen [OPTION]... SOURCES...\n\n"
          ^ " SOURCE     source file(s) providing grammar definition\n\n"
          ^ " OPTION"

let _ = if (Array.length Sys.argv) < 2 || !help then
            (Arg.usage specl usage;
            exit 0)
        else
            let anon s = sources := !sources @ [s]
            in
                Arg.parse specl anon usage


(* auxiliary stuff *)

let _ = (match !seed with
            None   -> Random.self_init (); seed := Some (Random.bits ())
          | Some _ -> ());
        Random.init (surely_some !seed)

let msg s = if !verbose then (fprintf !dest "* %s\n" s; flush !dest) else ()

let get_decls0 source =
    let decls = msg ("loading source file \"" ^ source ^ "\"...");
                load_decls source
    in
    let _ = msg "checking grammar...";
            Check.check !lbs decls !start
    in
    let _ = flush stderr; flush stdout
    in
       decls

let get_decls1 source =
    let decls0 = get_decls0 source
    in
        msg "preprocessing grammar...";
        Pre.pre decls0


(* main *)

let main source =

    match !mode with
        Check ->
            ignore (get_decls0 source)

      | Preprocess ->
            fprintf !dest "%s\n" (Absyn1.pretty_decls "" (get_decls1 source))

      | Generate ->
      		(* load complied or source grammar *)
            let decls =
            	try
            		msg "loading compiled grammar...";
                    load_obj source
              	with Failure s -> msg s; get_decls1 source
			in

            (* generate *)
            msg ("PRNG seed: " ^ (string_of_int (surely_some !seed)));
            msg ("EOF string: \"" ^ (String.escaped !eof) ^ "\"");
            msg ("initial label environment: " ^ LabelSet.pretty !lbs) ;
            msg ("generator output:");
            for i = 1 to !times do
                fprintf !dest "%s%s" (Gen.gen !lbs decls !start) !eof
            done;

            (* store compiled grammar *)
            try
            	msg "storing compiled grammar...";
            	store_obj source decls
            with Failure s -> msg s
;;


(* main code *)

try
    iter main !sources;
    close_out !dest
with Unexpected s ->
    eprintf "Unexpected termination: %s\n* Please send a bug report to the author at manta@polygen.org" s

