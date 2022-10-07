//Stack using doubly linked list Implementation of push(), pop() and display() functions 

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *push(struct node *top);
struct node *pop(struct node *top);
void display(struct node *top);

int main()
{
    struct node *top=NULL;
    int ch;
    while(1){
    printf("\n1. Push\n2. Pop \n3. Display 4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n");
			top = push(top);
			display(top);
			break;
			
			case 2:
			printf("\n");
			top = pop(top);
			display(top);
			break;
			
			case 3:
			printf("\n");
			display(top);
			break;
			
			case 4:
			exit(0);
			
			default:
			printf("Wrong choice");
		}
	}
}

struct node *push(struct node *top)
{
    struct node *newobj=NULL, *temp=NULL;
	int num;
    newobj=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number : ");
	scanf("%d",&num);
	if(newobj==NULL)
	{
		printf("\nOverflow");
	}
    else
    {
		newobj->data = num;
		newobj->prev=NULL;
		newobj->next = top;
		if(top!=NULL)
		{
			top->prev=newobj;
		}
		top = newobj;
		return top;
    }
}

struct node *pop(struct node *top)
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {  
        printf("Underflow");
    }
    else
    {
        top=top->next;
        free(temp);
    }
    return top;
}

void display(struct node *top)
{
	// while(top!=NULL)
	// {
	// 	printf("\nData : %d",top->data);
	// 	top=top->next;
	// }
    if(top==NULL)return;
    printf("\nData : %d",top->data);
    display(top->next); 
}
