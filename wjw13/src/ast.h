#ifndef AST_H
#define	AST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <stack>


class mips_stack;

// Base node class for AST
class Node{
public:
	// virtual void postTraversal(Expression* exp1);
	virtual ~Node() {}
};

// Expressions
class Expression : public Node{
public:
	virtual std::string getType() const;
	virtual void printer() const {}
	virtual const Expression *getLeft() const {}
	virtual const Expression *getRight() const {}
	virtual const Expression *getNext() const {}
	virtual std::string getName() const {}
	virtual int getConstant() const {}
	virtual std::string getOperator() const {}
	virtual void codeGen(const Expression* exp1,mips_stack &mips32) const {}
	virtual bool getPrefix() const {}
};

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
	bool isMinus = false;
public:
	std::string getName() const;
	IdentifierExpression(std::string str1,bool state): id(str1),isMinus(state) {}
	std::string getType() const;
	bool getPrefix() const;
	void printer() const;
};

bool IdentifierExpression::getPrefix() const{
	return isMinus;
}

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
public:
	PostfixExpression(Expression* exp): exp1(exp) {}	
	std::string getFunctionName(const Expression* exp) const;
	void codeGen(const Expression* exp1,mips_stack &mips32) const;
};


// Statements
class Statement : public Node{
	virtual void print() {}
};

class ExpressionStatement : public Statement{
	const Expression *getExpression() const;
};

class IfStatement : public Statement{
	Expression* exp;
	Statement* state;
public:
	const Expression *getCondition() const;
	const Statement *getStatement() const;
	IfStatement(Expression* exp1,Statement* state1): exp(exp1), state(state1) {}
};

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
	bool inUse = false;			// can't use 0 to check if register is in use - look at MIPS documentation
};

// Register handling
// declaration - int a = 3; should use a new register
// usage - a = 5; should use an existing register regardless of scope as tested in C90 ( except in the case of function calls)
class mipsRegisters{
	std::vector<Register> registers;	// sets 31 registers to 0
public:
	mipsRegisters():registers(32) {}
	Register getValue(const int &registerName);
	void Bind(const int &val,const int &registerName,const std::string &var);
	int registerLookup(const std::string &varName);
	void clearRegisters();
	void printAllRegisters();
	int findEmptyRegister();
};

class mips_stack{
	std::map<std::string,std::string> varToRegister;
	int stack_counter = 0;
	int param_counter = 4;
public:
	void Insert(std::string var);
	std::string get_stack_counter();
	std::string getStackOffset(std::string identifier);
	void InsertParams(std::string str1);
	void noDeclare_singleHandler(std::vector<Expression*> &completeTree,std::string declarator,std::string assignOp);
	void singleHandler(std::vector<Expression*> &completeTree,std::string declarator);
	void returnHandler(std::vector<Expression*> &completeTree);
	void ShuntingYardAlgo(std::vector<Expression*> &completeTree,std::stack<Expression*> &mystack,const bool &debugMode,std::string declarator,std::string assignOp);

	// handling function calls
	void getNew();
};

void mips_stack::getNew(){
	param_counter = 4;
	stack_counter = 0;
	varToRegister.clear();
}

void mips_stack::InsertParams(std::string str1){
	Insert(str1);
	std::stringstream ss;
	ss << "$" << param_counter;
	std::cout << "sw 			" << ss.str() << "," << getStackOffset(str1) << std::endl;
	param_counter++;
}

