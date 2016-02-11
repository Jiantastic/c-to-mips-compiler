%option noyywrap
%{
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

int line_number = 1,source_line = 1;
bool filename_init = false;
string SourceFile = "";
string temp = "";
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

OPERATOR    \.\.\.|\[|\]|##|\|=|\^=|&=|->|>>=|<<=|\-=|\+=|%=|\/=|\*=|\|\||&&|\^|!=|==|>=|<=|>>|<<|\+\+|\-\-|[\.&+\-\*~!%\\(\)\/<>\|=,;#?:{}]|sizeof

/* 
    4 regex expressions separated by | - In order:
    floating constant - [0-9]+\.?[0-9]*[e|E]?[\+|\-]?[0-9]*[f|l|F|L]?
    integer constant - (?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)? implemented as (?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)[uUlL]?(?:(?<=u|U)[lL]|(?<=l|L)[uU])? is not supported
    enumeration constant - An identifier declared as an enumeration constant has type int.
    TODO: L,escape sequences character constant - any char except those listed in the C89 spec 
*/

CONSTANT        [0-9]+\.?[0-9]*[e|E]?[\+|\-]?[0-9]*[f|l|F|L]?|(?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)?|[L]?'[^\n\\']'

/* StringLiteral TODO: quotation marks or no quotation marks? escape sequences, L etc.... refer to C89 spec, ' ' and " " is still invalid */
/* 1. remove "" - https://en.wikipedia.org/wiki/String_literal */
/* 2. FINAL : SourceLine reading, ignore # maybe? */
STRINGLITERAL   [L]?\"(\\.|[^\\"])*\"

/* [L]?["][^\n\\\"]*["] */


WHITESPACE      [ \t\r]+


/* preprocessing-token: */

/*

TODO AFTER the rest is done

HEADER-NAME   (?:("[^\n\\\"]*")|(<[^\n>]*>))


PRE-IDENTIFIER

PP-NUMBER

PRE-CONSTANT

PRE-STRINGLITERAL

PRE-OPERATOR

PRE-PUNCTUATOR

{HEADER-NAME}           cout << yytext << " HEADER-NAME " << "toekn type " << line_number << " " << SourceFile << " " << source_line << endl;

*/

%%


{STRINGLITERAL}         cout << yytext << " StringLiteral " << "TString" << " " << line_number << " " << SourceFile << " " << source_line << endl;

