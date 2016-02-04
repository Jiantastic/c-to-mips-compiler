%option noyywrap

/* include this option to avoid dependencies on function yywrap (yywrap is only needed if more than one file need to be processed) */

%{
#include <iostream>

using namespace std;

/* we need this here because we use cout in the matching section */
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

/* the declarations above are aliases */

/* 
below: the matching section begins: regex followed by the action that has to be done when a match occurs 

by 'identifier' in our example we mean names that could be suitable for variables in C or C++ 
(cannot begin with a number)

notice that decimal numbers are correctly recognized by their regex and they are not mistaken for a pair of integers (with a . in the middle)

See also http://web.mit.edu/gnu/doc/html/flex_2.html in particular "How the Input is Matched"

"When the generated scanner runs, it analyzes its input looking for strings which match any of its patterns. If it finds more than one match, it takes the one matching the most text (for trailing context rules, this includes the length of the trailing part, even though it will then be returned to the input). If it finds two or more matches of the same length, the rule listed first in the flex input file is chosen.

Once the match is determined, the text corresponding to the match (called the token) is made available in the global character pointer yytext, and its length in the global integer yyleng. The action corresponding to the matched pattern is then executed (a more detailed description of actions follows), and then the remaining input is scanned for another match."
*/

%%

{DIGIT}+                cout << "An integer number: " << yytext << endl;

{DIGIT}+"."{DIGIT}*     cout << "A decimal number: " << yytext << endl;

{ID}                    cout << "An identifier: "<< yytext << endl; 

%%

/* 
end of the matching section
beginning of another section containing the "driver" of the scanner 
*/

int main()
{
    yylex();
    
    /* function yylex processes the standard input and every time a token is recognized it executes the corresponding code */
    
    return 0;
}

