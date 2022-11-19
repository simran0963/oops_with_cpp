//stacks using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *enqueue(struct node *rear){
	int num;
	struct node *obj=NULL;
	obj=(struct node *)malloc(sizeof(struct node));
	if(obj!=NULL){
		printf("Enter data : ");
		scanf("%d",&obj->data);
		rear->next=obj;
		obj->next=NULL;
		rear=obj;
	}
	else{
		printf("Overflow");
	}
	return rear;
}

struct node *dequeue(struct node *front){
	struct node *ptr=NULL;
	if(front!=NULL){
		ptr=front;
		front=front->next;
		ptr=NULL;
		free(ptr);
	}
	else{
		printf("Underflow");
	}
		return front;
}

void display(struct node *front){
    if(front==NULL){
		printf("Underflow");
	}
	else{
		while(front->next!=NULL){
			printf("%d",front->data);
			dequeue(front);
			front=front->next;
		}
	}
}

/*struct node *reverse(struct node *head){
	struct node *p,*c,*n;
	p=NULL;
	c=head;
	n=c->next;
	while(c!=NULL){
		c->next=p;
		p=c;
		c=n;
		if(n!=NULL){
			n=n->next;
		}
	}
	return p;
}*/

int main(){
	struct node *front=NULL, *rear=NULL;
	int ch;
	while(1){
		printf("\n1. Enqueue     2. Dequeue     3. Print     4. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				rear=enqueue(rear);
				//display(front);
				break;
					
			case 2:
				front=dequeue(front);
				if(front==NULL){
					rear=NULL;
				}
				//display(front);
				break;	
			
			case 3:
				display(front);
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

