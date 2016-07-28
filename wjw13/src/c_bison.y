%{
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include "ast.h"
#include "ast.cpp"

int yylex();
int yyerror(const char* s);

char* identifier_value;
int scope_counter = 0;
int is_function = 0;
mips_stack mips32;
std::vector<Expression*> completeTree;
bool debugMode = false;
bool isMinus = false;
std::string functionName;
int paramCount = 0;

%}

%union 
{
        int number;
        float float_num;
        char* str;
        class Expression* exp;
        class AssignmentOperator* assign_op;
}

%token <number> INT_NUM HEX_NUM

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

%type <str> declarator '(' ')'

%type <str> '='
MUL_ASSIGNMENT
DIV_ASSIGNMENT
MOD_ASSIGNMENT
ADD_ASSIGNMENT
SUB_ASSIGNMENT
LEFT_ASSIGNMENT 
RIGHT_ASSIGNMENT
AND_ASSIGNMENT  
XOR_ASSIGNMENT  
OR_ASSIGNMENT 


%type <exp> additive_expression multiplicative_expression cast_expression unary_expression postfix_expression primary_expression expression
assignment_expression
conditional_expression
logical_or_expression
logical_and_expression
inclusive_or_expression
exclusive_or_expression
and_expression
equality_expression
relational_expression
shift_expression
initializer

%type <assign_op> assignment_operator

%%

/* ===================== Parsing START ============================ */

translation_unit : external_declaration
                 | translation_unit external_declaration
                 ;

external_declaration : declaration             
                     | function_definition     
                     ;

/* ===================== Parsing END ============================ */

/* NOTE : all implementations below are partial, REMEMBER to check against spec */


primary_expression : IDENTIFIER     {
                                      $$ = new IdentifierExpression($1,isMinus);
                                      isMinus = false;
                                      completeTree.push_back($$);
                                    }      
                   | INT_NUM        { 
                                      if(isMinus){
                                        $$ = new ConstantExpression(-$1);
                                        isMinus = false;
                                      }
                                      else{
                                        $$ = new ConstantExpression($1);
                                      }
                                      completeTree.push_back($$);
                                    }     
                   | HEX_NUM        {
                                      if(isMinus){
                                        $$ = new ConstantExpression(-$1);
                                        isMinus = false;
                                      }
                                      else{
                                        $$ = new ConstantExpression($1);
                                      }
                                      completeTree.push_back($$);
                                    }  
                   | STRINGLITERAL        
                   | '(' expression ')' /* BRACKET EXPRESSION TODO */
                   ;

/*
CONSTANT : INT_NUM                        
         | FLOAT_NUM                     
         ;
*/

assignment_operator : '='                         {$$ = new AssignmentOperator("=");}
                    | MUL_ASSIGNMENT              {$$ = new AssignmentOperator("*=");}              
                    | DIV_ASSIGNMENT              {$$ = new AssignmentOperator("/=");}
                    | MOD_ASSIGNMENT              {$$ = new AssignmentOperator("%=");}
                    | ADD_ASSIGNMENT              {$$ = new AssignmentOperator("+=");}
                    | SUB_ASSIGNMENT              {$$ = new AssignmentOperator("-=");}
                    | LEFT_ASSIGNMENT             {$$ = new AssignmentOperator("<<=");}
                    | RIGHT_ASSIGNMENT            {$$ = new AssignmentOperator(">>=");}
                    | AND_ASSIGNMENT              {$$ = new AssignmentOperator("&=");}
                    | XOR_ASSIGNMENT              {$$ = new AssignmentOperator("^=");}
                    | OR_ASSIGNMENT               {$$ = new AssignmentOperator("|=");}
                    ;

constant_expression : conditional_expression
                    ;

/* ============== Expression Implementation ====================== */


expression : assignment_expression                        { $$ = new UnaryExpression($1,"assignment_expression"); }
           | expression ',' assignment_expression         { $$ = new BinaryExpression($1,",",$3);}
           ; 

/* ================ assignment expression =================== */

