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


/* operators */

%token ELLIPSIS EOLINE

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

variable : INT IDENTIFIER ';'        { for(int i=counter;i!=0;i--){std::cout << "    ";} std::cout << "VARIABLE : " << $2 << std::endl; }
         | INT IDENTIFIER assignment_operator NUM ';' { std::cout << "Number" << std::endl;}
         | INT IDENTIFIER  FLOAT_NUMBER ';' { std::cout << "Float" << std::endl;}
         | INT IDENTIFIER '=' IDENTIFIER ';' {std::cout << "IDEN" << std::endl;}
         ; 

function : INT IDENTIFIER         { for(int i=counter;i!=0;i--){std::cout << "  ";}std::cout << "FUNCTION : " << $2 << std::endl; } '(' params ')' 
         ;

params : INT IDENTIFIER           { std::cout << "    PARAMETER : " << $2 << std::endl; }
       | params ',' INT IDENTIFIER { std::cout << "    SPARAMETER : " << $4 << std::endl; }
       ;


scope_start : '{'       { counter++; std::cout << "SCOPE" << std::endl; } ;

scope_end : '}'         { counter--;};





/* NOTE : all implementations below are partial, REMEMBER to check against spec */

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

iteration_statement
  : WHILE '(' expression ')' statement
  | FOR '(' expression_statement expression_statement ')' statement
  | FOR '(' expression_statement expression_statement expression ')' statement
  ;


selection_statement
  : IF '(' expression ')' statement
  | IF '(' expression ')' statement ELSE statement
  | SWITCH '(' expression ')' statement
  ;


/* ============== Expression Implementation ====================== */


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

cast_expression : unary_expression
                | '(' type_name ')' cast_expression
                ;

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


%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
