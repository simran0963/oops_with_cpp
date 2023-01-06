#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *nxt;
};

void print(struct node *head){
	struct node *prnt = head;	
	while(prnt!=NULL){
		printf("%d \t",prnt->data);
		prnt=prnt->nxt;
	}
}

struct node *pos(struct node *head){
	struct node *p = NULL, *ptr = NULL;

	while(head != NULL){
		if(head->data >= 0){
			if(p == NULL)
				ptr =  p =  (struct node*)malloc(sizeof(struct node));
			else{
				p->nxt = (struct node*)malloc(sizeof(struct node));
				p=p->nxt;
			} 
			p->data = head->data;
		
		}
		head = head->nxt;
	}
	p->nxt= NULL;
	return ptr;
}

struct node *neg(struct node *head){
	struct node *p = NULL, *ptr = NULL;

	while(head != NULL){
		if(head->data < 0){
			if(p == NULL)
				ptr =  p =  (struct node*)malloc(sizeof(struct node));
			else{
				p->nxt = (struct node*)malloc(sizeof(struct node));
				p=p->nxt;
			} 
			p->data = head->data;
		
		}
		head = head->nxt;
	}
	p->nxt= NULL;
	return ptr;
}

int main(){
	int n,i;
	struct node *head = NULL, *temp = NULL, *pve = NULL, *nve = NULL;

	printf("Enter the limit of list : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head = temp = (struct node*)malloc(sizeof(struct node));
		}
		else 
		{
			temp->nxt = (struct node*)malloc(sizeof(struct node));
			temp = temp->nxt;
		}
		printf("Element : ");
		scanf("%d",&temp->data);
	
	}	
	temp->nxt = NULL;
	
	printf("\n\nEntred data :\n");
	print(head);
	
	pve = pos(head); 
	printf("\n\nPositive data :\n");
	print(pve);	
	
	nve = neg(head); 
	printf("\n\nNegitive data :\n");
	print(nve);
	
	return 0;
}

