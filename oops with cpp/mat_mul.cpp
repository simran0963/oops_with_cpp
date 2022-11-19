#include<iostream>
using namespace std;

int main()
{
	int arr[10][10], brr[10][10], res[10][10],m , n, o, p, i, j, k;
	cout<<"Input the order of the first matrix: "<<endl;
	cin>>m>>n;
	cout<<"Input the order of the second matrix: "<<endl;
	cin>>o>>p;
	cout<<"Enter the values of the matrix 1 : "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<"Matrix 1 is: \n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}

	cout<<"Enter the values of the matrix 2 : "<<endl;
	for(i=0;i<o;i++)
	{
		for(j=0;j<p;j++)
		{
			cin>>brr[i][j];
		}
	}
	cout<<"Matrix 2 is: \n";
	for(i=0;i<o;i++)
	{
		for(j=0;j<p;j++)
		{
			cout<<brr[i][j]<<"\t";
		}
		cout<<"\n";
	}

	cout<<"Multiplying the matrices : "<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			res[i][j]=0;
			for(k=0;k<n;k++){
				res[i][j]+=arr[i][k]*brr[k][j];
				cout<<"i="<<i<<"j="<<j<<"k="<<k<<"\t\t"<<res[i][j];
			}
		}
	}

	cout<<"Matrix after multiplication is: "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			cout<<res[i][j]<<"\t";
		}
		cout<<"\n";
	}
}