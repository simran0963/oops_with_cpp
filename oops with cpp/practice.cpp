#include<iostream>
using namespace std;

class student{
	public:
		string name;
		int age;
		bool gender;
	void display(){
		cout<<"Name : "<<name<<"\tage : "<<age<<"\tGender : "<<gender<<endl;
	}
};

int main(){
	student arr[3];
	for(int i=0;i<3;i++){
		cin>>arr[i].name>>arr[i].age>>arr[i].gender;
	}
	
	for(int i=0;i<3;i++){
		arr[i].display();
	}
	return 0;
}