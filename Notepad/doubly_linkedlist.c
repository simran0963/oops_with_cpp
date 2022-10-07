#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *pre;
	int data;
	struct node *next;
};

void print(struct node *head)
{
	if(head==NULL)return;
	if(head->next!=NULL)
	printf("\npre : %d  data : %d  next : %d",head->pre->data,head->data,head->next->data);
	print(head->next);
}

int main()
{
	struct node *head=NULL, *ptr=NULL, *temp=NULL;
	int i, n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=ptr=temp=(struct node*)malloc(sizeof(struct node));
			head->pre=NULL;
		}
		else
		{
			ptr->next=(struct node*)malloc(sizeof(struct node));
			temp=ptr;
			ptr=ptr->next;
			ptr->pre=temp;

		}
		printf("Node [%d] : ",i);
		scanf("%d",&ptr->data);
	}
	ptr->next=NULL;
	print(head);
	return 0;
}