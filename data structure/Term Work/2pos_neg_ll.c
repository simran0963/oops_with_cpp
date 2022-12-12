// WACP to create two linked lists positive and negative from a original linked list, so that the positive linked list contains all positive elements and negative linked list contains all negative elements. Positive and negative linked lists should use the node of existing original linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *insert(struct node *head){
	struct node *ptr=head;
	if(head==NULL){
		head=ptr=(struct node*)malloc(sizeof(struct node));
	}
	else{
		ptr->next=(struct node*)malloc(sizeof(struct node));
		ptr=ptr->next;
	}
	ptr->next=NULL;
}

int main(){
	struct node *head=NULL, *ptr=NULL, *phead=NULL, *nhead=NULL;
	int ch;
	while(1){
		printf("\nEnter your choice :\n1. Inserting.\n2. Display\n3. Separate lists\n4. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			head=insert(head);
			break;
			
			case 2:
			display(head);
			break;
			
			case 3: 
			phead=positive(head);
			nhead=negative(head);
			default:
			exit(0);
		}
	}
	return 0;
}