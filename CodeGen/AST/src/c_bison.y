%{
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stack>
#include "ast.h"
#include "ast.cpp"

int yylex();
int yyerror(const char* s);
char* identifier_value;
int scope_counter = 0;
int is_function = 0;
std::vector<Expression*> completeTree;
std::stack<int> mystack;
std::vector<const Expression*> argument_list;
mipsRegisters mips32;
maps map_stack;
bool isMinus = false;
bool debugMode = false;
bool called = false;
std::string functionName;

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

translation_unit : external_declaration                   {std::cout << "mystery1" << std::endl;}
                 | translation_unit external_declaration    {std::cout << "mystery2" << std::endl;}
                 ;

external_declaration : declaration             {std::cout << "mystery3" << std::endl;}
                     | function_definition     {std::cout << "mystery4" << std::endl;}
                     ;

/* ===================== Parsing END ============================ */

/* NOTE : all implementations below are partial, REMEMBER to check against spec */



primary_expression : IDENTIFIER     {
                                      $$ = new IdentifierExpression($1);completeTree.push_back($$);
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
                                                                                            if(debugMode){
                                                                                              std::cout << "a = 3 + 2..." << std::endl;
                                                                                            }
                                                                                            int counter = 0;
                                                                                            /* binder is used here to store name of variable on the LHS eg: X in X = 3; */
                                                                                            std::string binder;

                                                                                            /* check if identifier $1 exists or not */
                                                                                            bool checker = false;
                                                                                            const Expression * temp1 = $1;
                                                                                            while(!checker){
                                                                                              if(temp1->getType() == "Identifier"){
                                                                                                /* identifier has to exist prior to this */
                                                                                                int v = mips32.registerLookup(temp1->getName());
                                                                                                binder = temp1->getName();
                                                                                                if(v == -1){
                                                                                                  auto x = map_stack.getValue(temp1->getName());
                                                                                                  if(x == -1){
                                                                                                    std::cout << "variable has to be declared before usage" << std::endl;
                                                                                                    return -1;
                                                                                                  }
                                                                                                  checker = true;
                                                                                                }
                                                                                                else{
                                                                                                  checker = true;
                                                                                                }
                                                                                              }
                                                                                              else{
                                                                                                temp1 = temp1->getNext();
                                                                                              }
                                                                                            }
                                                                                            std::string assign = $2->getType();
                                                                                          /* Shunting-yard algorithm */
                                                                                          ShuntingYardAlgo(completeTree,mystack,debugMode,mips32,map_stack,binder,assign);
                                                                                          if(debugMode){
                                                                                            map_stack.printer();
                                                                                          }
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
                      | logical_or_expression OR_OPERATOR logical_and_expression
                      ;


postfix_expression : primary_expression                                           { $$ = new UnaryExpression($1,"primary_expression");completeTree.push_back($$);}
                   | postfix_expression '[' expression ']'
                   | postfix_expression '(' ')'                                   { 
                                                                                    $$ = new PostfixExpression($1,"NoParams");
                                                                                    map_stack.getNew(mips32);
                                                                                    called = true;
                                                                                    $$->codeGen($1);
                                                                                    if(debugMode){
                                                                                      std::cout << "func call 1" << std::endl;
                                                                                      mips32.printAllRegisters();
                                                                                    }
                                                                                    completeTree.push_back($$);
                                                                                  }
                   | postfix_expression '(' argument_expression_list ')'          { 
                                                                                    $$ = new PostfixExpression($1,"Params");
                                                                                    /* $$->loadParams(argument_list,mips32,map_stack); */
                                                                                    map_stack.getNew(mips32);
                                                                                    called = true;
                                                                                    $$->codeGen($1);
                                                                                    if(debugMode){
                                                                                      std::cout << "func call 2" << std::endl;
                                                                                      mips32.printAllRegisters();
                                                                                    }
                                                                                    completeTree.push_back($$);
                                                                                  }
                   | postfix_expression '.' IDENTIFIER                            
                   | postfix_expression PTR_OPERATOR IDENTIFIER                  
                   | postfix_expression INC_OPERATOR
                   | postfix_expression DEC_OPERATOR
                   ;

unary_operator : '&'    
               | '*'
               | '+'
               | '-'                                                    { /*SOLVE NEGATIVE EFFECTS, -a has retroactive effects on the rest of the program*/ isMinus = true;}
               | '~'
               | '!'
               ;

cast_expression : unary_expression                                      { $$ = new UnaryExpression($1,"unary_expression");completeTree.push_back($$);}
                | '(' type_name ')' cast_expression                     
                ;


/* ===================================== */


logical_and_expression : inclusive_or_expression                         { $$ = new UnaryExpression($1,"inclusive_or_expression");completeTree.push_back($$);}
                       | logical_and_expression AND_OPERATOR inclusive_or_expression
                       ;

argument_expression_list : assignment_expression                                {argument_list.push_back($1);}
                         | argument_expression_list ',' assignment_expression   {argument_list.push_back($3);}
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

equality_expression : relational_expression                               { $$ = new UnaryExpression($1,"relational_expression");completeTree.push_back($$);}
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
          | compound_statement        {std::cout << "DO I GO THROASDJASKLDJALSJDSLKA" << std::endl;}
          | expression_statement      {std::cout << "is this over?" << std::endl;}
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

expression_statement : ';'             {std::cout << "exp statement 1?" << std::endl;}
                     | expression ';'  {std::cout << "exp statement 2?" << std::endl;}
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
               | RETURN expression ';'      { ShuntingYardAlgo(completeTree,mystack,debugMode,mips32,map_stack);}
               ;

/* ============================ Statement recursion tree units ============================= */

statement_list : statement                   
               | statement_list statement     
               ;

declaration_list : declaration
                 | declaration_list declaration
                 ;


/* ================ Declaration ========================= */


declaration : declaration_specifiers ';'                           {std::cout << "declaration for function?" << std::endl;}
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
                                                                                          
                                                                                          int invalid_check = mips32.registerLookup($1);
                                                                                          if(invalid_check != -1){
                                                                                            std::cout << "variable " << $1 << " has already been declared" << std::endl;
                                                                                            return -1;
                                                                                          }
                                                                                          auto yy = map_stack.getValue($1);
                                                                                          if(yy != -1){
                                                                                            std::cout << "variable " << $1 << " has already been declared" << std::endl;
                                                                                            return -1;
                                                                                          }
                                                                                          int x = mips32.findEmptyRegister();
                                                                                          if(x == -1){
                                                                                            mips32.clearTempRegisters();
                                                                                          }
                                                                                          int f = mips32.findEmptyRegister();
                                                                                          mips32.Bind(0,f,$1,map_stack);
                                                                                          if(debugMode){
                                                                                            mips32.printAllRegisters();
                                                                                            map_stack.printer();
                                                                                          }
                                                                                        }

                | declarator '=' initializer                                            {  std::cout << "hohohohoho" << std::endl;
                                                                                            std::cout << "$3 yo " << $3->getType() << std::endl;
                                                                                            int counter = 0;
                                                                                            int x = mips32.findEmptyRegister();
                                                                                            if(x == -1){
                                                                                              mips32.clearTempRegisters();
                                                                                              x = mips32.findEmptyRegister();
                                                                                              /* potential TODO: Check for redeclaration of variable */
                                                                                            }

                                                                                            for(int i=0;i<completeTree.size();i++){
                                                                                            /* handles NON-BINARY EXPRESSIONS eg: int a= 3;int b = a; */

                                                                                              if(completeTree[i]->getType() == "Constant"){
                                                                                                mips32.Bind(completeTree[i]->getConstant(),x,$1,map_stack);
                                                                                                
                                                                                                for(int i=0;i<completeTree.size();i++){
                                                                                                  if(completeTree[i]->getType() == "Binary" ){
                                                                                                    counter++;
                                                                                                  }
                                                                                                }
                                                                                              }
                                                                                              else if(completeTree[i]->getType() == "Identifier"){
                                                                                                int v = mips32.registerLookup(completeTree[i]->getName());
                                                                                                auto final_value = 0;
                                                                                                if(v == -1){
                                                                                                  auto yy = map_stack.getValue(completeTree[i]->getName());
                                                                                                  if(yy == -1){
                                                                                                    std::cout << "error getting variable" << std::endl;
                                                                                                    return -1;
                                                                                                  }
                                                                                                  final_value = yy;
                                                                                                }
                                                                                                else{
                                                                                                  Register r1 = mips32.getValue(v);
                                                                                                  final_value = r1.value;
                                                                                                }
                                                                                                mips32.Bind(final_value,x,$1,map_stack);
                                                                                                for(int i=0;i<completeTree.size();i++){
                                                                                                  if(completeTree[i]->getType() == "Binary" ){
                                                                                                    counter++;
                                                                                                  }
                                                                                                }
                                                                                              }
                                                                                            }
                                                                                            if(debugMode){
                                                                                              mips32.printAllRegisters();
                                                                                              map_stack.printer();
                                                                                            }
                                                                                            
                                                                                              /* Shunting-yard Algorithm */
                                                                                            if(counter != 0){
                                                                                              ShuntingYardAlgo(completeTree,mystack,debugMode,mips32,map_stack,$1);
                                                                                            }
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
                  | direct_declarator function_name parameter_type_list ')'                {std::cout << "kekekek 1" << std::endl;} 
                  | direct_declarator function_name identifier_list ')'                   {std::cout << "kekekeke 2 " << std::endl;}
                  | direct_declarator function_name ')'                                  {std::cout << "kekekeke 3 " << std::endl;}
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
                                                                              /* TODO: replace these bindings with specific function param registers! */
                                                                              int reg = mips32.findEmptyRegister();
                                                                              mips32.Bind(0,reg,$2,map_stack);
                                                                              if(debugMode){
                                                                                mips32.printAllRegisters();
                                                                                map_stack.printer();
                                                                                for(int i=0;i<scope_counter;i++){
                                                                                  std::cout << "    " ;
                                                                                }
                                                                                std::cout << "    PARAMS : " << $2 << std::endl;
                                                                              }
                                                                             
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

function_definition : declaration_specifiers declarator declaration_list compound_statement   {std::cout << "111111" << std::endl;}
                    | declaration_specifiers declarator compound_statement                         {map_stack.getOld();mips32.clearTempRegisters();}
                    | declarator declaration_list compound_statement                              {std::cout << "22222" << std::endl;}
                    | declarator compound_statement                                         {std::cout << "333333" << std::endl;}
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
                            if(called){
                              /* if a function call occurred */
                              std::cout << "    lw    $31,0($sp)" << std::endl;
                              std::cout << "    addiu $sp,$sp,4" << std::endl;
                              called = false;
                            }
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


