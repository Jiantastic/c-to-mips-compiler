#include <stdio.h>

int f(int a,int b){
	return a+b;
}

int main(){
	int yy = 0;
	int g = 2;
	yy = f(3 == 3, 3 || 2);
	printf("%d",yy);
	return 0;
} 
