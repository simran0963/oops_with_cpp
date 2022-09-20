#include<stdio.h>
#include<stdlib.h>

struct record
{
	int roll;
	struct record *ptr;
};

void print(struct record *list_beg)
{

	if(list_beg==NULL)
	{
		return;
	}
	printf("record %d",list_beg->roll);
	print(list_beg->ptr);
}
void reverse(struct record** list_beg)
{
    struct record* prev = NULL;
    struct record* current = *list_beg;
    struct record* ptr = NULL;
    while (current != NULL) {
        ptr = current->ptr;
        current->ptr = prev;
        prev = current;
        current = ptr;
    }
    *list_beg = prev;
}

int main()
{
	struct record *list_beg=NULL ,*ptr_t=NULL;
	int i, n;
	printf("Enter the number of records: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(list_beg==NULL)
		{
			list_beg=ptr_t=(struct record*)malloc(sizeof(struct record));
		}
		else{
			ptr_t->ptr=(struct record*)malloc(sizeof(struct record));
			ptr_t=ptr_t->ptr;
		}
		printf("\nrecord[%d] : ",i);
		scanf("%d",ptr_t->roll);
	}
	print(list_beg);
}