#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;						// Creating Doubly linked list 
	struct node *prev;
};

struct node *insert_begin(struct node *head,int num);
struct node *insert_end(struct node *head,int num);
struct node *insert_after(struct node *head,int pos,int num);
struct node *insert_before(struct node *head,int pos,int num);
void print(struct node *head);

int main(){
	
	int n,i,ch,num,pos;
	struct node *head = NULL,*ptr = NULL,*t = NULL; 
	
	// Accepting linked list
	printf("Enter the Number of Nodes : ");
	scanf("%d",&n);
	
	// Accepting Data in linkdedlist 
	printf("\nEnter Data : \n");
	for(i = 0 ; i<n ; i++){
		if(head == NULL){
			head = ptr = (struct node*)malloc(sizeof(struct node));
			ptr->prev = NULL;
		}
		else{
			ptr->next = (struct node*)malloc(sizeof(struct node));
			t = ptr;
			ptr = ptr->next;
			ptr->prev=t;
		}
		printf("Element : ");
		scanf("%d",&ptr->data);
	}
	ptr->next = NULL;
	
	// Printing the Entered list
	printf("\nEntered Data : \n");
	print(head);
	
	// Menu driven for Inserting at different positions
	printf("\n\nSelect the position to inert : \n1 - Begin");
	printf("\n2 - After any Element\n3 - Before any Element\n4 - End\n\nYour Choice : ");
		scanf("%d",&ch);
		switch (ch){
			
			case 1:
			printf("\nEnter the Number to insert: ");
			scanf("%d",&num);
				head = insert_begin(head,num);
				break;
				
			case 2:
				printf("\nEnter the Number After which you want to insert : ");
				scanf("%d",&pos);
				printf("Enter the Number to insert: ");
				scanf("%d",&num);
				head = insert_after(head,pos,num);
				break;
			
			case 3:
				printf("\nEnter the Number Befotr which you want to insert : ");
				scanf("%d",&pos);
				printf("Enter the Number to insert: ");
				scanf("%d",&num);
				head = insert_before(head,pos,num);
				break;
				
			case 4:
				printf("\nEnter the Number to insert: ");
				scanf("%d",&num);
				head = insert_end(head,num);
				break;
				
			default:
				printf("\nInvalid choice!");
				exit(0);
	}
	
	// Printing New List
	printf("\nNew data : \n");
	print(head);
}


void print(struct node *head){
	if(head == NULL)
		return;
	printf("%d\n",head->data);
	print(head->next);
}

struct node *insert_begin(struct node *head,int num){
	struct node *obj = (struct node*)malloc(sizeof(struct node));
	obj->data = num;
	obj->next = head;
	head = obj;
	return head;
}

struct node *insert_after(struct node *head,int pos,int num){
	struct node *ptr = head, *obj = (struct node*)malloc(sizeof(struct node));
	obj->data = num;
	while(ptr->data != pos){
		ptr = ptr->next;
	}
	obj->next = ptr->next;
	ptr->next = obj;
	return head;
}

struct node *insert_before(struct node *head,int pos,int num){
	struct node *ptr = head, *obj = (struct node*)malloc(sizeof(struct node));
	obj->data = num;
	while(ptr->data != pos){
		ptr = ptr->next;
	}
	obj->next = ptr;
	ptr->prev->next = obj;
	return head;
}

struct node *insert_end(struct node *head,int num){
	struct node *ptr = head, *obj = (struct node*)malloc(sizeof(struct node));
	obj->data = num;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = obj;
	obj->next = NULL;
	return head;
}
