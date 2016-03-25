#ifndef AST_H
#define	AST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

// to solve hoisting issue
class maps;
class mipsRegisters;
/*
IMPORTANT : consider using int counts to traverse the AST later on;
create a pretty print function that traverses through the entire tree!
]

http://stackoverflow.com/questions/10739923/what-is-in-bison
REVELATION : $$ is returned as $x !

Example:
shift_expression : additive_expression                                   { $1->test_print();}
this means that $1 is whatever I returned to $$ for additive expressions!,
in this case $$ = new Plus !


Consider using smart pointers
http://stackoverflow.com/questions/106508/what-is-a-smart-pointer-and-when-should-i-use-one

TODO:
Statements
Register tracking - look at notes
CodeGen - look at phone pic, notes

1. track all declared variables, int X ..., only 2 places where declarations like int X can occur - declaration and parameter declaration
*/

// Base node class for AST
class Node{
public:
	// virtual void postTraversal(Expression* exp1);
	virtual ~Node() {}
};


// Expressions

class Expression : public Node{
public:
	// const Type * getType();
	// virtual evaluate() = 0;
	// Render using current identifier-register bindings in ctxt
	virtual std::string getType() const {}
	virtual void printer() const {}
	virtual const Expression *getLeft() const {}
	virtual const Expression *getRight() const {}
	virtual const Expression *getNext() const {}
	virtual std::string getName() const {}
	virtual int getConstant() const {}
	virtual std::string getOperator() const {}
	virtual void codeGen(const Expression* exp1) const {}
	//virtual void evaluate() const {}
	//virtual int getSum() const {}

};

// generic class for plus,minus for 2 operands and 1 operator
class BinaryExpression : public Expression{
private:
	Expression *left = NULL;
	Expression *right = NULL;
	std::string opCode;
public:
	BinaryExpression(Expression *l,std::string op,Expression *r): left(l),opCode(op),right(r) {}
	const Expression *getLeft() const;
	std::string getOperator() const;
	const Expression *getRight() const;
	std::string getType() const;
	void printer() const;
};


class UnaryExpression : public Expression{
	Expression* exp1 = NULL;
	std::string type;
public:
	UnaryExpression(Expression* exp,std::string ExpType): exp1(exp),type(ExpType) {}
	const Expression *getNext() const;
	std::string getType() const;
	void printer() const;
};

class IdentifierExpression : public Expression{
	std::string id;
public:
	std::string getName() const;
	IdentifierExpression(std::string str1): id(str1) {}
	std::string getType() const;
	void printer() const;
};

class ConstantExpression : public Expression{
	int num;
public:
	int getConstant() const;
	ConstantExpression(const int &num1) : num(num1) {}
	std::string getType() const;
	void printer() const;
};

class BracketExpression : public Expression{
	std::string leftBracket;
	std::string rightBracket;
	Expression* exp1;
public:
	BracketExpression(std::string leftBrac,std::string rightBrac,Expression* exp): leftBracket(leftBrac),rightBracket(rightBrac),exp1(exp) {}
	std::string getType() const;
	void printer() const;
};

class PostfixExpression : public Expression{
	Expression* exp1;
	std::string type;
public:
	PostfixExpression(Expression* exp,std::string val): exp1(exp),type(val) {}
	std::string getType();	
	std::string getFunctionName(const Expression* exp) const;
	//void loadParams(std::vector<const Expression*> core_vector,mipsRegisters &mips,maps &map1);
	void codeGen(const Expression* exp1) const;
};

// Statements

class Statement : public Node{
	// Render using current identifier-register bindings in ctxt
	// Context renderAssembly(const Context & ctxt) const;
	virtual void print() {}
};

class ExpressionStatement : public Statement{
	const Expression *getExpression() const;
};

class SelectionStatement : public Statement{

};
      

class IfStatement : public Statement{
	Expression* exp;
	Statement* state;
public:
	const Expression *getCondition() const;
	const Statement *getStatement() const;
	IfStatement(Expression* exp1,Statement* state1): exp(exp1), state(state1) {}
	// IfStatement(Expression* exp1,Statement* state1,Statement* state2):
};

class Parameters{
	int counter = 0;
	std::vector<std::string> params;
public:
	void loadParams(std::string str1);
	int checkifParam(std::string iden);
	void codeGen();
	void calculate();
	void iterator(std::vector<Expression*> exp1);

};

// load parameters into a special container
void Parameters::loadParams(std::string str1){
	params.push_back(str1);
}

// executed before anything else, in anything that requires ShuntingYardAlgo
bool Parameters::iterator(std::std::vector<<Expression*> exp1){
	for(int i=0;i<exp1.size();i++){
		if(exp1[i]->getType == "Identifier"){
			bool test = checkifParam(exp1[i]->getName());
			if(test){
				return true;
			}
		}
	}
	return false;
}

