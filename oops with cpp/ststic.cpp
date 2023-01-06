#include<iostream>
using namespace std;

class base{
	public:
	int x;
	static int y;
};

int base::y;

int main(){
	base b1, b2;
	b1.x=10;
	b1.y=20;
	b2.x=30;
	b2.y=40;
	cout<<"b1.x"<<b1.x<<"b1.y"<<b1.y<<endl;
	cout<<"b2.x"<<b2.x<<"b2.y"<<b2.y<<endl;
}