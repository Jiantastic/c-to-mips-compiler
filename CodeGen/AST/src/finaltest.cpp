#include <iostream>
#include <vector>

using namespace std;

struct wow{
	int x;
	int y;
	int z;
};

int main(){
	vector<wow> vec1;
	wow wow1;
	wow1.x = 3;
	wow1.y = 4;
	wow1.z = 5;
	vec1.push_back(wow1);
	for(int i=0;i<vec1.size();i++){
		cout << vec1[i].x << endl;
	}
	return 0;
}