#include<stdio.h>
#include<stdlib.h>
struct node{
	   int data;
	   struct node *next;
};

void push(struct node *head){
	struct node *ptr=head;
	if(head==NULL){
        head=ptr=(struct node*)malloc(sizeof(struct node));
		printf("List Underflow");
	}
	else{
		 ptr->next=(struct node*)malloc(sizeof(struct node));
		 ptr=ptr->next;	 
    }
    printf("Enter the data : ");
    scanf("%d",&ptr->next);
    ptr->next=NULL;
}

void pop(struct node *head){
	struct node *ptr=head->next;
	for(ptr=head;ptr->next!=NULL;ptr=ptr->next){
	    head=head->next;
	}
	free(ptr);
	head->next=NULL;
	}

void display(struct node *head){
	 if(head==NULL)return ;
	 printf("%d\t",head->data);
	 display(head->next);
}

int middle(struct node *head, int num){
	int ind=num/2,i;
	for(i=0;i!=ind;i++){
	    head=head->next;
	}
	return head->data;
}

int main(){
	struct node *head=NULL;
	int ch,i=0;
	while(1){
		printf("\n1. Push\n2. Pop \n3. Middle\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\n");
        i++;
        push(head);
        display(head);
        break;
        
        case 2:
        printf("\n");
        pop(head);
        display(head);
        break;
        
        case 3:
        printf("\n");
        middle(head,i);
        break;
        
        case 4:
        exit(0);
        
        default:
        printf("Wrong choice");
    }		
	}
}	