assignment_expression : conditional_expression            { $$ = new UnaryExpression($1,"conditional_expression"); completeTree.push_back($$);}
                      | unary_expression assignment_operator assignment_expression       { 
                                                                                            bool negative_identifier = false;
                                                                                            std::string iden="";
                                                                                            int single_case = 0;
                                                                                            for(int i=0;i<completeTree.size();i++){
                                                                                              if(completeTree[i]->getType() == "Constant"){
                                                                                                single_case++;
                                                                                              }
                                                                                              else if(completeTree[i]->getType() == "Identifier"){
                                                                                                iden = completeTree[i]->getName();
                                                                                                single_case++;
                                                                                              }
                                                                                            }
                                                                                            std::stack<Expression*> mystack;

                                                                                            /* handle single declaration, int x = 3, int x = a - ShuntingYard only works on Binary */

                                                                                            if(single_case == 2){
                                                                                              mips32.noDeclare_singleHandler(completeTree,iden,$2->getType());
                                                                                            }
                                                                                            else{
                                                                                              mips32.ShuntingYardAlgo(completeTree,mystack,debugMode,iden,$2->getType());
                                                                                            }
                                                                                            completeTree.clear();
                                                                                         }

                      ;

/* ===================================== */


conditional_expression : logical_or_expression             { $$ = new UnaryExpression($1,"logical_or_expression");completeTree.push_back($$);}
                       | logical_or_expression '?' expression ':' conditional_expression
                       ;

unary_expression : postfix_expression                      { $$ = new UnaryExpression($1,"postfix_expression");completeTree.push_back($$);}
                 | INC_OPERATOR unary_expression
                 | DEC_OPERATOR unary_expression
                 | unary_operator cast_expression           
                 | SIZEOF unary_expression
                 | SIZEOF '(' type_name ')'
                 ;


/* ================ assignment expression recurse tree units =================== */

logical_or_expression : logical_and_expression                                    { $$ = new UnaryExpression($1,"logical_and_expression");completeTree.push_back($$);}
                      | logical_or_expression OR_OPERATOR logical_and_expression   { $$ = new BinaryExpression($1,"||",$3);completeTree.push_back($$);}
                      ;


postfix_expression : primary_expression                                           { $$ = new UnaryExpression($1,"primary_expression");completeTree.push_back($$);}
                   | postfix_expression '[' expression ']'
                   | postfix_expression '(' ')'                                   { 
                                                                                    $$ = new PostfixExpression($1); $$->codeGen($1,mips32);
                                                                                    completeTree.push_back($$);
                                                                                  }
                   | postfix_expression '(' argument_expression_list ')'           
                   | postfix_expression '.' IDENTIFIER
                   | postfix_expression PTR_OPERATOR IDENTIFIER
                   | postfix_expression INC_OPERATOR                              {  }
                   | postfix_expression DEC_OPERATOR
                   ;

unary_operator : '&'    
               | '*'
               | '+'
               | '-'                                                    { isMinus = true;}
               | '~'
               | '!'
               ;

cast_expression : unary_expression                                      { $$ = new UnaryExpression($1,"unary_expression");completeTree.push_back($$);}
                | '(' type_name ')' cast_expression                     
                ;

/* ===================================== */

logical_and_expression : inclusive_or_expression                         { $$ = new UnaryExpression($1,"inclusive_or_expression");completeTree.push_back($$);}
                       | logical_and_expression AND_OPERATOR inclusive_or_expression  { $$ = new BinaryExpression($1,"&&",$3);completeTree.push_back($$);}
                       ;

argument_expression_list : assignment_expression
                         | argument_expression_list ',' assignment_expression
                         ;

/* ===================================== */

inclusive_or_expression : exclusive_or_expression                         { $$ = new UnaryExpression($1,"exclusive_or_expression");completeTree.push_back($$);}
                        | inclusive_or_expression '|' exclusive_or_expression  { $$ = new BinaryExpression($1,"|",$3);completeTree.push_back($$);}
                        ;

/* ===================================== */

exclusive_or_expression : and_expression                                  { $$ = new UnaryExpression($1,"and_expression");completeTree.push_back($$);}
                        | exclusive_or_expression '^' and_expression      { $$ = new BinaryExpression($1,"^",$3);completeTree.push_back($$);}
                        ;

/* ===================================== */

and_expression : equality_expression                                      { $$ = new UnaryExpression($1,"equality_expression");completeTree.push_back($$);}
               | and_expression '&' equality_expression                   { $$ = new BinaryExpression($1,"&",$3);completeTree.push_back($$);}
               ;

/* ===================================== */

equality_expression : relational_expression                                   { $$ = new UnaryExpression($1,"relational_expression");completeTree.push_back($$);}
                    | equality_expression EQ_OPERATOR relational_expression   { $$ = new BinaryExpression($1,"==",$3);completeTree.push_back($$);}
                    | equality_expression NE_OPERATOR relational_expression   { $$ = new BinaryExpression($1,"!=",$3);completeTree.push_back($$);}
                    ;

