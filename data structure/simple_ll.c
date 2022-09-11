#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

int main()
{
	struct node *head=NULL, *ptr=NULL;
	int i=0, n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	while(i<n)
	{
		if(head==NULL)
		{
			head=ptr=((struct node*)malloc(sizeof(struct node)));
		}
		else
		{
			ptr->next=((struct node*)malloc(sizeof(struct node)));
			ptr=ptr->next;
			printf("Input data for node %d : ",i);
			scanf("%d",&ptr->data);
			i++;
		}
	}
	ptr=head->next;
	printf("\nData entered in the list is:\n");
	for(i=0;i<n;i++)
	{
		printf("Data = %d\n",ptr->data);
		ptr=ptr->next;
	}
}