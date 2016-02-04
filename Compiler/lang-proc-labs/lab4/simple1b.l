%option noyywrap
%{
#include <iostream>

using namespace std;

/* 
showing a different approach: this time some actions associated to regex make member function yylex return a value (associated to the respective token type) and it is the main which handles the action 
*/

enum {
    INTEGERN=256,
    DECIMALN,
    IDENTIFIER
};

/* using enum to list the possible token types, notice that we start from 256 to avoid interferences with other return values of yylex (e.g. 0 means EOF) */

int ints = 0, decims = 0, idents = 0;

/* some variables to keep the count of the various token types */

%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

/* 
below, notice that we can use braces if the action requires more than one instruction
for ints the approach follows the previous examples, for other tokens there is only a return 
*/

%%

{DIGIT}+                {
                            ints++;
                            cout << "Integer: " << yytext << endl;
                            return INTEGERN; 
                        }

{DIGIT}+"."{DIGIT}*     return DECIMALN;

{ID}                    return IDENTIFIER;

.                       /* what happens by default when tokens are not recognized? what do we achieve by including this and the newline below in the matching section (without an associated action)? */

\n

%%

int main()
{
    int lexcode = yylex();
    while(lexcode != 0){
/*     checking what was returned by yylex... */
        if(lexcode == DECIMALN){
            decims++;
            cout << "Decimal: " << yytext << endl;
        }
        else if(lexcode == IDENTIFIER){
            idents++;
            cout << "Identifier: " << yytext << endl;
        }
        /* the INTEGERN case is already handled in the matching section */
        lexcode = yylex();
    }
    
    cout << "There are:" << endl << ints << " integers" << endl << decims << " decimals" << endl << idents << " identifiers" << endl;
    
    return 0;
}