/* ===================================== */

relational_expression : shift_expression                                   { $$ = new UnaryExpression($1,"shift_expression");completeTree.push_back($$);}
                      | relational_expression '<' shift_expression         { $$ = new BinaryExpression($1,"<",$3);completeTree.push_back($$);}
                      | relational_expression '>' shift_expression         { $$ = new BinaryExpression($1,">",$3);completeTree.push_back($$);}
                      | relational_expression LE_OPERATOR shift_expression { $$ = new BinaryExpression($1,"<=",$3);completeTree.push_back($$);}
                      | relational_expression GE_OPERATOR shift_expression { $$ = new BinaryExpression($1,">=",$3);completeTree.push_back($$);}
                      ;

/* ===================================== */

shift_expression : additive_expression                                   { $$ = new UnaryExpression($1,"additive_expression");completeTree.push_back($$);}
                 | shift_expression LEFT_OPERATOR additive_expression    { $$ = new BinaryExpression($1,"<<",$3);completeTree.push_back($$);}
                 | shift_expression RIGHT_OPERATOR additive_expression   { $$ = new BinaryExpression($1,">>",$3);completeTree.push_back($$);}
                 ;

/* ===================================== */

additive_expression : multiplicative_expression                            { $$ = new UnaryExpression($1,"multiplicative_expression");completeTree.push_back($$);}
                    | additive_expression '+' multiplicative_expression    { $$ = new BinaryExpression($1,"+",$3);completeTree.push_back($$);}
                    | additive_expression '-' multiplicative_expression    { $$ = new BinaryExpression($1,"-",$3);completeTree.push_back($$);}
                    ;

/* ===================================== */

multiplicative_expression : cast_expression                                { $$ = new UnaryExpression($1,"cast_expression");completeTree.push_back($$);}   
                          | multiplicative_expression '*' cast_expression  { $$ = new BinaryExpression($1,"*",$3);completeTree.push_back($$);}
                          | multiplicative_expression '/' cast_expression  { $$ = new BinaryExpression($1,"/",$3);completeTree.push_back($$);}
                          | multiplicative_expression '%' cast_expression  { $$ = new BinaryExpression($1,"%",$3);completeTree.push_back($$);}
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

compound_statement : start_scope end_scope
                   | start_scope statement_list end_scope                 
                   | start_scope declaration_list end_scope                  
                   | start_scope declaration_list statement_list end_scope     
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

iteration_statement : WHILE '(' expression ')' statement
                    | DO statement WHILE '(' expression ')' ';'
                    | FOR '(' expression_statement expression_statement expression ')' statement
                    | FOR '(' expression_statement expression_statement ')' statement 
                    ;

/* OK ====== Jump Statement ======= */

jump_statement : GOTO IDENTIFIER ';'
               | CONTINUE ';'
               | BREAK ';'
               | RETURN ';'                 
               | RETURN expression ';'      { mips32.returnHandler(completeTree); }
               ;

/* ============================ Statement recursion tree units ============================= */

statement_list : statement                   
               | statement_list statement     
               ;

declaration_list : declaration
                 | declaration_list declaration
                 ;


/* ================ Declaration ========================= */


declaration : declaration_specifiers ';'
            | declaration_specifiers init_declarator_list ';'      {
                                                                      if(debugMode){
                                                                        for(int i=0;i<scope_counter;i++){
                                                                          std::cout << "    " ;
                                                                        }
                                                                        std::cout << "VARIABLE : " << identifier_value << std::endl;
                                                                      }
                                                                      
                                                                   }
            ;

/* ================ declaration_specifiers ================ */

declaration_specifiers : storage_class_specifier
                       | storage_class_specifier declaration_specifiers
                       | type_specifier
                       | type_specifier declaration_specifiers
                       | type_qualifier
                       | type_qualifier declaration_specifiers
                       ;

storage_class_specifier : TYPEDEF
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

type_specifier : VOID
               | CHAR
               | SHORT
               | INT                   
               | LONG
               | FLOAT
               | DOUBLE
               | SIGNED
               | UNSIGNED
               ;

type_qualifier : CONST
               | VOLATILE
               ;

/* ============= init_declarator_list ============= */

init_declarator_list : init_declarator                                    
                     | init_declarator_list ',' init_declarator           
                     ;

