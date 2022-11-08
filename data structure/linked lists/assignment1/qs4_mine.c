#include<stdio.h>
#include<stdlib.h>
#define max 5
int arr[max],top=-1;

int peek();
void push(int num);
int pop();
void display();
void sort(int arr[]);
void order(int arr[],int temp);

int isEmpty(){
	if(top==-1)
		return 1;
	else
		return 0;
}

int peek(){
	if(isEmpty()){
		printf("Stack Underflow");
		exit(1);
	}
	int temp=arr[top];
	return temp;
}

void push(int num){
	if(top==max-1){
		printf("Stack Overflow");
		exit(1);
	}
	arr[++top]=num;
}

int pop(){
	if(top==-1){
		printf("Stack Underflow");
		exit(1);
	}
	int temp = arr[top];
	top--;
	return temp;
}

void order(int arr[],int temp){
	if(isEmpty() || peek()>temp){
		push(temp);
		return;;
	}
	int ele=pop();
	order(arr,temp);
	push(ele);
}

void sort(int arr[]){
	if(isEmpty()){
		return;
	}
	int temp=pop();
	sort(arr);
	order(arr,temp);
}

void display(){
	if(top==-1){
		printf("Stack Underflow");
		return;
	}
	for(int i=0;i>=0;i--){
		printf("%d\t",arr[top]);
	}	
}

int main()
{
	push(8);
	push(2);
	push(54);
	push(-7);
	push(8);
	sort(arr);
	display();
}