%option noyywrap
%{
#include <iostream>

using namespace std;


int line_number = 1;
%}


/* token:*/

KEYWORD     (auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while)

IDENTIFIER  [A-Za-z_][A-Za-z0-9_]*  

/* 
    pair operators TODO - [], (), ?: , check expression in between [],() and ?:
    The operators # and ## shall occur in macro-defining preprocessing directives only.
*/

OPERATOR    ##|\|=|\^=|&=|>>=|<<=|\-=|\+=|%=|\/=|\*=|\|\||&&|\^|!=|==|>=|<=|>>|<<|\+\+|\-\-|[\.&+\-\*~!%\\(\)\/<>\|=,#]|sizeof

/* 
    4 regex expressions separated by | - In order:
    floating constant - [0-9]+\.?[0-9]*[e|E]?[\+|\-]?[0-9]*[f|l|F|L]?
    integer constant - (?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)? implemented as (?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)[uUlL]?(?:(?<=u|U)[lL]|(?<=l|L)[uU])? is not supported
    enumeration constant - An identifier declared as an enumeration constant has type int.
    TODO: L,escape sequences character constant - any char except those listed in the C89 spec 
*/

CONSTANT        [0-9]+\.?[0-9]*[e|E]?[\+|\-]?[0-9]*[f|l|F|L]?|(?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)?|[L]?'[^'\n\]+'

/* StringLiteral TODO: escape sequences, L etc.... refer to C89 spec

STRINGLITERAL   ".*"    

INVALID         [^ ]

/* preprocessing-token: */


/* 
below, notice that we can use braces if the action requires more than one instruction
for ints the approach follows the previous examples, for other tokens there is only a return 
*/

%%


{KEYWORD}               cout << yytext << " Keyword " << "Insert desired token type " << line_number << endl;

{IDENTIFIER}            cout << yytext << " Identifier " << "Insert desired token type " << line_number << endl;

{OPERATOR}              cout << yytext << " Operator " << "Insert desired token type " << line_number << endl;

{CONSTANT}              cout << yytext << " Constant " << "Insert desired token type " << line_number << endl;

{STRINGLITERAL}         cout << yytext << " StringLiteral " << "Insert desired token type " << line_number << endl;

.                       cout << yytext << " Invalid " << "Insert desired token type " << line_number << endl;

\n

%%

int main()
{
    yylex();
    line_number++;
    
    /* function yylex processes the standard input and every time a token is recognized it executes the corresponding code */
    
    return 0;
}


