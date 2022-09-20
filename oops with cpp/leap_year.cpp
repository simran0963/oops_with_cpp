#include<iostream>
using namespace std;
int main()
{
	int year;
	cout<<"Enter the year to be checked: "<<endl;
	cin>>year;
	
	if(year%400==0)
	{
		cout<<"LEAP YEAR"<<endl;
	}
	else if(year%100==0)
	{
		cout<<"Not a leap year"<<endl;
	}
	else if(year%4==0)
	{
		cout<<"LEAP YEAR"<<endl;
	}
}