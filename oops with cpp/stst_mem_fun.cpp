#include<iostream>
using namespace std;

class Base{
	public:
	int x;
	static int y;
	void printx(){
		cout<<x<<","<<y;
	}
	static void printy(){
		cout<<y;	
	}
	
};

int Base::y;

int main(){
	Base b1;
	b1.x=30;
	b1.y=40;
	Base b2;
	b2.x=60;
	Base::y=70;	
	b1.printx();
	b1.printy();
	b2.printx();
	b2.printy();
}