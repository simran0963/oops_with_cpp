#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int co,ex;
	char var;
	struct node *nxt;
};

struct node *input(int n,char c){
	int i,z=n;
	struct node *p = NULL,*temp = NULL;
	for(i=0;i<=n;i++){
		
		if(p == NULL)
		{
			p = temp = (struct node*)malloc(sizeof(struct node));
		}
		else 
		{
			temp->nxt = (struct node*)malloc(sizeof(struct node));
			temp = temp->nxt;
		}
		temp->var = c;
		temp->ex = z;
		printf("Coefficient of %c^%d : ",temp->var,temp->ex);
		scanf("%d",&temp->co);
		z--;	 
	}
	temp->nxt = NULL;
	return p;
}

struct node *sum(struct node *a,struct node *b,char c,int n){
	int i;	
	struct node *p = NULL,*temp = NULL;
	for(i=0;i<=n;i++){
		
		if(p == NULL)
		{
			p = temp = (struct node*)malloc(sizeof(struct node));
		}
		else 
		{
			temp->nxt = (struct node*)malloc(sizeof(struct node));
			temp = temp->nxt;
		}
		temp->var = c;
		temp->co = a->co + b->co;
		temp->ex = a->ex;
	}
	temp->nxt = NULL;
	return p;
	
}

void disp(struct node *h){
	while(h->nxt != NULL){
		printf("%d%c^%d + ",h->co,h->var,h->ex);
		h = h->nxt;
	}
	printf("%d%c^%d  ",h->co,h->var,h->ex);
}

int main(){
	struct node *p1 = NULL,*p2 = NULL ,*temp = NULL, *res = NULL ;
	int n,i;
	
	printf("Enter the Degree of Polynomial equations : ");
	scanf("%d",&n);

	printf("\nEnter the coefficients of 1 st equation :\n");
	p1 = input(n,'a');
	
	printf("\nEnter the coefficients of 1 st equation :\n");
	p2 = input(n,'b');
	
	printf("\n\n1 st Equation :\n");
	disp(p1);
	printf("\n\n2 nd Equation :\n");
	disp(p2);
	
	res = sum(p1,p2,'r',n);
	printf("\n\nResultant Equation :\n");
	disp(res);
}
