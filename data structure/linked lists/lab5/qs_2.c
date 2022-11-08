#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void del(struct node *head)
{
	struct node *ptr=head->next, *temp=head;
	int num;
	if(head==NULL)
	{
		exit(0);
	}
	else
	{
		printf("\nEnter the value of data after which the deletion is to be initiated: ");
		scanf("%d",&num);
		if(head->data==num)
		{
			printf("\nElements from the starting and end of the list cannot be modified.");
			exit(0);
		}
		else{
			while(ptr->data!=num)
			{
				temp=temp->next;
				ptr=ptr->next;
			}
			printf("\nElement found.");
			head=temp;
			temp=temp->next->next;
			head->next=NULL;
			free(head->next);
		}
	}
}

void print(struct node *head)
{
    if(head==NULL)return;
    printf("Data : %d\t",head->data);
    print(head->next);
}

int main()
{
    struct node *head=NULL, *ptr=NULL;
    int n, i,ch;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(head==NULL)
        {
            head=ptr=(struct node *)malloc(sizeof(struct node));
        }
        else
        {
            ptr->next=(struct node *)malloc(sizeof(struct node));
            ptr=ptr->next;
        }
        printf("\nEnter Data %d : ",i+1);
        scanf("%d",&ptr->data);
    }
    ptr->next==NULL;
    print(head);
	printf("New list is: \n");
	del(head);
	print(head);
    return 0;
}
