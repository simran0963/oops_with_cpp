#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *push(struct node *head);
void display(struct node *head);
void pull(struct node *head);

int main(){
	struct node *head=NULL;
	int ch;
	while(1){
		printf("\n1. Taking input \n2. Deleting\n 3. Printing\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			head = push(head);
			display(head);
			break;

			case 2:
			pull(head);
			break;

			case 3:
			display(head);
			break;

			default:
			exit(0);
		}
	}
}

struct node *push(struct node *head)
{
	int num;
	struct node *ptr=head;
	if(head==NULL){
		head=ptr=(struct node*)malloc(sizeof(struct node));
	}
	else{
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=(struct node*)malloc(sizeof(struct node));
		ptr=ptr->next;
	}
	ptr->next=NULL;
	printf("Enter the data: ");
	scanf("%d",&num);
	ptr->data=num;
	return head;
}

void pull(struct node *head)
{
	return;
}

void display(struct node *head)
{
	if(head==NULL)
	{
		printf("\nList underflow.\n");
		return;
	}
	printf("data : %d\t",head->data);
	display(head->next);
}