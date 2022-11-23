#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	// Constant
//	cout<<"a was : "<<a<<endl;
//	const a=44;
//	cout<<"a is : "<<a<<endl;
	// manipulators: 
	int a=3, b=8, c=23;
	cout<<"The value of a without setw is : "<<a<<endl;
	cout<<"The value of b without setw is : "<<b<<endl;
	cout<<"The value of c without setw is : "<<c<<endl;
	
	cout<<"The value of a is : "<<setw(4)<<a<<endl;
	cout<<"The value of b is : "<<setw(4)<<b<<endl;
	cout<<"The value of c is : "<<setw(4)<<c<<endl;
	return 0;
}
