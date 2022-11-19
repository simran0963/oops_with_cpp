//stacks using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *push(struct node *top){
	struct node *obj=NULL;
	int num;
	obj=(struct node *)malloc(sizeof(struct node));
	if(obj==NULL){
		printf("Stack Overflow");
	}
	else{
		obj->next=top;
		printf("Enter data : ");
		scanf("%d",&num);
		obj->data=num;
		top=obj;
	}
	return top;
}

struct node *pop(struct node *top){
	struct node *ptr=NULL;
	if(top==NULL){
		printf("Stack Underflow");
	}
	else{
		ptr=top;
		top=top->next;
		ptr=NULL;
		free(ptr);
	}
	return top;
}

void display(struct node *top){
    struct node *ptr=top;
    if(ptr==NULL){
		printf("Underflow");
	}
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

struct node *reverse(struct node *head){
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
}

int main(){
	struct node *top=NULL;
	int ch;
	while(1){
		printf("\n1. Push     2. Pop     3. Reverse     4. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				top=push(top);
				display(top);
				break;
					
			case 2:
				top=pop(top);
				display(top);
				break;	
			
			case 3:
				top = reverse(top);
				display(top);
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

