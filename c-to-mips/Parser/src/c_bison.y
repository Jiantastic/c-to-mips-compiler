%{
#include <iostream>
#include <cstdlib>

int yylex();
int yyerror(const char* s);
int counter = 0;

%}

%union 
{
        int number;
        float float_num;
        char* str;
}


%token <number> NUM

%token <float_num> FLOAT_NUMBER

%token <str> IDENTIFIER

%token  CONSTANT STRINGLITERAL SIZEOF

/* keywords */

%token AUTO DOUBLE INT STRUCT BREAK ELSE LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR EXTERN RETURN UNION CONST FLOAT SHORT UNSIGNED CONTINUE FOR SIGNED VOID DEFAULT GOTO VOLATILE DO IF STATIC WHILE

%token  LROUNDBRACKET RROUNDBRACKET EOLINE LCURLYBRACE RCURLYBRACE SEMICOLON COMMA

/* operators */

%token ELLIPSIS

%token PTR_OPERATOR INC_OPERATOR DEC_OPERATOR LEFT_OPERATOR RIGHT_OPERATOR LE_OPERATOR GE_OPERATOR EQ_OPERATOR NE_OPERATOR

%token AND_OPERATOR OR_OPERATOR MUL_ASSIGNMENT DIV_ASSIGNMENT MOD_ASSIGNMENT ADD_ASSIGNMENT

%token SUB_ASSIGNMENT LEFT_ASSIGNMENT RIGHT_ASSIGNMENT AND_ASSIGNMENT

%token XOR_ASSIGNMENT OR_ASSIGNMENT 


%%

/*
TODO:

data-type : int

control-flow : if, while, for

function - parameters

scope - 

indentations


*/

primary_expression : IDENTIFIER           { std::cout << $1 << std::endl;}
                   | CONSTANT
                   | STRINGLITERAL
                   | '(' expression ')'
                   ;

file   : line file
       | line
       ;

line   : function EOLINE 
       | function scope_start EOLINE
       | function scope_start scope_end EOLINE
       | variable EOLINE  
       | scope_start EOLINE 
       | scope_end EOLINE
       | scope_start scope_end EOLINE
       | EOLINE
       ;

variable : INT IDENTIFIER         { for(int i=counter;i!=0;i--){std::cout << "    ";} std::cout << "VARIABLE : " << $2 << std::endl;}

function : INT IDENTIFIER         { for(int i=counter;i!=0;i--){std::cout << "    ";}std::cout << "FUNCTION : " << $2 << std::endl; } params 
         ;

params : '(' ')' 
       | '(' expression ')'       { std::cout << "    PARAMETER : "; }
       ;


scope_start : '{'       { counter++; std::cout << "SCOPE" << std::endl; } ;

scope_end : '}'         { counter--;};

expression : assignment_expression
           | expression ',' assignment_expression
           ; 

assignment_expression : conditional_expression
                      | unary_expression assignment_operator assignment_expression
                      ;

conditional_expression : logical_or_expression
                       | logical_or_expression '?' expression ':' conditional_expression
                       ;

logical_or_expression : logical_and_expression
                      | logical_or_expression OR_OPERATOR logical_and_expression
                      ;

logical_and_expression : inclusive_or_expression
                       | logical_and_expression AND_OPERATOR inclusive_or_expression
                       ;

inclusive_or_expression : exclusive_or_expression
                        | inclusive_or_expression '|' exclusive_or_expression
                        ;

exclusive_or_expression : and_expression
                        | exclusive_or_expression '^' and_expression
                        ;

and_expression : equality_expression
               | and_expression '&' equality_expression
               ;

equality_expression : relational_expression
                    | equality_expression EQ_OPERATOR relational_expression
                    | equality_expression NE_OPERATOR relational_expression
                    ;

relational_expression : shift_expression
                      | relational_expression '<' shift_expression
                      | relational_expression '>' shift_expression
                      | relational_expression LE_OPERATOR shift_expression
                      | relational_expression GE_OPERATOR shift_expression
                      ;

shift_expression : additive_expression
                 | shift_expression LEFT_OPERATOR additive_expression
                 | shift_expression RIGHT_OPERATOR additive_expression
                 ;

additive_expression : multiplicative_expression
                    | additive_expression '+' multiplicative_expression
                    | additive_expression '-' multiplicative_expression
                    ;

multiplicative_expression : cast_expression
                          | multiplicative_expression '*' cast_expression
                          | multiplicative_expression '/' cast_expression
                          | multiplicative_expression '%' cast_expression
                          ;

/* incomplete - INT only */

cast_expression : unary_expression
                | '(' type_name ')' cast_expression
                ;

assignment_operator : '='
                    | MUL_ASSIGNMENT
                    | DIV_ASSIGNMENT
                    | MOD_ASSIGNMENT
                    | ADD_ASSIGNMENT
                    | SUB_ASSIGNMENT
                    | LEFT_ASSIGNMENT
                    | RIGHT_ASSIGNMENT
                    | AND_ASSIGNMENT
                    | XOR_ASSIGNMENT
                    | OR_ASSIGNMENT
                    ;


/* incomplete - INT only */

unary_expression : postfix_expression
                 | INC_OPERATOR unary_expression
                 | DEC_OPERATOR unary_expression
                 | unary_operator cast_expression
                 | SIZEOF unary_expression
                 | SIZEOF '(' type_name ')'
                 ;

postfix_expression : primary_expression
                   | postfix_expression '[' expression ']'
                   | postfix_expression '(' ')'
                   | postfix_expression '(' argument_expression_list ')'
                   | postfix_expression '.' IDENTIFIER
                   | postfix_expression PTR_OPERATOR IDENTIFIER
                   | postfix_expression INC_OPERATOR
                   | postfix_expression DEC_OPERATOR
                   ;

argument_expression_list : assignment_expression
                         | argument_expression_list ',' assignment_expression
                         ;

unary_operator : '&'
               | '*'
               | '+'
               | '-'
               | '~'
               | '!'
               ;

type_name : INT

control_flow : IF '(' expression ')' statement
             | IF '(' expression ')' statement ELSE statement
             | WHILE '(' expression ')' statement
             | FOR '(' expression_statement expression_statement ')' statement
             | FOR '(' expression_statement expression_statement expression ')' statement
             ; 

statement : labeled_statement
          | compound_statement
          | expression_statement
          | selection_statement
          | iteration_statement
          | jump_statement
          ;

expression_statement : ';'
                     | expression ';'
                     ;




/*

etc...................

values : INT IDENTIFIER                { std::cout << "    PARAMETER : " << $2 << std::endl; }
       | values COMMA INT IDENTIFIER   { std::cout << "    PARAMETER : " << $4 << std::endl; }
       ;


==================================== OLD

{
  function(int a,int b,int c){}
}


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
