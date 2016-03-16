#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "ast.h"

// Expression Handlers

const Expression* BinaryExpression::getLeft() const{
	return left;
}

std::string BinaryExpression::getOperator() const{
	return opCode;
}

const Expression* BinaryExpression::getRight() const{
	return right;
}

const Expression* UnaryExpression::getNext() const{
	return exp1;
}

std::string BinaryExpression::getType() const{
	return "Binary";
}

void BinaryExpression::printer() const{
	std::cout << "TYPE: Binary Expression with operation " << getOperator() << std::endl;
}

std::string UnaryExpression::getType() const{
	return "Unary";
}

void UnaryExpression::printer() const{
	std::cout << "TYPE : UnaryExpression of " << type << std::endl;
}

std::string IdentifierExpression::getType() const{
	return "Identifier";
}

void IdentifierExpression::printer() const{
	std::cout << "TYPE: IdentifierExpression with identifier of " << id << std::endl;
}

std::string IdentifierExpression::getName() const{
	return id;
}

std::string ConstantExpression::getType() const{
	return "Constant";
}

int ConstantExpression::getConstant() const{
	return num;
}

void ConstantExpression::printer() const{
	std::cout << "TYPE : ConstantExpression with constant of " << num << std::endl;
}

std::string BracketExpression::getType() const{
	return "Bracket";
}

void BracketExpression::printer() const{
	std::cout << "Brackets around ( expression ) with expression type = " << exp1->getType() << std::endl;
}

/*
const Expression* exp1 = $$;
bool test_case = false;

while(!test_case){
std::string type = exp1->getType();
if(type == "Constant"){
  int x = exp1->getConstant();
  std::cout << "valuable X ----- " << x << std::endl;
  test_case = true;
}
else if(type == "Identifier"){
  std::string str1 = exp1->getName();
  std::cout << "valuable str1 " << str1 << std::endl;
  test_case = true;
}
else if(type != "+"){
  exp1 = exp1->getNext();
}
else{
  exp1 = exp1->getLeft();
}*/


// get left value and get right value - tree traversal
/*int BinaryExpression::getSum(Expression* root,mipsRegisters &mips) const{
	if(root != NULL && root->getType == "+"){
		getSum(root->getLeft());
		// doSomething
		if(root->getType() == "Constant"){
			mips[5] += root->getConstant();
		}
		else if(root->getType() == "Identifier"){
			int reg = mips->registerLookup(root->getName());
			if(reg == -1){
				std::cout << "identifier not previously declared" << std::endl;
				return -1;
			}
			else{
				mips[5] += mips[reg].value;
			}
		}
		getSum(root->getRight());
	}
	else{
		getSum()
	}
	bool fin = false;
	int summation = 0;
	while(!fin){
		if(type == "Constant"){
			summation 
		}
	}
}*/



// CodeGen for operations +-*/


// Post Order Tree Traversal for summing up all values of the RHS, eg: int x = 3 +2, this function returns 5!
// Run once for left nodes, another time for right nodes



void codeGen(const int &registerName,mipsRegisters mips){
	std::stringstream ss;
	int x = registerName - 8;
	ss << x;
	std::string name = "$t" + ss.str();
	Register r1 = mips.getValue(registerName);
	std::cout << "move " << name << "," << r1.value << std::endl;
	ss.str("");
}


void ShuntingYardAlgo(std::vector<Expression*> &completeTree,std::stack<int> &mystack,const bool &debugMode,mipsRegisters &mips32){
	/* Shunting-yard algorithm */
	if(debugMode){
	  std::cout << "int a = 3 + 2...init" << std::endl; 
	}

	for(int i=0;i<completeTree.size();i++){
	  if(completeTree[i]->getType() == "Binary" || completeTree[i]->getType() == "Identifier" || completeTree[i]->getType() == "Constant"){
	    if(debugMode){
	      completeTree[i]->printer();
	    }
	    if(completeTree[i]->getType() == "Constant"){
	      mystack.push(completeTree[i]->getConstant());
	    }
	    else if(completeTree[i]->getType() == "Identifier"){
	      // logic to handle identifier conversion
	      int y = mips32.registerLookup(completeTree[i]->getName());
	      Register r = mips32.getValue(y);
	      mystack.push(r.value);
	    }
	    else if(completeTree[i]->getType() == "Binary"){
	      std::string strOp = completeTree[i]->getOperator();
	      int temp_x = mystack.top();
	      mystack.pop(); 
	      int temp_y = mystack.top();
	      mystack.pop();
	      int sum = 0;
	      if(strOp == "+"){
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
	      mystack.push(sum);
	    }
	  }
	}
	int ans = mystack.top();
	int v = mips32.registerLookup($1);
	mips32.Bind(ans,v,$1);
	completeTree.clear();
	codeGen(v,mips32);
	mystack.pop();
	if(debugMode){
	  mips32.printAllRegisters();
	}

}



// Statement Handlers














// MIPS Registers Handlers

Register mipsRegisters::getValue(const int &registerName){
	return registers[registerName];
}

void mipsRegisters::Bind(const int &val,const int &registerName,const std::string &var){
	registers[registerName].value = val;
	registers[registerName].varName = var;
	registers[registerName].inUse = true;
}

int mipsRegisters::registerLookup(const std::string &varName){
	for(int i=0;i<registers.size();i++){
		if(registers[i].varName == varName){
			return i;
		}
	}
	return -1;
}

void mipsRegisters::clearRegisters(){
	registers.clear();
	registers.resize(31);
}

void mipsRegisters::printAllRegisters(){
	for(int i=0;i<registers.size();i++){
		std::cout << "REGISTER : " << i << " - " << registers[i].varName << " - " << registers[i].value << std::endl;
	}
}

int mipsRegisters::findEmptyRegister(){
	for(int i=8;i<16;i++){
		if(!registers[i].inUse){
			return i;
		}
	}
	return -1;
}