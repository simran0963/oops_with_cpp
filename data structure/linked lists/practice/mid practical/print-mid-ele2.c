#include<stdio.h>
#include<stdlib.h>
struct node{
	   int data;
	   struct node *next;
};

struct node *push(struct node *head){
	struct node *ptr=head;
	int num;
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
    printf("Enter the data : ");
    scanf("%d",&num);
    ptr->data=num;
    ptr->next=NULL;
    return head;
}

void *pop(struct node *head){
	struct node *head1=head, *ptr=head->next;
	for(ptr=head1;ptr->next!=NULL;ptr=ptr->next){
	    head1=head1->next;
	}
	free(ptr);
	head1->next=NULL;
	}

void display(struct node *head){
	 if(head==NULL)return ;
	 while(head!=NULL){
	    printf("%d\t",head->data);
	    head=head->next;
	 }
}

void middle(struct node *head, int num){
	int ind=num/2,i;
	for(i=0;i!=ind;i++){
	    head=head->next;
	}
	printf("Middle element: %d",head->data);
}

int main(){
	struct node *head=NULL;
	int ch,i=0,mid;
	while(1){
		printf("\n1. Push\n2. Pop \n3. Middle\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\n");
        i++;
        head=push(head);
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
        exit(0);
        
        case 4:
        exit(0);
        
        default:
        printf("Wrong choice");
    }		
	}
	return 0;
}	
