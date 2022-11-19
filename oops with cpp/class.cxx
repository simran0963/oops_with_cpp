#include<iostream>
class Base{
	int i;
	int j;
	public:
	int geti(){
		return i;
	}
	int student();
};

int Base :: student(){
	return j;
}


void der(){
	int a;
	
}

int main(){
	Base o;
	int a, b;
	a=o.geti();
	o.student();
}