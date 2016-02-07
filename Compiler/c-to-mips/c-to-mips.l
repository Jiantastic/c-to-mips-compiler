%option noyywrap
%{
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int line_number = 1,source_line = 1;
bool filename_init = false;
string SourceFile = "";
stringstream ss;

/* 
TODO:
    1. Lexical Analysis for pre-processor - starting with #, otherwise ignore
    2. determine if whitespace  is Invalid
    3. where do ',"",{ , }, ; belong?
    4. # and ## only valid in pre-processor
    5. _ansi.h, stdio.h ----> how to classify?
*/

%}

/* token:*/

KEYWORD     (auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while)

IDENTIFIER  [A-Za-z_][A-Za-z0-9_]*  

/* 
    TODO: is this correct? -> [expression*],(expression*),{expression*}
    The punctuators [ ] , ( ) , and { } shall occur in pairs, possibly separated by expressions, declarations, or statements. The punctuator # shall occur in preprocessing directives only.
    The operators # and ## shall occur in macro-defining preprocessing directives only. cout << "Invalid" ; if not in preprocessor
    this implementation ignores the difference between OPERATOR and PUNCTATOR
*/

OPERATOR    \.\.\.|\[|\]|##|\|=|\^=|&=|>>=|<<=|\-=|\+=|%=|\/=|\*=|\|\||&&|\^|!=|==|>=|<=|>>|<<|\+\+|\-\-|[\.&+\-\*~!%\\(\)\/<>\|=,;#?:{}]|sizeof

/* 
    4 regex expressions separated by | - In order:
    floating constant - [0-9]+\.?[0-9]*[e|E]?[\+|\-]?[0-9]*[f|l|F|L]?
    integer constant - (?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)? implemented as (?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)[uUlL]?(?:(?<=u|U)[lL]|(?<=l|L)[uU])? is not supported
    enumeration constant - An identifier declared as an enumeration constant has type int.
    TODO: L,escape sequences character constant - any char except those listed in the C89 spec 
*/

CONSTANT        [0-9]+\.?[0-9]*[e|E]?[\+|\-]?[0-9]*[f|l|F|L]?|(?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)?|[L]?'[^\n\\']'

/* StringLiteral TODO: escape sequences, L etc.... refer to C89 spec, ' ' and " " is still invalid */

STRINGLITERAL   [L]?"[^\n\\\"]*"


/* preprocessing-token: */

/*HEADER-NAME

PRE-IDENTIFIER

PP-NUMBER

PRE-CONSTANT

PRE-STRINGLITERAL

PRE-OPERATOR

PRE-PUNCTUATOR*/


%%


{KEYWORD}               cout << yytext << " Keyword " << "token type " << line_number << " " << SourceFile << " " << source_line << endl;

{IDENTIFIER}            cout << yytext << " Identifier " << "token type " << line_number << " " << SourceFile << " " << source_line << endl;

{OPERATOR}              cout << yytext << " Operator " << "token type " << line_number << " " << SourceFile << " " << source_line << endl;

{CONSTANT}              cout << yytext << " Constant " << "token type " << line_number << " " << SourceFile << " " << source_line << endl;

{STRINGLITERAL}         cout << yytext << " StringLiteral " << "token type " << line_number << " " << SourceFile << " " << source_line << endl;

.                       cout << yytext << " Invalid " << "token type " << line_number << " " << SourceFile << " " << source_line << endl;

\n                      line_number++;

%%

int main()
{
    getline(cin,SourceFile);
    for(int i=0;i<SourceFile.length();++i){
        if(SourceFile[i] == '\"'){
            filename_init = !filename_init;
        }
        else if(filename_init){
            ss << SourceFile[i];
        }
    }
    SourceFile = ss.str();
    cout << "initialize test" << endl;
    cout << SourceFile << endl;

    yylex();
    
    /* function yylex processes the standard input and every time a token is recognized it executes the corresponding code */
    
    return 0;
}


