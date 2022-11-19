#include<iostream>
using namespace std;

class Base{
	int a;
	int b;
	public:

	void operator ++(){
		a--;
	}
	void operator +(int n){
		a-b;
	}
	void show(){
		cout<<"a="<<a<<endl;
	}
};
int main(){
	Base t;
	int t1=3,t2=4,t3;
	t1++;
	t.show();
	t3=t1+t2;
	cout<<t3;
}