init_declarator : declarator                                                            {
                                                                                          mips32.Insert($1);
                                                                                          completeTree.clear();
                                                                                        }

                | declarator '=' initializer                                            {
                                                                                          
                                                                                          int single_case = 0;
                                                                                          for(int i=0;i<completeTree.size();i++){
                                                                                            if(completeTree[i]->getType() == "Constant"){
                                                                                              single_case++;
                                                                                            }
                                                                                            else if(completeTree[i]->getType() == "Identifier"){
                                                                                              single_case++;
                                                                                            }
                                                                                          }
                                                                                          std::stack<Expression*> mystack;

                                                                                          /* handle single declaration, int x = 3, int x = a - ShuntingYard only works on Binary */
                                                                                          
                                                                                            if(single_case == 1){
                                                                                              mips32.singleHandler(completeTree,$1);
                                                                                            }
                                                                                            else{
                                                                                              mips32.ShuntingYardAlgo(completeTree,mystack,debugMode,$1);
                                                                                            }
                                                                                          completeTree.clear();
                                                                                        }
                ;


/* ============== declarator ============ */

declarator : pointer direct_declarator
           | direct_declarator
           ;

pointer : '*'
        | '*' type_qualifier_list
        | '*' pointer
        | '*' type_qualifier_list pointer
        ;

type_qualifier_list : type_qualifier
                    | type_qualifier_list type_qualifier
                    ;

direct_declarator : IDENTIFIER                                                      { 
                                                                                      identifier_value = $1;
                                                                                    }
                  | '(' declarator ')'                                              
                  | direct_declarator '[' constant_expression ']'                         
                  | direct_declarator '[' ']'                               
                  | direct_declarator function_name parameter_type_list ')'                 
                  | direct_declarator function_name identifier_list ')'             
                  | direct_declarator function_name ')'                             
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

parameter_declaration : declaration_specifiers declarator                 { 
                                                                              int num = 0;
                                                                              mips32.InsertParams($2);
                                                                              if(debugMode){
                                                                                for(int i=0;i<scope_counter;i++){
                                                                                  std::cout << "    " ;
                                                                                }
                                                                                std::cout << "    PARAMS : " << $2 << std::endl;
                                                                              }
                                                                             completeTree.clear();
                                                                          }
                      | declaration_specifiers
                      ;

identifier_list : IDENTIFIER                                                                        
                | identifier_list ',' IDENTIFIER                                                    
                ;

/* ========= initializer ======== */

initializer : assignment_expression                                 
            | start_scope initializer_list end_scope
            | start_scope initializer_list ',' end_scope
            ;

initializer_list : initializer
                 | initializer_list ',' initializer
                 ;


/* ================== function definitions ====================== */

function_definition : declaration_specifiers declarator declaration_list compound_statement   
                    | declaration_specifiers declarator compound_statement                         {mips32.getNew();}
                    | declarator declaration_list compound_statement                          
                    | declarator compound_statement                                         
                    ;


/* ====================== stdout handlers ====================== */

start_scope : '{'        {  /*
                            for(int i=0;i<scope_counter;i++){
                              std::cout << "    " ;
                            }
                            scope_counter++; std::cout << "SCOPE" << std::endl;
                            */
                         }
            ;

end_scope : '}'          {
                            scope_counter--;
                            std::cout << "      addiu $sp,$sp,1000" << std::endl;
                            std::cout << "      j     $31" << std::endl;
                            std::cout << "      nop" << std::endl;
                            std::cout << std::endl;
                            std::cout << "      .end  " << functionName << std::endl;
                          }
          ;


function_name : '('   {
                        for(int i=0;i<scope_counter;i++){
                          std::cout << "    " ;
                        }
                          std::cout << "      .text" << std::endl;
                          std::cout << "      .align 2" << std::endl;
                          std::cout << "      .globl " << identifier_value << std::endl;
                          std::cout << "      .ent    " << identifier_value << std::endl;
                          std::cout << "      .type " << identifier_value << ",@function" << std::endl;
                          std::cout << identifier_value << ":" << std::endl;
                          std::cout << "       addiu  $sp,$sp,-1000" << std::endl;
                          if(debugMode){
                            std::cout << "FUNCTION : " << identifier_value << std::endl;  
                          }
                          functionName = identifier_value;
                      }        
              ;

/* ====================== stdout handlers END ====================== */

%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  std::stringstream ss;
  ss << yyparse();
}
