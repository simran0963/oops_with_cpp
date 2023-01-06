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

void split(struct node *p){
	int i = 1;
	struct node *q = NULL, *r = NULL,*qtr = NULL, *rtr = NULL;
	while(p != NULL){
		if(i %2 != 0){
			if(q == NULL)
				qtr =  q =  (struct node*)malloc(sizeof(struct node));
			else{
				qtr->nxt = (struct node*)malloc(sizeof(struct node));
				qtr=qtr->nxt;
			} 
			qtr->data = p->data;
		}
		else{
			if(r == NULL)
				rtr =  r =  (struct node*)malloc(sizeof(struct node));
			else{
				rtr->nxt = (struct node*)malloc(sizeof(struct node));
				rtr=rtr->nxt;
			} 
			rtr->data = p->data;
		}
		i++;
		p=p->nxt;
	}
	rtr->nxt = NULL;
	qtr->nxt = NULL;
	printf("\nElements at Odd Position : \n");
	print(q);
	printf("\nElements at Even Position : \n");
	print(r);
}

int main(){
	int n,i;
	struct node *p = NULL, *temp = NULL, *pve = NULL, *nve = NULL;

	printf("Enter the limit of list : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		if(p==NULL)
		{
			p = temp = (struct node*)malloc(sizeof(struct node));
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
	print(p);
	
	split(p);
	return 0;
}