// WAP to sort the stack elements with  recursive 
#include<stdio.h>
#include<stdlib.h>
#define max 6

int push(int arr[], int top)
{
	printf("Enter the value : ");
	scanf("%d",&arr[++top]);
	return top;
}

int pop(int arr[], int top)
{
	return --top;
}

void display(int arr[], int top)
{
	for(top=top;top>=0;top--){
		printf("%d\t",arr[top]);
	}
}

int main()
{
	int arr[max], ch, top=-1;
	while(1)
	{
		printf("\n\n\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			if(top>=max-1){
				printf("Stack Overflow.");
				return 0;
			}
			else{
				top=push(arr,top);
				printf("\n");
				display(arr,top);
			}
			break;

			case 2:
			if(top==-1){
				printf("Stack Underflow.");
				return 0;
			}
			top=pop(arr, top);
			display(arr,top);
			break;

			case 3:
			display(arr, top);
			break;

			case 4:
			exit(0);

			default:
			printf("Invalid input");
			exit(0);
		}
	}
	return 0;
}