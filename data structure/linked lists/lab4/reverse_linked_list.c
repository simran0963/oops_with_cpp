#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};

void print(struct node *head)
{
	if(head==NULL)return;
	printf("\ndata : %d",head->data);
	print(head->next);
}

struct node *reverse(struct node *head)
{
	struct node *p,*c,*n;
	p=NULL;
	c=head;
	n=c->next;
	while(c!=NULL)
	{
		c->next=p;
		p=c;
		c=n;
		if(n!=NULL)
		n=n->next;
	}
	return p;
}

int main()
{
	struct node *head=NULL, *ptr=NULL;
	int i, n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=ptr=(struct node*)malloc(sizeof(struct node));
		}
		else
		{
			ptr->next=(struct node*)malloc(sizeof(struct node));
			ptr=ptr->next;
		}
		printf("Node [%d] : ",i);
		scanf("%d",&ptr->data);
	}
	ptr->next=NULL;
	print(head);
	head=reverse(head);
	printf("\nReverse\n");
	print(head);
	return 0;
}