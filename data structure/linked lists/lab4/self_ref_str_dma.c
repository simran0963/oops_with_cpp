#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct record
{
	int roll;
	struct record *ptr;
};

void print(struct record *list_beg)
{
	int i=0;
	struct record *temp;
	temp=list_beg;
	while(temp!=NULL)
	{
		printf("\nrecord[%d] = %d\n",i,temp->roll);
		temp=temp->ptr;
		i++;
	}
}
int main()
{
	int n ,i=0;
	struct record *list_beg=NULL, *ptr_t=NULL;
	printf("Enter the size: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(list_beg==NULL)
		{
			list_beg = ptr_t = (struct record*)malloc(sizeof(struct record));
			//ptr_t=ptr_t->ptr;
		}
		else
		{
			ptr_t->ptr=(struct record*)malloc(sizeof(struct record));
			ptr_t=ptr_t->ptr;
		}
		printf("\nRecord %d : ",i);
		scanf("%d",&ptr_t->roll);
	}
	ptr_t->ptr=NULL;
	print(list_beg);
	return 0;
}
