//Queue using array
#include<stdio.h>
#include<stdlib.h>
#define max 50

int enqueue(int *arr, int front, int rear);
int dequeue(int *arr, int front, int rear);
int display(int *arr, int front, int rear);

int main()
{
	int ch, arr[max], front=0, rear=-1;
	while(1){
    printf("\n1. Enqueue\n2. Dequeue \n3. Display \n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n");
			rear = enqueue(arr, front, rear);
			display(arr,front,rear);
			break;
			
			case 2:
			printf("\n");
			front=dequeue(arr, front, rear);
			if(front=-1)
			{
				rear=-1;
			}
			display(arr, front, rear);
			break;
			
			case 3:
			printf("\n");
			display(arr, front, rear);
			break;
			
			case 4:
			exit(0);
			
			default:
			printf("Wrong choice");
		}
	}
}

int enqueue(int *arr, int front, int rear)
{
	if(rear==max-1)
	{
		printf("Overflow");
	}
	else{
		printf("Enter the value : ");
		scanf("%d",&arr[++rear]);
	}
	return rear;
}

int dequeue(int *arr, int front, int rear)
{
	if(front==-1)
	{
		printf("Underflow");
	}
	else{
		printf("Data to be deleted : %d",arr[front]);
	}
	if(front==rear)
	{
		front=-1;
	}
	else{
		front++;
	}
	return front;
}

int display(int *arr, int front, int rear)
{
	if(front==-1)
	{
		printf("Underflow");
	}
	else{
		for(int i=front;i<rear;i++){
		printf("data : %d\t",arr[front]);}
	}
}