void mips_stack::singleHandler(std::vector<Expression*> &completeTree,std::string declarator){
	int identifiers = 0;
	int constants = 0;

	for(int i=0;i<completeTree.size();i++){
		if(completeTree[i]->getType() == "Constant"){
			constants++;
		}
		else if(completeTree[i]->getType() == "Identifier"){
			identifiers++;
		}
	}
	if(constants == 1 && identifiers == 0){
		// handle single constant
		int ans;
		for(int i=0;i<completeTree.size();i++){
			if(completeTree[i]->getType() == "Constant"){
				ans = completeTree[i]->getConstant();
			}
		}
		std::stringstream ss;
		ss << ans;
		Insert(declarator);
		std::string offset = getStackOffset(declarator);
		std::cout << "lw 		$2," << offset << std::endl;
		std::cout << "li 		$2," << ss.str() << std::endl;
		std::cout << "sw 		$2," << offset << std::endl;
	}
	else if(constants == 0 && identifiers == 1){
		// handle single identifier
		std::string ans;
		bool minus = false;
		for(int i=0;i<completeTree.size();i++){
			if(completeTree[i]->getType() == "Identifier"){
				ans = getStackOffset(completeTree[i]->getName());
				if(completeTree[i]->getPrefix()){
					minus = true;
				}
			}
		}
		Insert(declarator);
		std::string offset = getStackOffset(declarator);
		std::cout << "lw 		$2," << ans << std::endl;
		if(minus){
			// for negative identifiers, -a
			std::cout << "sub 		$2,$0,$2" << std::endl;	
		}
		std::cout << "sw 		$2," << offset << std::endl;
	}
}

void mips_stack::noDeclare_singleHandler(std::vector<Expression*> &completeTree,std::string declarator,std::string assignOp){
	int identifiers = 0;
	int constants = 0;

	for(int i=0;i<completeTree.size();i++){
		if(completeTree[i]->getType() == "Constant"){
			constants++;
		}
		else if(completeTree[i]->getType() == "Identifier"){
			identifiers++;
		}
	}
	if(constants == 1 && identifiers == 1){
		// handle a = 3
		int ans;
		for(int i=0;i<completeTree.size();i++){
			if(completeTree[i]->getType() == "Constant"){
				ans = completeTree[i]->getConstant();
			}
		}
		std::stringstream ss;
		ss << ans;
		std::string offset = getStackOffset(declarator);
		if(assignOp == "="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "li 		$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;			
		}
		else if(assignOp == "+="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "addiu 		$2,$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "-="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "addiu 		$2,$2,-" << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "*="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "mul 		$2,$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "/="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "div 		$2,$2," << ss.str() << std::endl;
			std::cout << "mfhi 		$2" << std::endl;
			std::cout << "mflo 		$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "%="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "div 		$0,$2," << ss.str() << std::endl;
			std::cout << "mfhi 		$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "<<="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "sll 		$2,$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == ">>="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "sra 		$2,$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "&="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "andi 		$2,$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "^="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "xori 		$2,$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "|="){
			std::cout << "lw 		$2," << offset << std::endl;
			std::cout << "ori 		$2,$2," << ss.str() << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}

	}
	else if(constants == 0 && identifiers == 2){
		// handle b = a
		std::vector<std::string> ans;
		bool minus = false;
		int counter = 0;
		for(int i=0;i<completeTree.size();i++){
			if(completeTree[i]->getType() == "Identifier"){
				ans.push_back(getStackOffset(completeTree[i]->getName()));
				if(counter == 1){
					if(completeTree[i]->getPrefix()){
						minus = true;
					}
				}
				counter++;
			}
		}

		std::string offset = ans[0];
		std::string RHS_offset = ans[1];

		// load RHS into register $2
		std::cout << "lw 		$2," << RHS_offset << std::endl;

		// for negative identifiers, -a
		if(minus){
			std::cout << "sub 		$2,$0,$2" << std::endl;
		}

		if(assignOp == "="){
			std::cout << "sw 		$2," << offset << std::endl;		
		}
		if(assignOp == "+="){
			// if any assignOp other than =, means that c += 3 and that variable is already declared
			// get current value of c
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "addu 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "-="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "subu 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "*="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "mul 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "/="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "div 		$2,$3,$2" << std::endl;
			std::cout << "mfhi 		$2" << std::endl;
			std::cout << "mflo 		$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "%="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "div 		$0,$3,$2" << std::endl;
			std::cout << "mfhi 		$10" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "<<="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "sll 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == ">>="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "sra 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "&="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "and 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "^="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "xor 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
		else if(assignOp == "|="){
			std::cout << "lw 		$3," << offset << std::endl;
			std::cout << "or 		$2,$3,$2" << std::endl;
			std::cout << "sw 		$2," << offset << std::endl;
		}
	}
}

#endif

