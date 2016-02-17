%option noyywrap
%{
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int line_number = 1;
bool filename_init = false;
string SourceFile = "";
string input = "";
string source_line = "";
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

KEYWORD     (auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|volatile|do|if|static|while)

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

FLOATING_CONSTANT   [0-9]+\.?[0-9]*[e|E]?[\+|\-]?[0-9]*[f|l|F|L]?

INTEGER_CONSTANT    (?:0[xX][A-Fa-f0-9]+|[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)?

CHARACTER_CONSTANT  [L]?\'(?:\\([abfnrtv\'\"\?\\]|[0-7]{1,3}|x[0-9A-Fa-f]+)|[^\\'])+\'


/* StringLiteral TODO: quotation marks or no quotation marks? escape sequences, L etc.... refer to C89 spec, ' ' and " " is still invalid */

STRINGLITERAL   [L]?\"(?:\\([abfnrtv\'\"\?\\]|[0-7]{1,3}|x[0-9A-Fa-f]+)|[^\\"])*\"

WHITESPACE      [ \t\r]+


%%

{STRINGLITERAL}         {
                            string strString(yytext);
                            string ans;
                            /* StringLiteral without " " */
                            for(int i=1;i<strString.length()-1;++i){
                                ans += strString[i]; 
                            }
                            cout << ans << " StringLiteral " << "TString" << " " << line_number << " " << SourceFile << " " << source_line << endl;
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

{FLOATING_CONSTANT}     {
                            cout << yytext << " Constant " << "TFloatingConstant" << " " << line_number << " " << SourceFile << " " << source_line << endl;
                        }

{INTEGER_CONSTANT}      {
                            cout << yytext << " Constant " << "TIntegerConstant" << " " << line_number << " " << SourceFile << " " << source_line << endl;                          
                        }

{CHARACTER_CONSTANT}    {
                            cout << yytext << " Constant " << "TCharacterConstant" << " " << line_number << " " << SourceFile << " " << source_line << endl;                           
                        }

{WHITESPACE}            

.                       cout << yytext << " Invalid " << "TokenType" << " " << line_number << " " << SourceFile << " " << source_line << endl;

\n                      line_number++;

%%
/*
void getSourceFile(string &str1,bool &var1){
    bool tmp1 = false;
    ss.str() = "";
    for(int i=0;i<str1.length();++i){
        if(str1[i] == '\"'){
            tmp1 = !tmp1;
        }
        else if(tmp1){
            ss << str1[i];
        }
    }
    SourceFile = ss.str();
    ss.clear();
    var1 = true;
}
*/

int main()
{

    bool sourceline_init = false;
    bool hashtag;
    /* read input line by line */
    while(getline(cin,input)){
        hashtag = false;
        istringstream iss(input);
        string word;
        int count = 1;
        while(iss >> word){
            if(input[0] == '#' && input[1] == ' '){
                hashtag = true;
		if(count == 3){
	            SourceFile = word;
		}
                if(count == 2){
                    source_line = word;
                }
                count++;
            }
        }
        if(!hashtag){
            char *new_char = &input[0];
            yy_scan_string(new_char);
            yylex();
        }
        line_number++;
        /* TODO: Increment source_line number */
        if(source_line != ""){
            if(!sourceline_init){
                sourceline_init = true;
            }
            else{
<<<<<<< HEAD
                stringstream ss2;
                int x = 0;
                ss2 << source_line;
                ss2 >> x;
                x++;
                ss2.clear();
                ss2 << x;
                source_line = ss2.str();                
=======
		x = atoi(source_line.c_str());
                x++;
		stringstream ss2;
		ss2 << x;
                source_line = ss2.str();              
>>>>>>> dedc8c40b80af088194e65ac3b8de9031bd170ec
            }
        }
    }

    return 0;
}
