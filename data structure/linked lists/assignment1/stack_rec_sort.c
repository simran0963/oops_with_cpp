#include<stdio.h>
#include<stdlib.h>
#define max 5
int arr[max];
int top=-1;

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int seek()
{
	if(isEmpty())
	{
		printf("Stack Underfow.");
		exit(1);
	}
	else
	return arr[top];
}

void push(int n)
{
	if(top==max-1)
	{
		printf("Stack Overflow.");
		exit(1);
	}
	arr[++top]=n;
}

int pop()
{
	int temp;
	if(isEmpty())
	{
		printf("Stack Underflow.");
		exit(1);
	}
	temp=arr[top];
	top--;
	return temp;
}

void display()
{
	if(top==-1)
	{
		printf("Stack Underflow.");
		return;
	}
	for(int i=top;i>=0;i--)
	{
		printf("%d\t",arr[top]);
	}
}

void order(int arr[],int temp)
{
	if(isEmpty() || seek()<temp)
	{
		push(temp);
		return;
	}
	int ele;
	ele=pop();
	order(arr,temp);
	push(ele);
}

void sort(int arr[])
{
	if(isEmpty())
	return;
	int temp=pop();
	sort(arr);
	order(arr,temp);
}

int main()
{
	push(9);
	push(2);
	push(-6);
	push(0);
	sort(arr);
}