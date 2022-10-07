#include<stdio.h>
#include<stdlib.h>

struct node *enqueue(struct node *rear, int num);
struct node *dequeue(struct node *front);
void display(struct node *rear, struct node *front, int num);

struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};

int main()
{
	int ch, num;
	struct node *front=NULL, *rear=NULL;
	while(1){
    printf("\n1. Enqueue\n2. Dequeue \n3. Display \n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n");
			printf("Enter the value: ");
			scanf("%d",&num);
			rear = enqueue(rear,num);
			display(rear, num, front);
			break;
			
			case 2:
			printf("\n");
			front=dequeue(front);
			if(front!=NULL)
			{
				rear=NULL;
			}
			display(rear, front, num);
			break;
			
			case 3:
			printf("\n");
			display(rear, front, num);
			break;
			
			case 4:
			exit(0);
			
			default:
			printf("Wrong choice");
		}
	}
}

struct node *enqueue(struct node *rear, int num)
{
	struct node *newobj=(struct node*)malloc(sizeof(struct node));
	newobj->next=newobj->prev=NULL;
	if(newobj!=NULL)
	{
		newobj->prev=rear;
		rear=newobj;
	}
	else{
		printf("Overflow");
	}
	return rear;
}

struct node *dequeue(struct node *front)
{
	if(front==NULL)
	{
		printf("Underflow");
	}
	struct node *temp=front;
	front=front->next;
	free(temp);
	if(front!=NULL)
	{
		front->prev=NULL;
	}
	return front;
}