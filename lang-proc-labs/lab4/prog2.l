%option noyywrap
%{
#include <iostream>

using namespace std;

%}

PREPROCESSOR [#][a-z]*.<[a-z]*>
USING    "using"^[^ ]*[a-z]+^[^]*[a-z]*
DIGIT    [0-9]
ID       [a-z][a-z0-9]*
COMMENT  \/\/.*
IF_ELSE  if|else
MATH_OP  (<=|>=|==|[+-><=%\/*])
STRING   ".*"




/* 
below, notice that we can use braces if the action requires more than one instruction
for ints the approach follows the previous examples, for other tokens there is only a return 
*/

%%

{PREPROCESSOR}          {
                            cout << "PREPROCESSOR_INCLUDE" << endl;
                        }

{USING}                 {
                            cout <<"USING_DIRECTIVE" << endl;
                        }

{STRING}                {
                            cout <<"STRING<" << yytext << ">";
                        }

{IF_ELSE}               {
                            cout << "SELECT_KWD<" << yytext << ">";
                        }

{DIGIT}+                {
                            cout << "INT_NUM<" << yytext << ">";
                        }

{ID}                    {
                            cout << "ID<" << yytext << ">"; 
                        }

{COMMENT}               {
                            cout << "(COMMENT)" << endl;
                        }



MATH_OP                 {
                            cout << "MATH_OP<" << yytext << ">";
                        }




.                       { 
                            cout << yytext;
                        }

\n

%%

int main()
{
    yylex();
    
    /* function yylex processes the standard input and every time a token is recognized it executes the corresponding code */
    
    return 0;
}


