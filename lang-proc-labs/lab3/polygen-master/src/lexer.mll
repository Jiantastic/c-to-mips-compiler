(*
 * Polygen
 * lexer.mll: lexer definition for Lex
 *
 * Alvise Spano' (2002)
 *)

{
open Parser
open Parser
}

rule quote = parse
    '"'             { "" }
  | "\\\""          { "\"" ^ (quote lexbuf) }
  | "\\\\"          { "\\" ^ (quote lexbuf) }
  | "\\n"           { "\n" ^ (quote lexbuf) }
  | "\\r"           { "\r" ^ (quote lexbuf) }
  | "\\b"           { "\b" ^ (quote lexbuf) }
  | "\\t"           { "\t" ^ (quote lexbuf) }

  | '\\' ['0'-'9'] ['0'-'9'] ['0'-'9']
                    { let s = String.sub (Lexing.lexeme lexbuf) 1 3 in
                      let c = String.make 1 (char_of_int (int_of_string s))
                      in
                          c ^ (quote lexbuf) }

  | ['a'-'z' 'A'-'Z' '0'-'9' '!' '£' '$' '%' '&' '/' '(' ')' '=' '?' '^' '\''
     '[' ']' '*' '+' '@' '#' '<' '>' ',' '.' '-' ';' ':' '_' '{' '}' '`' '~'
     '|' ' ']       { let s = Lexing.lexeme lexbuf in s ^ (quote lexbuf) }

  | _                { raise (Failure ("illegal character '" ^ (String.escaped (Lexing.lexeme lexbuf)) ^ "' within quote")) }

and comment = parse
    "*)"            { token lexbuf }
  | "(*"            { comment lexbuf }
  | '\n'
  | "\r\n"	        { Err.next_line lexbuf; comment lexbuf }
  | _               { comment lexbuf }

and token = parse
    [' ' '\t']      { token lexbuf }        (* skip blanks *)
  | "(*"            { comment lexbuf }      (* skip comments *)

  | '\n'
  | "\r\n"	        { Err.next_line lexbuf; token lexbuf }

  | ';'             { EOL }
  | ':'             { COLON }
  | '('             { BRA }
  | ')'             { KET }
  | '['             { SQBRA }
  | ']'             { SQKET }
  | "::="           { DEF }
  | ":="            { ASSIGN }
  | '|'             { PIPE }
  | '>'             { GT }
  | ">>"            { GTGT }
  | '<'             { LT }
  | "<<"            { LTLT }
  | '{'             { CBRA }
  | '}'             { CKET }
  | '*'				{ STAR }
  | '+'             { PLUS }
  | '-'             { MINUS }
  | '^'             { CAP }
  | '_'             { UNDERSCORE }
  | '.'             { DOT }
  | ','				{ COMMA }
  | ".("            { DOTBRA }
  | '"'             { QUOTE (quote lexbuf) }
  | '\\'            { BACKSLASH }
  | "import"        { IMPORT }
  | "as"            { AS }
  | '/'             { SLASH }

  | ['a'-'z' '0'-'9' '\''] ['a'-'z' 'A'-'Z' '0'-'9' '\'']* { TERM (Lexing.lexeme lexbuf) }
  | ['A'-'Z'] ['a'-'z' 'A'-'Z' '0'-'9']*					 { NONTERM (Lexing.lexeme lexbuf) }
  | '.' ['a'-'z' 'A'-'Z' '0'-'9']+				             { let s = Lexing.lexeme lexbuf in
                                                                    DOTLABEL (String.sub s 1 (String.length s - 1)) }

  | eof             { EOF }

  | _    		    { raise (Failure ("illegal character '" ^ (String.escaped (Lexing.lexeme lexbuf)) ^ "'")) }

