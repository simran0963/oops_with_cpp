//stacks using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void enqueue(struct node **front,struct node **rear){
	int num;
	struct node *obj=(struct node *)malloc(sizeof(struct node));
	if(obj!=NULL){
		printf("Enter data : ");
		scanf("%d",&obj->data);
		obj->next=NULL;
	}
	if(*rear==NULL){
		*rear=obj;
		*front=obj;
	}
	else{
		(*rear)->next=obj;
		(*rear)=obj;
	}
}

struct node *dequeue(struct node **front,struct node **rear){
	struct node *ptr=*front;
	if(*front==*rear){
		printf("Popped value : %d",ptr->data);
		(*front)=(*rear)=NULL;
		return;
	}
	else if(front!=NULL){
		printf("Popped value : %d",(*front)->data);
		*front=(*front)->next;
		ptr=NULL;
		free(ptr);
	}
	else{
		printf("Underflow");
		return;
	}
}

void display(struct node *front,struct node *rear){
    if(front==NULL){
		printf("Underflow");
	}
	else{
		while(front!=NULL){
			printf("%d",front->data);
			//dequeue(front);
			front=front->next;
		}
	}
}


int main(){
	struct node *front=NULL, *rear=NULL;
	int ch;
	while(1){
		printf("\n1. Enqueue     2. Dequeue     3. Print     4. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				enqueue(&front,&rear);
				//display(front);
				break;
					
			case 2:
				if(front==NULL){
					printf("Empty");
					break;
				}
				dequeue(&front,&rear);
				//display(front);
				break;	
			
			case 3:
				display(front,rear);
				break;	
				
			case 4:
				exit(0);
			
			default:
				printf("Invalid");
				exit(0);
		}		
		
	}
	return 0;
}

