%{
#include <iostream>
#include <cstdlib>

int yylex();
int yyerror(const char* s);

%}

%union 
{
        int number;
        float float_num;
        char* str;
}

%token <number> INT_NUM

%token <float_num> FLOAT_NUM

%token <str> IDENTIFIER

%token CHAR_CONST STRINGLITERAL SIZEOF

/* keywords */

%token AUTO DOUBLE INT STRUCT BREAK ELSE LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR EXTERN RETURN UNION CONST FLOAT SHORT UNSIGNED CONTINUE FOR SIGNED VOID DEFAULT GOTO VOLATILE DO IF STATIC WHILE


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

/* ===================== Parsing START ============================ */

file   : translation_unit

translation_unit
  : external_declaration
  | translation_unit external_declaration
  ;

external_declaration
  : function_definition
  | declaration
  ;


/* ===================== Parsing END ============================ */

/* NOTE : all implementations below are partial, REMEMBER to check against spec */


primary_expression : IDENTIFIER           { std::cout << "ASSIGNMENSST" << $1 << std::endl ;}
                   | CONSTANT             
                   | STRINGLITERAL        
                   | '(' expression ')'
                   ;

CONSTANT : INT_NUM                        
         | FLOAT_NUM                     
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



constant_expression
  : conditional_expression
  ;


/* ============== Expression Implementation ====================== */


expression : assignment_expression
           | expression ',' assignment_expression
           ; 

/* ================ assignment expression =================== */

assignment_expression : conditional_expression
                      | unary_expression assignment_operator assignment_expression
                      ;

/* ===================================== */


conditional_expression : logical_or_expression
                       | logical_or_expression '?' expression ':' conditional_expression
                       ;

unary_expression : postfix_expression
                 | INC_OPERATOR unary_expression
                 | DEC_OPERATOR unary_expression
                 | unary_operator cast_expression
                 | SIZEOF unary_expression
                 | SIZEOF '(' type_name ')'
                 ;


/* ================ assignment expression recurse tree units =================== */

logical_or_expression : logical_and_expression
                      | logical_or_expression OR_OPERATOR logical_and_expression
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

unary_operator : '&'
               | '*'
               | '+'
               | '-'
               | '~'
               | '!'
               ;

cast_expression : unary_expression
                | '(' type_name ')' cast_expression
                ;


/* ===================================== */


logical_and_expression : inclusive_or_expression
                       | logical_and_expression AND_OPERATOR inclusive_or_expression
                       ;

argument_expression_list : assignment_expression
                         | argument_expression_list ',' assignment_expression
                         ;



/* ===================================== */


inclusive_or_expression : exclusive_or_expression
                        | inclusive_or_expression '|' exclusive_or_expression
                        ;

/* ===================================== */

exclusive_or_expression : and_expression
                        | exclusive_or_expression '^' and_expression
                        ;

/* ===================================== */

and_expression : equality_expression
               | and_expression '&' equality_expression
               ;

/* ===================================== */

equality_expression : relational_expression
                    | equality_expression EQ_OPERATOR relational_expression
                    | equality_expression NE_OPERATOR relational_expression
                    ;

/* ===================================== */

relational_expression : shift_expression
                      | relational_expression '<' shift_expression
                      | relational_expression '>' shift_expression
                      | relational_expression LE_OPERATOR shift_expression
                      | relational_expression GE_OPERATOR shift_expression
                      ;

/* ===================================== */

shift_expression : additive_expression
                 | shift_expression LEFT_OPERATOR additive_expression
                 | shift_expression RIGHT_OPERATOR additive_expression
                 ;

/* ===================================== */

additive_expression : multiplicative_expression
                    | additive_expression '+' multiplicative_expression
                    | additive_expression '-' multiplicative_expression
                    ;

/* ===================================== */

multiplicative_expression : cast_expression
                          | multiplicative_expression '*' cast_expression
                          | multiplicative_expression '/' cast_expression
                          | multiplicative_expression '%' cast_expression
                          ;


/*
  #incomplete - type_name

    | specifier_qualifier_list abstract_declarator
*/

type_name : specifier_qualifier_list
          ;

specifier_qualifier_list
  : type_specifier specifier_qualifier_list
  | type_specifier
  | type_qualifier specifier_qualifier_list
  | type_qualifier
  ;








/* ============== Statement Implementation ========================== */

statement : labeled_statement
          | compound_statement
          | expression_statement
          | selection_statement
          | iteration_statement
          | jump_statement
          ;


/* TODO ====== Labeled Statement ======= */

labeled_statement : IDENTIFIER ':' statement
                  | CASE constant_expression ':' statement
                  | DEFAULT ':' statement
                  ;

/* TODO ====== Compound Statement ======= */

