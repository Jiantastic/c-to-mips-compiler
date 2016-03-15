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
void Traversal(Expression* root, int &sum,int &leftTemp, int &rightTemp,mipsRegisters mips){
	if(root != NULL){
		std::vector<int> vec1;
		if(root->getType() == "Unary"){
			Traversal(root->getNext());
		}
		else if(root->getType() == "Constant"){
			vec1.push_back(root->getConstant());
		}
		else if(root->getType() == "Identifier"){
			int register_num = mips.registerLookup(root->getName());
			Register r1 = mips.getValue(register_num);
			vec1.push_back(r1.value);
		}
		else if(root->getType() == "Binary"){
			Traversal(root->left);
			Traversal(root->right);
			if(root->getType() == "Binary"){
				if(root->left != NULL && root->right != NULL){
					std::string op = root->getOperator();
					if(op == "+"){
						leftTemp = vec1[0] + vec1[1];
					}
					else if(op == "-"){
						leftTemp = vec1[0] - vec1[1];
					}
					else if(op == "*"){
						leftTemp = vec1[0] * vec1[1];
					}
					else if(op == "/"){
						leftTemp = vec1[0] / vec1[1];
					}
					return leftTemp;
				}
				/* makes no sense where left is not null and right is null - will occur under no circumstances
				else if(root->left != NULL && root->right == NULL){
					if(op == "+"){
						sum += vec1[0];
					}
					else if(op == "-"){
						sum += vec1[0];
					}
					else if(op == "*"){
						sum += vec1[0];
					}
					else if(op == "/"){
						sum += vec1[0];
					}
				}*/
			}	
		}

		vec1.clear();
	}
}


void codeGen(const int &registerName,mipsRegisters mips){
	std::stringstream ss;
	int x = registerName - 8;
	ss << x;
	std::string name = "$t" + ss.str();
	Register r1 = mips.getValue(registerName);
	std::cout << "move " << name << "," << r1.value << std::endl;
	ss.str("");
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