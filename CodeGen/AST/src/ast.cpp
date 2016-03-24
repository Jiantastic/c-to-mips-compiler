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



void codeGen(const int &registerName,mipsRegisters mips,const std::string &order = ""){

	if(order == "return"){
		Register r1 = mips.getValue(registerName);
		std::cout << "      li $t9," << r1.value << std::endl;
		std::cout << "      move $v0,$t9" << std::endl;
	}
	else{
		int x = 0;
		std::stringstream ss;
		std::string name;
		if(registerName >= 8 && registerName <= 15){
			x = registerName - 8;
		}
		else if(registerName >= 16 && registerName <= 27){
			x = registerName - 16;
		}
		ss << x;
		name = "$t" + ss.str();
		Register r1 = mips.getValue(registerName);
		std::cout << "      li " << name << "," << r1.value << std::endl;
		ss.str("");		
	}

}


void ShuntingYardAlgo(std::vector<Expression*> &completeTree,std::stack<int> &mystack,const bool &debugMode,mipsRegisters &mips32,maps &maps1,std::string declarator="",std::string assignOp=""){
	/* Shunting-yard algorithm */
	if(debugMode){
	  std::cout << "int a = 3 + 2...init" << std::endl; 
	}


	for(int i=0;i<completeTree.size();i++){
			if(completeTree[i]->getType() == "NoParams"){
		std::cout << "GET REKT MATE" << std::endl;
		return;
	}
	  if(completeTree[i]->getType() == "Binary" || completeTree[i]->getType() == "Identifier" || completeTree[i]->getType() == "Constant"){
	    if(debugMode){
	      completeTree[i]->printer();
	    }
	    if(completeTree[i]->getType() == "Constant"){
	      mystack.push(completeTree[i]->getConstant());
	    }
	    else if(completeTree[i]->getType() == "Identifier"){
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



// Statement Handlers






// Assignment Operators

std::string AssignmentOperator::getType(){
	return assignment;
}









// PostfixExpression Handlers

/*void PostfixExpression::loadParams(std::vector<const Expression*> core_vector,mipsRegisters &mips,maps &map1){
	std::vector<int> vec1;
	std::cout << "ONE SMALL STEP FOR A PERSON!" << std::endl;
	bool finished;
	for(int i=0;i<core_vector.size();i++){
		finished = false;
		const Expression* exp_handler = core_vector[i];
		while(!finished){
			if(exp_handler->getType() == "Identifier"){
				// handle identifiers
				int v = mips.registerLookup(exp_handler->getName());
				if(v == -1){
					// look at map_stack to get value
					v = map1.getValue(exp_handler->getName());
					if(v == -1){
						std::cout << "cannot find identifier" << std::endl;
						exit(EXIT_FAILURE);
					}
					vec1.push_back(v);
				}
				else{
					Register r = mips.getValue(v);
					vec1.push_back(r.value);
				}
				finished = true;
			}
			else if(exp_handler->getType() == "Constant"){
				// handle constants
				vec1.push_back(exp_handler->getConstant());
				finished = true;
			}
			else if(exp_handler->getType() == "Unary"){
				exp_handler = exp_handler->getNext();
			}
			// No "Binary" handler, cannot handle f(3+3);
		}
	}

	for(int i=0;i<vec1.size();i++){
		mips.Bind(vec1[i],i+4,"",map1);
		std::cout << "		li 		$" << i+4 << "," << vec1[i] << std::endl;
	}
}*/

std::string PostfixExpression::getFunctionName(const Expression* exp1) const{
	// pretty straightforward for identifiers, exp1->getNext()->getName();
	return exp1->getNext()->getName();
}

void PostfixExpression::codeGen(const Expression* exp1) const{
	std::cout << "		addiu 		$sp,$sp,-4" << std::endl;
	std::cout << "		sw 		$31,0($sp)" << std::endl;
	std::cout << "		jal " << getFunctionName(exp1) << std::endl;
	std::cout << "		nop" << std::endl;
}

std::string PostfixExpression::getType(){
	return type;
}


// MIPS Registers Handlers

Register mipsRegisters::getValue(const int &registerName){
	return registers[registerName];
}

void mipsRegisters::Bind(const int &val,const int &registerName,const std::string &var,maps &map1){
	if(registerName == 0){
		// in MIPS, $0 is always 0 
		return;
	}
	registers[registerName].value = val;
	registers[registerName].varName = var;
	registers[registerName].inUse = true;

	// map_stack, bind to map_stack as well
	map1.Insert(var,val);
}

int mipsRegisters::registerLookup(const std::string &varName){
	for(int i=0;i<registers.size();i++){
		if(registers[i].varName == varName){
			return i;
		}
	}
	// if not in here, check in stack and place it in register
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
	for(int i=8;i<24;i++){
		if(!registers[i].inUse){
			return i;
		}
	}
	//map_stack
	// if not in here, check in stack

	return -1;
}

void mipsRegisters::clearTempRegisters(){
	for(int i=8;i<24;i++){
		registers[i].varName = "";
		registers[i].value = 0;
		registers[i].inUse = false;
	}
}



// map_stack implementation

void maps::Insert(const std::string &str1,const int &r1){
	map_stack[str1] = r1;
}


int maps::getValue(std::string iden){
	std::map<std::string,int>::iterator it;
	for(it=map_stack.begin();it!=map_stack.end();it++){
		if(it->first == iden){
			return it->second;
		}
	}
	// if we cannot find the variable in both the register and the map_stack, that means that the variable has not been declared, we return -1 to indicate that
	return -1;
}


// executed before every new function call
void maps::getNew(mipsRegisters &mips){
	stacking.push(map_stack);
	mips.clearTempRegisters();
	// generate MIPS assembly Code that iterates the entire map and li $... if necessary
	map_stack.clear();
}

// executed after every function calls ends
void maps::getOld(){
	map_stack.clear();
	if(!stacking.empty()){
		map_stack = stacking.top();
		// no need to restore registers from stack to registers, my function will automatically look at stack if it can't find it in registers
		// generate MIPS assembly Code that iterates the entire map and li $... if necessary
		stacking.pop();
	}

}

void maps::printer(){
	std::map<std::string,int>::iterator it;
	std::cout << "inside maps printer" << std::endl;
	for(it = map_stack.begin();it != map_stack.end();it++){
		std::string str1 = it->first;
		int x = it->second;
		std::cout << "IDENTIFIER : " << str1 << " , VALUE: " << x << std::endl;
	}
}

