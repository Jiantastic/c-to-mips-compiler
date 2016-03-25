#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main() {
	// your code goes here
	auto a = "nameee";
	auto aaa = 33;
	string b = typeid(a).name(); 
	cout << b << endl;
	cout << "aaa = " << typeid(aaa).name() << endl;
	return 0;
}
