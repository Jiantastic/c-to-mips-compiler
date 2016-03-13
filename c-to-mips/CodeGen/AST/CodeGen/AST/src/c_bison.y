%{
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include "ast.h"
#include "ast.cpp"

int yylex();
int yyerror(const char* s);
char* identifier_value;
int scope_counter = 0;
int is_function = 0;
std::stack<Expression*> mystack;
mipsRegisters mips32;

%}

%union 
{
        int number;
        float float_num;
        char* str;
        class Expression* exp;
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

%type <str> declarator 

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
assignment_operator

%type <exp> additive_expression multiplicative_expression cast_expression unary_expression postfix_expression primary_expression
expression
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



primary_expression : IDENTIFIER     {$$ = new IdentifierExpression($1);mystack.push($$);}      
                   | INT_NUM        {$$ = new ConstantExpression($1);mystack.push($$);}             
                   | STRINGLITERAL        
                   | '(' expression ')'
                   ;

/*
CONSTANT : INT_NUM                        
         | FLOAT_NUM                     
         ;
*/

assignment_operator : '='                         {$$ = $1;}
                    | MUL_ASSIGNMENT              {$$ = $1;}              
                    | DIV_ASSIGNMENT              {$$ = $1;}
                    | MOD_ASSIGNMENT              {$$ = $1;}
                    | ADD_ASSIGNMENT              {$$ = $1;}
                    | SUB_ASSIGNMENT              {$$ = $1;}
                    | LEFT_ASSIGNMENT             {$$ = $1;}
                    | RIGHT_ASSIGNMENT            {$$ = $1;}
                    | AND_ASSIGNMENT              {$$ = $1;}
                    | XOR_ASSIGNMENT              {$$ = $1;}
                    | OR_ASSIGNMENT               {$$ = $1;}
                    ;



constant_expression : conditional_expression
                    ;


/* ============== Expression Implementation ====================== */


expression : assignment_expression                        { 
                                                            $$ = new UnaryExpression($1,"assignment_expression");

                                                          }
           | expression ',' assignment_expression         
           ; 

/* ================ assignment expression =================== */

assignment_expression : conditional_expression            { $$ = new UnaryExpression($1,"conditional_expression"); mystack.push($$);}
                      | unary_expression assignment_operator assignment_expression { std::cout << "testing" << std::endl;}
                      ;

/* ===================================== */


conditional_expression : logical_or_expression             { $$ = new UnaryExpression($1,"logical_or_expression");mystack.push($$);}
                       | logical_or_expression '?' expression ':' conditional_expression
                       ;

unary_expression : postfix_expression                      { $$ = new UnaryExpression($1,"postfix_expression");mystack.push($$);}
                 | INC_OPERATOR unary_expression
                 | DEC_OPERATOR unary_expression
                 | unary_operator cast_expression           {std::cout << "TODO - UNARY EXPRESSION " << std::endl;}
                 | SIZEOF unary_expression
                 | SIZEOF '(' type_name ')'
                 ;


/* ================ assignment expression recurse tree units =================== */

logical_or_expression : logical_and_expression                                    { $$ = new UnaryExpression($1,"logical_and_expression");mystack.push($$);}
                      | logical_or_expression OR_OPERATOR logical_and_expression
                      ;


postfix_expression : primary_expression                                           { $$ = new UnaryExpression($1,"primary_expression");mystack.push($$);}
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

cast_expression : unary_expression                                      { $$ = new UnaryExpression($1,"unary_expression");mystack.push($$);}
                | '(' type_name ')' cast_expression
                ;


/* ===================================== */


logical_and_expression : inclusive_or_expression                         { $$ = new UnaryExpression($1,"inclusive_or_expression");mystack.push($$);}
                       | logical_and_expression AND_OPERATOR inclusive_or_expression
                       ;

argument_expression_list : assignment_expression
                         | argument_expression_list ',' assignment_expression
                         ;



/* ===================================== */


inclusive_or_expression : exclusive_or_expression                         { $$ = new UnaryExpression($1,"exclusive_or_expression");mystack.push($$);}
                        | inclusive_or_expression '|' exclusive_or_expression
                        ;

/* ===================================== */

exclusive_or_expression : and_expression                                  { $$ = new UnaryExpression($1,"and_expression");mystack.push($$);}
                        | exclusive_or_expression '^' and_expression
                        ;

/* ===================================== */

and_expression : equality_expression                                      { $$ = new UnaryExpression($1,"equality_expression");mystack.push($$);}
               | and_expression '&' equality_expression
               ;

/* ===================================== */

equality_expression : relational_expression                               { $$ = new UnaryExpression($1,"relational_expression");mystack.push($$);}
                    | equality_expression EQ_OPERATOR relational_expression
                    | equality_expression NE_OPERATOR relational_expression
                    ;

/* ===================================== */

relational_expression : shift_expression                                  { $$ = new UnaryExpression($1,"shift_expression");mystack.push($$);}
                      | relational_expression '<' shift_expression        
                      | relational_expression '>' shift_expression        
                      | relational_expression LE_OPERATOR shift_expression 
                      | relational_expression GE_OPERATOR shift_expression
                      ;

/* ===================================== */

shift_expression : additive_expression                                   { $$ = new UnaryExpression($1,"additive_expression");mystack.push($$);}
                 | shift_expression LEFT_OPERATOR additive_expression
                 | shift_expression RIGHT_OPERATOR additive_expression
                 ;

/* ===================================== */

additive_expression : multiplicative_expression                            { $$ = new UnaryExpression($1,"multiplicative_expression");mystack.push($$);}
                    | additive_expression '+' multiplicative_expression    { $$ = new BinaryExpression($1,"+",$3);mystack.push($$);
                                                                              std::cout << "ADDITION COMPLETE,recursive testing" << std::endl;
                                                                           }
                    | additive_expression '-' multiplicative_expression    { $$ = new BinaryExpression($1,"-",$3);mystack.push($$);



                    }
                    ;

/* ===================================== */

multiplicative_expression : cast_expression                                { $$ = new UnaryExpression($1,"cast_expression");mystack.push($$);}   
                          | multiplicative_expression '*' cast_expression  { $$ = new BinaryExpression($1,"*",$3);mystack.push($$);std::cout << "MULT" << std::endl;}
                          | multiplicative_expression '/' cast_expression  { $$ = new BinaryExpression($1,"/",$3);mystack.push($$);}
                          | multiplicative_expression '%' cast_expression  { $$ = new BinaryExpression($1,"%",$3);mystack.push($$);}
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
               | RETURN expression ';'
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
                                                                      for(int i=0;i<scope_counter;i++){
                                                                        std::cout << "    " ;
                                                                      }
                                                                      std::cout << "VARIABLE : " << identifier_value << std::endl;
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

init_declarator_list : init_declarator                                    {std::cout << "times of number" << std::endl;}
                     | init_declarator_list ',' init_declarator           {std::cout << "number of times" << std::endl;}
                     ;

init_declarator : declarator
                | declarator '=' initializer                                            { 
                                                                                          std::cout << "hohohoohoh" << std::endl;
                                                                                          std::string strOp;
                                                                                          std::vector<int> vec1;
                                                                                          std::vector<std::string> operations;

                                                                                          /* store initialization of register variable */
                                                                                          int reg = mips32.findEmptyRegister();
                                                                                          mips32.Bind(0,reg,$1);
                                                                                          while (!mystack.empty()){
                                                                                              mystack.top()->printer();
                                                                                            if(mystack.top()->getType() == "+" || mystack.top()->getType() == "*" || mystack.top()->getType() == "-" || mystack.top()->getType() == "/"){
                                                                                              strOp = mystack.top()->getType();
                                                                                              operations.push_back(strOp);
                                                                                              for(int i=0;i<operations.size();i++){
                                                                                                std::cout << "this works " << operations[i] << std::endl;
                                                                                              }
                                                                                            }
                                                                                            else if(mystack.top()->getType() == "Identifier"){
                                                                                              /* check if identifier exists prior to this */
                                                                                              int check = mips32.registerLookup(mystack.top()->getName());
                                                                                              if(check == -1){
                                                                                                std::cout << "variable " << mystack.top()->getName() << " is undeclared" << std::endl;
                                                                                                return -1;
                                                                                              }
                                                                                              else{
                                                                                                Register reg1 = mips32.getValue(check);
                                                                                                int val = reg1.value;
                                                                                                vec1.push_back(val);
                                                                                              }
                                                                                            }
                                                                                            else if(mystack.top()->getType() == "Constant"){
                                                                                              vec1.push_back(mystack.top()->getConstant());
                                                                                            }
                                                                                            mystack.pop();
                                                                                          }
                                                                                          /* after collecting all necessary data, combine them */
                                                                                          for(int i=0;i<vec1.size();i++){
                                                                                            std::cout << "COLLECTION : " << vec1[i] << std::endl;
                                                                                          }
                                                                                          for(int i=0;i<operations.size();i++){
                                                                                            std::cout << "OPERATORSSSS : " << operations[i] << std::endl;
                                                                                          }
                                                                                          int sum = 0;
                                                                                          std::cout << "OPERATIONS SIZE : " <<operations.size() << std::endl;
                                                                                          for(int i=0;i<operations.size();i++){
                                                                                            std::cout << "inside the loop" << std::endl;
                                                                                            if(operations[i] == "+"){
                                                                                              std::cout << "VALUE : " << vec1[vec1.size()-1] << std::endl;
                                                                                              sum += vec1[vec1.size()-1];

                                                                                              vec1.pop_back();
                                                                                            }
                                                                                            else if(operations[i] == "*"){
                                                                                              std::cout << "VALUES : " << vec1[vec1.size()-1] << " " << vec1[vec1.size()-2] << std::endl;
                                                                                              sum += (vec1[vec1.size()-2] * vec1[vec1.size()-1]);
                                                                                              std::cout << "MULT is this working?" << std::endl;
                                                                                              vec1.pop_back();
                                                                                              vec1.pop_back();
                                                                                            }
                                                                                            else if(operations[i] == "-"){
                                                                                              std::cout << "MINUS : " << vec1[0] << std::endl;
                                                                                              sum = sum - vec1[0];
                                                                                              vec1.pop_back();
                                                                                            }
                                                                                            else if(operations[i] == "/"){
                                                                                              sum += (vec1[1] / vec1[0]);
                                                                                              vec1.erase(vec1.begin());
                                                                                              vec1.erase(vec1.begin());
                                                                                            }
                                                                                          }
                                                                                          /* add remaining components */

                                                                                          std::cout << "FINAL ANSWER : " << $1 << " = " << sum << std::endl;
                                                                                          mips32.Bind(sum,reg,$1);
                                                                                          std::cout << std::endl;
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

direct_declarator : IDENTIFIER                                                      { identifier_value = $1;
                                                                                      int x = mips32.findEmptyRegister();
                                                                                      if(x == -1){
                                                                                        std::cout << "redeclaration of variable / registers are filled with existing data" << std::endl;
                                                                                        return -1;
                                                                                      }
                                                                                      else{

                                                                                        mips32.Bind(0,x,$1);
                                                                                        mips32.printAllRegisters();
                                                                                      }
                                                                                    }
                  | '(' declarator ')'                                               
                  | direct_declarator '[' constant_expression ']'                         
                  | direct_declarator '[' ']'                               
                  | direct_declarator function_name parameter_type_list ')'         {std::cout << "asdasdasdasdsa" << std::endl;}         
                  | direct_declarator function_name identifier_list ')'             {std::cout << "sqqqqqqqq" << std::endl;}
                  | direct_declarator function_name ')'                             {std::cout << "pppppppppppppppp" << std::endl;}
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
                                                                              int reg = mips32.findEmptyRegister();
                                                                              mips32.Bind(0,reg,$2);
                                                                              mips32.printAllRegisters();
                                                                              for(int i=0;i<scope_counter;i++){
                                                                                std::cout << "    " ;
                                                                              }
                                                                              std::cout << "    PARAMS : " << $2 << std::endl;
                                                                          }
                      | declaration_specifiers
                      ;

identifier_list : IDENTIFIER                                                                        
                | identifier_list ',' IDENTIFIER                                                    
                ;


/* ========= initializer ======== */

initializer : assignment_expression                                     { $$ = new UnaryExpression($1,"assignment_expression");}
            | start_scope initializer_list end_scope
            | start_scope initializer_list ',' end_scope
            ;

initializer_list : initializer
                 | initializer_list ',' initializer
                 ;


/* ================== function definitions ====================== */

function_definition : declaration_specifiers declarator declaration_list compound_statement   
                    | declaration_specifiers declarator compound_statement                         {mips32.clearRegisters();std::cout << "function definition compound statemnet end" << std::endl;}
                    | declarator declaration_list compound_statement                          
                    | declarator compound_statement                                         
                    ;


/* ====================== stdout handlers ====================== */

start_scope : '{'        {
                            for(int i=0;i<scope_counter;i++){
                              std::cout << "    " ;
                            }
                            scope_counter++; std::cout << "SCOPE" << std::endl;
                         }
            ;

end_scope : '}'          {scope_counter--;}
          ;


function_name : '('   {
                        for(int i=0;i<scope_counter;i++){
                          std::cout << "    " ;
                        }
                        std::cout << "FUNCTION : " << identifier_value << std::endl;
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


