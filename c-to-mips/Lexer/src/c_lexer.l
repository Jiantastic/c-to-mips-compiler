%option noyywrap
%{
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int line_number = 1;
bool filename_init = false;
string SourceFile = "";
string input = "";
string source_line = "";
stringstream ss;

%}

/* tokens: TODO - refactor to modular regex*/

KEYWORD     (auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|volatile|do|if|static|while)

IDENTIFIER  [A-Za-z_][A-Za-z0-9_]*  

OPERATOR    \.\.\.|\[|\]|##|\|=|\^=|&=|->|>>=|<<=|\-=|\+=|%=|\/=|\*=|\|\||&&|\^|!=|==|>=|<=|>>|<<|\+\+|\-\-|[\.&+\-\*~!%\\(\)\/<>\|=,;#?:{}]|sizeof

EXPONENT    [e|E][\+|\-]?[0-9]+

FRACTIONAL_CONSTANT ([0-9]*\.[0-9]+)|([0-9]+\.)

FLOATING_SUFFIX [f|l|F|L]

FLOATING_CONSTANT   [\+\-]?{FRACTIONAL_CONSTANT}{EXPONENT}?{FLOATING_SUFFIX}?|[\+\-]?[0-9]+{EXPONENT}{FLOATING_SUFFIX}?

INTEGER_CONSTANT    (?:[\+|\-]?0[xX][A-Fa-f0-9]+|[\+|\-]?[1-9][0-9]*|[\+|\-]?0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)?

CHARACTER_CONSTANT  [L]?\'(?:\\([abfnrtv\'\"\?\\]|[0-7]{1,3}|x[0-9A-Fa-f]+)|[^\\'])+\'

STRINGLITERAL   [L]?\"(?:\\([abfnrtv\'\"\?\\]|[0-7]{1,3}|x[0-9A-Fa-f]+)|[^\\"])*\"

WHITESPACE      [ \t\r]+

FILE_LINE_FINDER ^#.*$

%%

{FILE_LINE_FINDER}      {
                            /*
                             string manipulation on # 1 "/usr/include/stdio.h" 1 3 4
                             source_line is the 2nd argument - find first number
                             SourceFile is the 3rd argument - find first "

                            */
                            string someString(yytext);  
                            string word;
                            istringstream iss(someString);
                            int count = 1;
                            while(iss >> word ){
                                if(count == 2){
                                    source_line = word;
                                }
                                else if(count == 3){
                                    SourceFile = word;
                                }
                                count++;
                            }
                        }

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


{FLOATING_CONSTANT}     {
                            cout << yytext << " Constant " << "TFloatingConstant" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                        }

{INTEGER_CONSTANT}      {
                            cout << yytext << " Constant " << "TIntegerConstant" << " " << line_number << " " << SourceFile << " " << source_line << endl;                          
                        }

{CHARACTER_CONSTANT}    {
                            cout << yytext << " Constant " << "TCharacterConstant" << " " << line_number << " " << SourceFile << " " << source_line << endl;                           
                        }


{OPERATOR}              {
                            string opString(yytext);
                            if(opString == "("){
                                cout << yytext << " Operator " << "TLeftRoundBracket" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ")"){
                               cout << yytext << " Operator " << "TRightRoundBracket" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "["){
                                cout << yytext << " Operator " << "TLeftSquareBracket" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "]"){
                                cout << yytext << " Operator " << "TRightSquareBracket" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "."){
                                cout << yytext << " Operator " << "TDot" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "->"){
                                cout << yytext << " Operator " << "TArrow" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "++"){
                                cout << yytext << " Operator " << "TPlusPlus" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "--"){
                                cout << yytext << " Operator " << "TMinusMinus" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "&"){
                                cout << yytext << " Operator " << "TBitwiseAND" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "*"){
                                cout << yytext << " Operator " << "TStar" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "+"){
                                cout << yytext << " Operator " << "TPlus" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "-"){
                                cout << yytext << " Operator " << "TMinus" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "~"){
                                cout << yytext << " Operator " << "TTilde" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "!"){
                                cout << yytext << " Operator " << "TExclaimationMark" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "sizeof"){
                                cout << yytext << " Operator " << "TOpsizeof" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "/"){
                                cout << yytext << " Operator " << "TForwardSlash" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "%"){
                                cout << yytext << " Operator " << "TPercentage" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<<"){
                                cout << yytext << " Operator " << "TShiftLeft" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">>"){
                                cout << yytext << " Operator " << "TShiftRight" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<"){
                                cout << yytext << " Operator " << "TLeftArrow" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">"){
                                cout << yytext << " Operator " << "TRightArrow" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<="){
                                cout << yytext << " Operator " << "TLeftArrowEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">="){
                                cout << yytext << " Operator " << "TRightArrowEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "=="){
                                cout << yytext << " Operator " << "TEqualEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "!="){
                                cout << yytext << " Operator " << "TExclaimationMarkEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "^"){
                                cout << yytext << " Operator " << "TCaret" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "|"){
                                cout << yytext << " Operator " << "TBitwiseOR" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "&&"){
                                cout << yytext << " Operator " << "TAND" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "||"){
                                cout << yytext << " Operator " << "TOR" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "?"){
                                cout << yytext << " Operator " << "TQuestionMark" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ":"){
                                cout << yytext << " Operator " << "TColon" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "="){
                                cout << yytext << " Operator " << "TEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "*="){
                                cout << yytext << " Operator " << "TStarEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "/="){
                                cout << yytext << " Operator " << "TForwardSlashEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "%="){
                                cout << yytext << " Operator " << "TPercentageEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "+="){
                                cout << yytext << " Operator " << "TPlusEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "-="){
                                cout << yytext << " Operator " << "TMinusEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "<<="){
                                cout << yytext << " Operator " << "TLeftShiftEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ">>="){
                                cout << yytext << " Operator " << "TRightShiftEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "&="){
                                cout << yytext << " Operator " << "TBitwiseANDEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "^="){
                                cout << yytext << " Operator " << "TCaretEqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "|="){
                                cout << yytext << " Operator " << "TBitwiseOREqual" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == ","){
                                cout << yytext << " Operator " << "TComma" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }
                            else if(opString == "#"){
                                cout << yytext << " Operator " << "THashtag" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }  
                            else if(opString == "##"){
                                cout << yytext << " Operator " << "THashTagHashTag" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                            else{
                                cout << yytext << " Operator " << "TokenType" << " " << line_number << " " << SourceFile << " " << source_line << endl;                               
                            }
                        }

{STRINGLITERAL}         {
                            string strString(yytext);
                            string ans;
                            /* StringLiteral without " " */
                            for(int i=1;i<strString.length()-1;++i){
                                ans += strString[i]; 
                            }
                            cout << ans << " StringLiteral " << "TString" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                        }


{WHITESPACE}            

.                       cout << yytext << " Invalid " << "TokenType" << " " << line_number << " " << SourceFile << " " << source_line << endl;

\n                      line_number++;

%%

int main()
{
    yylex();
    return 0;
}
