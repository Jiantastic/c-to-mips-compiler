#include <iostream>
#include <string>

using namespace std;

auto f(auto x){
	return x;
}

int main(){
	int x = 3;
	auto yy = f(x);
	cout << yy << endl;
	return 0;
}
