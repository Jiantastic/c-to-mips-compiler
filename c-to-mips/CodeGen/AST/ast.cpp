#include <iostream>
#include <cstdlib>
#include <string>

// Base node class for AST
class Node{
public:
	virtual ~Node() {}
};

// Expressions
class Expression : public Node{
	const Type * getType();
	// Render using current identifier-register bindings in ctxt
public:
	
	int value(){
		return 1;
	}
	void renderAssembly(const Context & ctxt) const;
};

class BinaryExpression : public Expression{

public:
	const Expression *getLeft() const;
	OperatorCode getOperator() const;
	const Expression *getRight() const;
};


class IdentifierExpression : public Expression{
	std::string val;
public:
	std::string getName() const;
	IdentifierExpression(std::string s);
};


class ConstantExpression : public Expression{
	int value;
public:
	int getConstant() const;
	ConstantExpression(const int &i);
};

ConstantExpression::ConstantExpression(const int &i){
	value = i;
}

// Statements
/*
statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;
*/

class Statement : public Node{
	// Render using current identifier-register bindings in ctxt
	Context renderAssembly(const Context & ctxt) const;
};

class LabeledStatement : public Statement{
	
};

class CompoundStatement : public Statement{
	int getDeclarationCount() const;
	const Declaration *getDeclaration(int i) const;
	int getStatementCount() const;
	const Statement *getStatement(int i) const;
};

class ExpressionStatement : public Statement{
	const Expression *getExpression() const;
};

class SelectionStatement : public Statement{
	
};


/*

selection_statement : IF '(' expression ')' statement
                    | IF '(' expression ')' statement ELSE statement
                    | SWITCH '(' expression ')' statement
                    ;

*/                

class IfStatement : public Statement{
	const Expression *getCondition() const;
	const Statement * getStatement() const;
};



class IterationStatement : public Statement{
	
};

class JumpStatement : public Statement{
	
};