#include<iostream>
using namespace std;

class A;
class B{
	int b;
	public:
	void getval(int x){
		b=x;
	}
	void putval(void){
		cout<<b<<endl;
	}
	friend void add(A,B);
};

class A{
	int a;
	public:
	void getval(int x){
		a=x;
	}
	void putval(void){
		cout<<a<<endl;
	}
	friend void add(A,B);
};
void add(A a1, B b1){
	cout<<"Addition using friend : "<<a1.a+b1.b<<endl;
}

int main(){
	A a1;
	B b1;
	a1.getval(100);
	b1.getval(200);
	a1.putval();
	b1.putval();
	add(a1,b1);
}