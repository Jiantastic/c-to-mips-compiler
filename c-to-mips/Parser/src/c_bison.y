%{
#include <iostream>
#include <cstdlib>

int yylex();
int yyerror(const char* s);

%}

%token NUM INT LROUNDBRACKET RROUNDBRACKET EOLINE IDENTIFIER LCURLYBRACE RCURLYBRACE SEMICOLON

%%

function : INT IDENTIFIER params { std::cout << "FUNCTION : " << $2 << std::endl; }
         ;

params : LROUNDBRACKET RROUNDBRACKET 
       | LROUNDBRACKET values RROUNDBRACKET
       ;

values : INT IDENTIFIER           { std::cout << "    PARAMETER : " << $2 << std::endl; }
       | values INT IDENTIFIER 
       ;


/*

scope_start : LCURLYBRACE       { std::cout << "SCOPE" << std::endl; } ;

scope_end : RCURLYBRACE          


variable : INT IDENTIFIER   { std::cout << "VARIABLE : " << $2 << std::endl; };

bool scoping = false;

Scopes
{ scoping = true; std::cout << "SCOPE" << std::endl;}

 { scoping = false; }


// TODO : identation of 4 spaces
// TODO : Lexer is incomplete - code punctuators, both in regex and lexer cout << ....
VARIABLE : keyword identifier | keyword identifier EXTENSION* ;


EXTENSION : operator (identifier|num);

SCOPE_START : left curly ----- { cout << "SCOPE" << endl; }

SCOPE_END :

*/


%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
