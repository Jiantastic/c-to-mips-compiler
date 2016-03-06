#include <iostream>
#include <string>

using namespace std;

class testone{
public:
	const  getStatement(){
		cout << "getting statement..." << endl;
	}
};

class test2 : public testone{
public:
	testone getStatement() const{
		cout << "removing statement!" << endl;
	}
};

int main(){
	test2 testtwo;
	testtwo.getStatement();
	return 0;
}