compound_statement : '{' '}'
                   | '{' statement_list '}'                 {std::cout << "compound_test1" << std::endl;}
                   | '{' declaration_list '}'                  {std::cout << "compound_test2" << std::endl;}
                   | '{' declaration_list statement_list '}'     {std::cout << "compound_test3" << std::endl;}
                   ;

/* OK ====== Expression Statement ======= */

expression_statement : ';'
                     | expression ';'
                     ;

/* OK ====== Selection Statement ======= */

selection_statement : IF '(' expression ')' statement
                    | IF '(' expression ')' statement ELSE statement
                    | SWITCH '(' expression ')' statement
                    ;

/* OK ====== Iteration Statement ======= */

iteration_statement : WHILE '(' expression ')' statement {std::cout<<"test"<<std::endl;}
                    | DO statement WHILE '(' expression ')' ';'
                    | FOR '(' expression_statement expression_statement ')' statement
                    | FOR '(' expression_statement expression_statement expression ')' statement
                    ;

/* OK ====== Jump Statement ======= */

jump_statement : GOTO IDENTIFIER ';'
               | CONTINUE ';'
               | BREAK ';'
               | RETURN ';'
               | RETURN expression ';'
               | RETURN {std::cout << "ewasadasdasd" << std::endl;}
               | ')' {std::cout << "ewasadasdasd" << std::endl;}
               ;

/* ============================ Statement recursion tree units ============================= */

statement_list : statement                   {std::cout << "doI?" << std::endl;}
               | statement_list statement     {std::cout << "doI?" << std::endl;}
               ;

declaration_list : declaration
                 | declaration_list declaration
                 ;


/* ================ Declaration ========================= */


declaration : declaration_specifiers ';'
            | declaration_specifiers init_declarator_list ';'
            ;

/* ================ declaration_specifiers ================ */

declaration_specifiers
  : storage_class_specifier
  | storage_class_specifier declaration_specifiers
  | type_specifier
  | type_specifier declaration_specifiers
  | type_qualifier
  | type_qualifier declaration_specifiers
  ;

storage_class_specifier
  : TYPEDEF
  | EXTERN
  | STATIC
  | AUTO
  | REGISTER
  ;

/* 

  #incomplete - type_specifier

  | struct_or_union_specifier
  | enum_specifier
  | TYPE_NAME - not a token

*/

type_specifier
  : VOID
  | CHAR
  | SHORT
  | INT                   
  | LONG
  | FLOAT
  | DOUBLE
  | SIGNED
  | UNSIGNED
  ;

type_qualifier
  : CONST
  | VOLATILE
  ;

/* ============= init_declarator_list ============= */

init_declarator_list
  : init_declarator
  | init_declarator_list ',' init_declarator
  ;

init_declarator
  : declarator
  | declarator '=' initializer
  ;


/* ============== declarator ============ */

declarator
  : pointer direct_declarator
  | direct_declarator
  ;

pointer : '*'
        | '*' type_qualifier_list
        | '*' pointer
        | '*' type_qualifier_list pointer
        ;

type_qualifier_list
  : type_qualifier
  | type_qualifier_list type_qualifier
  ;

direct_declarator : IDENTIFIER                                                      { 
                                                                                        std::cout << "VARIABLEZZZ : " << $1 << std:: endl;
                                                                                    }
                  | '(' declarator ')'
                  | direct_declarator '[' constant_expression ']'
                  | direct_declarator '[' ']'
                  | direct_declarator '(' parameter_type_list ')'
                  | direct_declarator '(' identifier_list ')'
                  | direct_declarator '(' ')'
                  ;


parameter_type_list : parameter_list
                    | parameter_list ',' ELLIPSIS
                    ;

parameter_list : parameter_declaration
               | parameter_list ',' parameter_declaration
               ;

/*   

  #incomplete - parameter_declaration

      | declaration_specifiers abstract_declarator 

*/

parameter_declaration : declaration_specifiers declarator
                      | declaration_specifiers
                      ;

identifier_list
  : IDENTIFIER                                                                        { std::cout << "VARIABLE2 : " << $1 << std::endl;}
  | identifier_list ',' IDENTIFIER                                                    { std::cout << "VARIABLE3 : " << $3 << std::endl;}
  ;


/* ========= initializer ======== */

initializer : assignment_expression
            | '{' initializer_list '}'
            | '{' initializer_list ',' '}'
            ;

initializer_list : initializer
                 | initializer_list ',' initializer
                 ;




/* ================== function definitions ====================== */

function_definition : declaration_specifiers declarator declaration_list compound_statement   { std::cout << "FUNCTION : " << std::endl;}
                    | declaration_specifiers declarator compound_statement                    { std::cout << "FUNCTION : " << std::endl;}
                    | declarator declaration_list compound_statement                          { std::cout << "function3 end" << std::endl;}
                    | declarator compound_statement                                         { std::cout << "function4 end" << std::endl;}
                    ;




%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