{KEYWORD}               {
                            /* string class has an in-built constructor that converts char* (yytext) -> string */
                            string someString(yytext);
                            if(someString == "auto"){
                                cout << yytext << " Keyword " << "TAuto" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "double"){
                                cout << yytext << " Keyword " << "TDouble" << " " << line_number << " " << SourceFile << " " << source_line << endl;                                
                            }
                            else if(someString == "int"){
                                cout << yytext << " Keyword " << "TInt" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "struct"){
                                cout << yytext << " Keyword " << "TStruct" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "break"){
                                cout << yytext << " Keyword " << "TBreak" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "else"){
                                cout << yytext << " Keyword " << "TElse" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "long"){
                                cout << yytext << " Keyword " << "TLong" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "switch"){
                                cout << yytext << " Keyword " << "TSwitch" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "case"){
                                cout << yytext << " Keyword " << "TCase" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "enum"){
                                cout << yytext << " Keyword " << "TEnum" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "register"){
                                cout << yytext << " Keyword " << "TRegister" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "typedef"){
                                cout << yytext << " Keyword " << "TTypedef" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "char"){
                                cout << yytext << " Keyword " << "TChar" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "extern"){
                                cout << yytext << " Keyword " << "TExtern" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "return"){
                                cout << yytext << " Keyword " << "TReturn" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "union"){
                                cout << yytext << " Keyword " << "TUnion" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "const"){
                                cout << yytext << " Keyword " << "TConst" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "float"){
                                cout << yytext << " Keyword " << "TFloat" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "short"){
                                cout << yytext << " Keyword " << "TShort" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "unsigned"){
                                cout << yytext << " Keyword " << "TUnsigned" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "continue"){
                                cout << yytext << " Keyword " << "TContinue" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "for"){
                                cout << yytext << " Keyword " << "TFor" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "signed"){
                                cout << yytext << " Keyword " << "TSigned" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "void"){
                                cout << yytext << " Keyword " << "TVoid" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "default"){
                                cout << yytext << " Keyword " << "TDefault" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "goto"){
                                cout << yytext << " Keyword " << "TGoto" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "sizeof"){
                                cout << yytext << " Keyword " << "TSizeof" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "volatile"){
                                cout << yytext << " Keyword " << "TVolatile" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "do"){
                                cout << yytext << " Keyword " << "TDo" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "if"){
                                cout << yytext << " Keyword " << "TIf" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "static"){
                                cout << yytext << " Keyword " << "TStatic" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(someString == "while"){
                                cout << yytext << " Keyword " << "TWhile" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else{
                                cout << yytext << " Keyword " << "TokenType" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }   
                        }
{IDENTIFIER}            cout << yytext << " Identifier " << "TIdentifier " << line_number << " " << SourceFile << " " << source_line << endl;

{OPERATOR}              {
                            string opString(yytext);
                            if(opString == "("){
                                cout << yytext << " Operator " << "T(" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ")"){
                               cout << yytext << " Operator " << "T)" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "["){
                                cout << yytext << " Operator " << "T[" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "]"){
                                cout << yytext << " Operator " << "T]" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "."){
                                cout << yytext << " Operator " << "TDot" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "->"){
                                cout << yytext << " Operator " << "T->" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "++"){
                                cout << yytext << " Operator " << "T++" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "--"){
                                cout << yytext << " Operator " << "T--" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "&"){
                                cout << yytext << " Operator " << "T&" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "*"){
                                cout << yytext << " Operator " << "T*" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "+"){
                                cout << yytext << " Operator " << "T+" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "-"){
                                cout << yytext << " Operator " << "T-" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "~"){
                                cout << yytext << " Operator " << "T~" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "!"){
                                cout << yytext << " Operator " << "T!" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "sizeof"){
                                cout << yytext << " Operator " << "TOpsizeof" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "/"){
                                cout << yytext << " Operator " << "T/" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "%"){
                                cout << yytext << " Operator " << "T%" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<<"){
                                cout << yytext << " Operator " << "T<<" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">>"){
                                cout << yytext << " Operator " << "T>>" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<"){
                                cout << yytext << " Operator " << "T<" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">"){
                                cout << yytext << " Operator " << "T>" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<="){
                                cout << yytext << " Operator " << "T<=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">="){
                                cout << yytext << " Operator " << "T>=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "=="){
                                cout << yytext << " Operator " << "T==" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "!="){
                                cout << yytext << " Operator " << "T!=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "^"){
                                cout << yytext << " Operator " << "T^" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "|"){
                                cout << yytext << " Operator " << "T|" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "&&"){
                                cout << yytext << " Operator " << "T&&" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "||"){
                                cout << yytext << " Operator " << "T||" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "?"){
                                cout << yytext << " Operator " << "T?" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ":"){
                                cout << yytext << " Operator " << "T:" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "="){
                                cout << yytext << " Operator " << "T=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "*="){
                                cout << yytext << " Operator " << "T*=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "/="){
                                cout << yytext << " Operator " << "T/=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "%="){
                                cout << yytext << " Operator " << "T%=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "+="){
                                cout << yytext << " Operator " << "T+=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "-="){
                                cout << yytext << " Operator " << "T-=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<<="){
                                cout << yytext << " Operator " << "T<<=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">>="){
                                cout << yytext << " Operator " << "T>>=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "&="){
                                cout << yytext << " Operator " << "T&=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "^="){
                                cout << yytext << " Operator " << "T^=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "|="){
                                cout << yytext << " Operator " << "T|=" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ","){
                                cout << yytext << " Operator " << "T," << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "#"){
                                cout << yytext << " Operator " << "T#" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }  
                            else if(opString == "##"){
                                cout << yytext << " Operator " << "T##" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                            else{
                                cout << yytext << " Operator " << "TokenType" << " " << line_number << " " << SourceFile << " " << source_line << endl;                               
                            }
                        }

{CONSTANT}              cout << yytext << " Constant " << "TConstant" << " " << line_number << " " << SourceFile << " " << source_line << endl;


{WHITESPACE}            

.                       cout << yytext << " Invalid " << "TokenType" << " " << line_number << " " << SourceFile << " " << source_line << endl;

\n                      line_number++;

%%

int main()
{
    getline(cin,SourceFile);
    ss.str() = "";
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


