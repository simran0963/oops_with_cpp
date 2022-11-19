// Tower of Hanoi
#include<stdio.h>

void towerOfHanoi(int n, char A, char C, char B){
	if(n==1){
		C=A;
		return;
	}
	towerOfHanoi(n-1,A,B,C);
	printf("\n%c to %c",A,C);
	towerOfHanoi(n-1,B,C,A);
}

int main(){
	int n=5;
	towerOfHanoi(n,'A','C','B');
}
