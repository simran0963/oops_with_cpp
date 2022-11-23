#include<iostream>
using namespace std;

int main(){
	int age;
	cout<<"Tell me your age : "<<endl;
	cin>>age;
//	if(age<18){
//		cout<<"You can not come to my party "<<endl;
//	}
//	else if(age==18){
//		cout<<"You will get a kids pass to the party : "<<endl;
//	}
//	else if(age<1){
//		cout<<"You are not yet born."<<endl;
//	}
//	else{
//		cout<<"You are invited"<<endl;
//	}
	switch(age){
		case 18:
			cout<<"You are 18"<<endl;
			break;
			
		case 22:
			cout<<"You are 22"<<endl;
			break;
		
		case 2:
			cout<<"You are 2"<<endl;
			break;
		default:
			cout<<"No special case"<<endl;
	}
	
	
	return 0;
}
