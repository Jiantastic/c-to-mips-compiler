#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "ast.h"

// Expression Handlers

void Expression::getType(){
	std::cout << "TYPE : Expression top-level node" << std::endl;
}

const Expression* BinaryExpression::getLeft() const{
	return left;
}

std::string BinaryExpression::getOperator() const{
	return opCode;
}

const Expression* BinaryExpression::getRight() const{
	return right;
}


std::string BinaryExpression::getType(){
	return opCode;
}

void BinaryExpression::printer(){
	std::cout << "TYPE: Binary Expression with operation " << getOperator() << std::endl;
}

void BinaryExpression::codeGen(){

}

std::string IdentifierExpression::getType(){
	return "Identifier";
}

void IdentifierExpression::printer(){
	std::cout << "TYPE: IdentifierExpression with identifier of " << id << std::endl;
}

std::string IdentifierExpression::getName(){
	return id;
}

std::string ConstantExpression::getType(){
	return "Constant";
}

int ConstantExpression::getConstant() const{
	return num;
}

void ConstantExpression::printer(){
	std::cout << "TYPE : ConstantExpression with constant of " << num << std::endl;
}



// CodeGen for operations +-*/


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
	for(int i=15;i<23;i++){
		if(!registers[i].inUse){
			return i;
		}
	}
	return -1;
}