// check if parameter before Shunting Yard algorithm, if it is, use another algorithm ( not Shunting Yard)
int Parameters::checkifParam(std::string iden){
	for(int i=0;i<params.size();i++){
		if(params[i] == iden){
			std::cout << "identifier is a parameter" << std::endl;
			// returns register position
			return i+4;
		}
	}
	return -1;
}

// take this entire thing and generate codeGen
void Parameters::calculate(std::vector<Expression*> &completeTree){
	std::stack<std::string> func_params;

	for(int i=0;i<completeTree.size();i++){
	  if(completeTree[i]->getType() == "Binary" || completeTree[i]->getType() == "Identifier" || completeTree[i]->getType() == "Constant"){
	    if(debugMode){
	      completeTree[i]->printer();
	    }
	    if(completeTree[i]->getType() == "Constant"){
	      mystack.push(completeTree[i]->getConstant());
	    }
	    else if(completeTree[i]->getType() == "Identifier"){
	    	// for identifiers, check if it is a parameter first
	    	if(checkifParam(completeTree[i]->getName()) != -1){

	    	}
	    	else{
		      // logic to handle identifier conversion to a constant
		      	int y = mips32.registerLookup(completeTree[i]->getName());
		      	if(y == -1){
		      	// get value from map_stack if not in register file
		      		y = maps1.getValue(completeTree[i]->getName());
			      	if(y == -1){
			      		// not in map_stack nor in registers
			      		std::cout << "variable is not in registers nor in stack" << std::endl;
			      		exit(EXIT_FAILURE);
			      	}
			      	mystack.push(maps1.getValue(completeTree[i]->getName()));
		      	}
		      	else{
		      		// get value from register if register name is found
			      	Register r = mips32.getValue(y);
			      	mystack.push(r.value);
		      	}	    		
	    	}
	    }
	    else if(completeTree[i]->getType() == "Binary"){
	      std::string strOp = completeTree[i]->getOperator();
	      int yy;
	      int zz;
	      // need to handle string, in the case of param 1 + param 2
	      auto temp_x = mystack.top();
	      mystack.pop(); 
		  auto temp_y = mystack.top();
	      mystack.pop();


	      if(typeid(temp_x) == "PKc" && typeid(temp_y) != "PKc"){
	      	// x is params, y is not
	      	yy = checkifParam(temp_x);
	      	if(strOp == "+"){
	      		std::cout << "addiu 	$" << yy << ",$" << 
	      	}
	      	else if(strOp == "-"){
	      		std::cout << "addiu 	$"
	      	}
	      	else if(strOp == "*"){

	      	}
	      	else if(strOp == "/"){

	      	}
	      }
	      else if(typeid(temp_x) != "PKc" && typeid(temp_y) == "PKc"){
	      	// y is params, x is not
	      	zz = checkifParam(temp_y);
	      	if(strOp == "+"){
	      		std::cout << "addiu 	$"
	      	}
	      	else if(strOp == "-"){
	      		std::cout << "addiu"
	      	}
	      	else if(strOp == "*"){

	      	}
	      	else if(strOp == "/"){

	      	}
	      }
	      else if(typeid(temp_x) == "PKc" && typeid(temp_y) == "PKc"){
	      	// x and y are params
	      	yy = checkifParam(temp_x);
	      	zz = checkifParam(temp_y);
	      	if(strOp == "+"){
	      		std::cout << "addiu 	$"
	      	}
	      	else if(strOp == "-"){
	      		std::cout << "subu"
	      	}
	      	else if(strOp == "*"){

	      	}
	      	else if(strOp == "/"){

	      	}
	      }




	      
	      if(typeid(temp_x) == "PKc" || typeid(temp_y) == "PKc"){
	      	// this means that either one is a parameter

	      	if(strOp == "+"){
	      		
	      	}
	      	else if(strOp == "-"){
	      		std::cout << "subu "
	      	}
	      	else if(strOp == "*"){

	      	}
	      	else if(strOp == "/"){

	      	}

	      	yy = checkifParam(temp_x);
	      }

	      int sum = 0;
	      if(strOp == "+"){
	      	std::cout << "addiu $"
	        sum = temp_y + temp_x;
	      }
	      else if(strOp == "-"){
	        sum = temp_y - temp_x;
	      }
	      else if(strOp == "*"){
	        sum = temp_y * temp_x;
	      }
	      else if(strOp == "/"){
	        sum = temp_y / temp_x;
	      }
	      else if(strOp == "|"){
	        sum = temp_y | temp_x;
	      }
	      else if(strOp == "^"){
	        sum = temp_y ^ temp_x;
	      }
	      else if(strOp == "&"){
	        sum = temp_y & temp_x;
	      }
	      else if(strOp == "=="){
	        sum = temp_y == temp_x;
	      }
	      else if(strOp == "!="){
	        sum = temp_y != temp_x;
	      }
	      else if(strOp == "<"){
	        sum = temp_y < temp_x;
	      }
	      else if(strOp == ">"){
	        sum = temp_y > temp_x;
	      }
	      else if(strOp == "<="){
	        sum = temp_y <= temp_x;
	      }
	      else if(strOp == ">="){
	        sum = temp_y >= temp_x;
	      }
	      else if(strOp == "<<"){
	        sum = temp_y << temp_x;
	      }
	      else if(strOp == ">>"){
	        sum = temp_y >> temp_x;
	      }
	      else if(strOp == "%"){
	      	sum = temp_y % temp_x;
	      }
	      mystack.push(sum);
	    }
	  }
	}
	int ans = mystack.top();
	if(declarator == ""){
		// codeGen for return expression;
		mips32.Bind(ans,25,"$t9_RETURN_",maps1);
		codeGen(25,mips32,"return");
	}
	else{
		// if "=", just execute the 3 statements
		int v = mips32.registerLookup(declarator);
		int final_answer = 0;
		Register r1 = mips32.getValue(v);
	
		if(assignOp == "+="){
			r1.value += ans;
			final_answer = r1.value;
		}
		else if(assignOp == "-="){
			r1.value -= ans;
			final_answer = r1.value;
		}
		else if(assignOp == "*="){
			r1.value *= ans;
			final_answer = r1.value;
		}
		else if(assignOp == "/="){
			r1.value /= ans;
			final_answer = r1.value;
		}
		else if(assignOp == "%="){
			r1.value /= ans;
			final_answer = r1.value;
		}
		else if(assignOp == "<<="){
			r1.value /= ans;
			final_answer = r1.value;
		}
		else if(assignOp == ">>="){
			r1.value /= ans;
			final_answer = r1.value;
		}
		else if(assignOp == "&="){
			r1.value /= ans;
			final_answer = r1.value;
		}
		else if(assignOp == "^="){
			r1.value /= ans;
			final_answer = r1.value;
		}
		else if(assignOp == "|="){
			r1.value /= ans;
			final_answer = r1.value;
		}
		else{
			// if "="
			final_answer = ans;
		}
		mips32.Bind(final_answer,v,declarator,maps1);
		codeGen(v,mips32);
	}
	completeTree.clear();
	mystack.pop();


	if(debugMode){
	  mips32.printAllRegisters();
	}
}

