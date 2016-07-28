%option noyywrap
%{
#include "c_bison.tab.h"
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

KEYWORD     (auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|volatile|do|if|static|while)

IDENTIFIER  [A-Za-z_][A-Za-z0-9_]*  

OPERATOR    \.\.\.|\[|\]|##|\|=|\^=|&=|->|>>=|<<=|\-=|\+=|%=|\/=|\*=|\|\||&&|\^|!=|==|>=|<=|>>|<<|\+\+|\-\-|[\.\&\+\-\*~!%\\(\)\/<>\|\=\,\;\#\?\:\{\}]|sizeof

EXPONENT    [e|E][\+|\-]?[0-9]+

FRACTIONAL_CONSTANT ([0-9]*\.[0-9]+)|([0-9]+\.)

FLOATING_SUFFIX [f|l|F|L]

FLOATING_CONSTANT   {FRACTIONAL_CONSTANT}{EXPONENT}?{FLOATING_SUFFIX}?|[\+\-]?[0-9]+{EXPONENT}{FLOATING_SUFFIX}?

INTEGER_CONSTANT    (?:[1-9][0-9]*|0[0-7]*)(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)?

HEXADECIMAL_CONSTANT 0[xX][A-Fa-f0-9]+(?:ul|uL|Ul|UL|lu|lU|Lu|LU|u|U|l|L)?

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
                                return AUTO;
                            }
                            else if(someString == "double"){
                                return DOUBLE;
                            }
                            else if(someString == "int"){
                                return INT;
                            }
                            else if(someString == "struct"){
                                return STRUCT;
                            }
                            else if(someString == "break"){
                                return BREAK;
                            }
                            else if(someString == "else"){
                                return ELSE;
                            }
                            else if(someString == "long"){
                                return LONG;
                            }
                            else if(someString == "switch"){
                                return SWITCH;
                            }
                            else if(someString == "case"){
                                return CASE;
                            }
                            else if(someString == "enum"){
                                return ENUM;
                            }
                            else if(someString == "register"){
                                return REGISTER;
                            }
                            else if(someString == "typedef"){
                                return TYPEDEF;
                            }
                            else if(someString == "char"){
                                return CHAR;
                            }
                            else if(someString == "extern"){
                                return EXTERN;
                            }
                            else if(someString == "return"){
                                return RETURN;
                            }
                            else if(someString == "union"){
                                return UNION;
                            }
                            else if(someString == "const"){
                                return CONST;
                            }
                            else if(someString == "float"){
                                return FLOAT;
                            }
                            else if(someString == "short"){
                                return SHORT;
                            }
                            else if(someString == "unsigned"){
                                return UNSIGNED;
                            }
                            else if(someString == "continue"){
                                return CONTINUE;
                            }
                            else if(someString == "for"){
                                return FOR;
                            }
                            else if(someString == "signed"){
                                return SIGNED;
                            }
                            else if(someString == "void"){
                                return VOID;
                            }
                            else if(someString == "default"){
                                return DEFAULT;
                            }
                            else if(someString == "goto"){
                                return GOTO;
                            }
                            else if(someString == "sizeof"){
                                return SIZEOF;
                            }
                            else if(someString == "volatile"){
                                return VOLATILE;
                            }
                            else if(someString == "do"){
                                return DO;
                            }
                            else if(someString == "if"){
                                return IF;
                            }
                            else if(someString == "static"){
                                return STATIC;
                            }
                            else if(someString == "while"){
                                return WHILE;
                            }

                        }
{IDENTIFIER}            {
                            yylval.str = strdup(yytext);
                            return IDENTIFIER;
                        }

{FLOATING_CONSTANT}     {
                            yylval.float_num = atof(yytext); 
                            return FLOAT_NUM;
                        }

{INTEGER_CONSTANT}      {
                            yylval.number = atoi(yytext);
                            return INT_NUM;
                        }

{HEXADECIMAL_CONSTANT}  {
                            stringstream ll;
                            ll << std::hex << yytext;
                            int x;
                            ll >> x;
                            yylval.number = x;
                            return HEX_NUM;
                        }

