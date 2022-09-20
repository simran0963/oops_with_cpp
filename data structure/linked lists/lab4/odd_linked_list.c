#include<stdio.h>
#include<stdlib.h>

struct record
{
	int roll;
	struct record *ptr;
};

void print(struct record *list_beg)
{
	if(list_beg==NULL){
		return;
	}
		printf("\n%d\n",list_beg->roll);
		print(list_beg->ptr);
}

void odd(struct record *list_beg)
{
	if(list_beg==NULL)
	{
		return;
	}
	
		if(list_beg->roll%2==1)
		{
			printf("\n%d",list_beg->roll);
		}
		odd(list_beg->ptr);
}

int main()
{
	struct record *list_ptr=NULL, *ptr_t=NULL;
	int i, n;
	scanf("%d",&n);
		for(i=0;i<n;i++)
	{
		if(list_ptr==NULL)
		{
			list_ptr=ptr_t=(struct record*)malloc(sizeof(struct record));
		}
		else
		{
			ptr_t->ptr=(struct record*)malloc(sizeof(struct record));
			ptr_t = ptr_t->ptr;
		}
		printf("\nRecord %d : ",i);
		scanf("%d",&ptr_t->roll);
	}
	ptr_t->ptr=NULL;
	print(list_ptr);
	odd(list_ptr);
	return 0;
}