void Parameters::codeGen(){
	std::cout << "		addiu 	$sp,$sp,-" << counter << std::endl;
	std::cout << "		sw 		$fp," << i+4 << "($sp)" << std::endl;
	std::cout << "		move 	$fp,$sp" << std::endl;
	
	for(int i=0;i<counter;i++){


	}
}

class AssignmentOperator : public Expression{
	std::string assignment;
public:
	AssignmentOperator(std::string value): assignment(value) {}
	std::string getType();
};


// "struct with properties associated with a register"
class Register{
public:
	Register() {}
	Register(int v,std::string var,bool t): value(v),varName(var),inUse(t) {}
	int value = 0;
	std::string varName = "";
	bool inUse = false;			// can't use 0 to check if register is in use as register can be 
};

// Register handling
// declaration - int a = 3; should use a new register
// usage - a = 5; should use an existing register regardless of scope as tested in C90 ( except in the case of function calls)

// TODO: need to call map_stack when temporary registers run out of space 
// another problem is that any register values must be in map_stack for that function scope to ensure consistency
class mipsRegisters{
	std::vector<Register> registers;	// sets 31 registers to 0,make this public?
public:
	mipsRegisters():registers(32) {}
	Register getValue(const int &registerName);
	void Bind(const int &val,const int &registerName,const std::string &var,maps &map1);
	int registerLookup(const std::string &varName);
	void clearRegisters();
	void clearTempRegisters();		// clear all temporary registers before function call
	void printAllRegisters();
	int findEmptyRegister();
};


// before every function call jump, replace current map_stack with fresh map_stack, preserve map_stack in a stack, to be called after every return jump ( j $31)


class maps{
	std::map<std::string,int> map_stack;		// map is used over other data structures due to access time, O(log N)
// TO-DO : Implement a stack which swaps out registers when out of register space, alternating between stack and registers
	std::stack<std::map<std::string,int> > stacking; 
public:
	maps() {}
	void Insert(const std::string &str1,const int &r1);
	void getNew(mipsRegisters &mips);	// stores old map_stack in stack, clear map_stack of all values
	void getOld();
	int getValue(std::string iden);	// gets the value of an identifier
	void printer();
};


#endif