{CHARACTER_CONSTANT}    {
                            return CHAR_CONST;
                        }


{OPERATOR}              {
                            string opString(yytext);
                            if(opString == "("){
                                return '(';
                            }
                            else if(opString == ")"){
                               return ')';
                            }
                            else if(opString == "["){
                                return '[';
                            }
                            else if(opString == "]"){
                                return ']';
                            }
                            else if(opString == "."){
                                return '.';
                            }
                            else if(opString == "->"){
                                return PTR_OPERATOR;
                            }
                            else if(opString == "++"){
                                return INC_OPERATOR;
                            }
                            else if(opString == "--"){
                                return DEC_OPERATOR;
                            }
                            else if(opString == "&"){
                                return '&';
                            }
                            else if(opString == "*"){
                                return '*';
                            }
                            else if(opString == "+"){
                                return '+';
                            }
                            else if(opString == "-"){
                                return '-';
                            }
                            else if(opString == "~"){
                                return '~';
                            }
                            else if(opString == "!"){
                                return '!';
                            }
                            else if(opString == "sizeof"){
                                return SIZEOF;
                            }
                            else if(opString == "/"){
                                return '/';
                            }
                            else if(opString == "%"){
                                return '%';
                            }
                            else if(opString == "<<"){
                                return LEFT_OPERATOR;
                            }
                            else if(opString == ">>"){
                                return RIGHT_OPERATOR;
                            }
                            else if(opString == "<"){
                                return '<';
                            }
                            else if(opString == ">"){
                                return '>';
                            }
                            else if(opString == "<="){
                                return LE_OPERATOR;
                            }
                            else if(opString == ">="){
                                return GE_OPERATOR;
                            }
                            else if(opString == "=="){
                                return EQ_OPERATOR;
                            }
                            else if(opString == "!="){
                                return NE_OPERATOR;
                            }
                            else if(opString == "^"){
                                return '^';
                            }
                            else if(opString == "|"){
                                return '|';
                            }
                            else if(opString == "&&"){
                                return AND_OPERATOR;
                            }
                            else if(opString == "||"){
                                return OR_OPERATOR;
                            }
                            else if(opString == "?"){
                                return '?';
                            }
                            else if(opString == ":"){
                                return ':';
                            }
                            else if(opString == "="){
                                return '=';
                            }
                            else if(opString == "*="){
                                return MUL_ASSIGNMENT;
                            }
                            else if(opString == "/="){
                                return DIV_ASSIGNMENT;
                            }
                            else if(opString == "%="){
                                return MOD_ASSIGNMENT;
                            }
                            else if(opString == "+="){
                                return ADD_ASSIGNMENT;
                            }
                            else if(opString == "-="){
                                return SUB_ASSIGNMENT;
                            }
                            else if(opString == "<<="){
                                return LEFT_ASSIGNMENT;
                            }
                            else if(opString == ">>="){
                                return RIGHT_ASSIGNMENT;
                            }
                            else if(opString == "&="){
                                return AND_ASSIGNMENT;
                            }
                            else if(opString == "^="){
                                return XOR_ASSIGNMENT;
                            }
                            else if(opString == "|="){
                                return OR_ASSIGNMENT;
                            }
                            else if(opString == ","){
                                return ',';
                            }
                            else if(opString == ";"){
                                return ';';
                            }
                            else if(opString == "..."){
                                return ELLIPSIS;
                            }
                            else if(opString == "{"){
                                return '{';
                            }
                            else if(opString == "}"){
                                return '}';
                            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

                        }

{STRINGLITERAL}         {
                            string strString(yytext);
                            string ans;
                            /* StringLiteral without " " */
                            for(int i=1;i<strString.length()-1;++i){
                                ans += strString[i]; 
                            }
                            return STRINGLITERAL;
                        }


{WHITESPACE}            

.                       cout << yytext << " Invalid " << "TokenType" << " " << yytext << " " << SourceFile << " " << source_line << endl;

\n                      {
                            line_number++;

                        }

%%
