#include <iostream>
#include <cstdlib>
#include <string>

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

*/

// Base node class for AST
class Node{
public:
	virtual ~Node() {}
};

// Expressions
class Expression : public Node{
public:
	// const Type * getType();
	// virtual evaluate() = 0;
	// Render using current identifier-register bindings in ctxt
	// void renderAssembly(const Context & ctxt) const;
	virtual void test_print(){
		std::cout << "Expression leader :)" << std::endl;
	}
};

class UnaryExpression : public Expression{
	Expression* exp1;
public:
	UnaryExpression(Expression* exp): exp1(exp) {}
};

class PrimaryExpression : public Expression{
	Expression* exp1;
public:
	PrimaryExpression(Expression* exp): exp1(exp) {}
};

class PostfixExpression : public Expression{
	Expression* exp1;
public:
	PostfixExpression(Expression* exp): exp1(exp) {}
};

class CastExpression : public Expression{
	Expression* exp1;
public:
	CastExpression(Expression* exp): exp1(exp) {}
};

class IdentifierExpression : public Expression{
	std::string id;
public:
	std::string getName() const;
	IdentifierExpression(std::string str1){
		id = str1;
	}
};

class ConstantExpression : public Expression{
	int num;
public:
	int getConstant() const;
	ConstantExpression(const int &num1){
		num = num1;
	}
};


// generic class for plus,minus for 2 operands and 1 operator
class BinaryExpression : public Expression{
private:
	Expression *left;
	Expression *right;
	string opCode;
public:
	BinaryExpression(Expression *l,string op,Expression *r): left(l),opCode(op),right(r) {}
	const Expression *getLeft() const;
	string getOperator() const;
	const Expression *getRight() const;
};


/*
class Plus : public Expression{
protected:
	Expression *left;
	Expression *right;
public:
	Plus(Expression *l,Expression *r): left(l),right(r) {}
	void test_print(){
		std::cout << "if this works, I understand what I am supposed to do :)" << std::endl;
	}
};

class Multiply : public Expression{
protected:
	Expression *left;
	Expression *right;
public:
	Multiply(Expression *l,Expression *r): left(l),right(r) {}
};*/