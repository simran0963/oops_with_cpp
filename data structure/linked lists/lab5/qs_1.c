#include<stdio.h>
#include<stdlib.h>
// self referential structure
struct node
{
    int data;
    struct node *next;
};

struct node *start(struct node *head)
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("list underflow");                   //underflow
        exit(0);
    }
    else
    {
        head=head->next;
        free(temp);                                // freeing memory
    }
    return head;
}

void end(struct node *head)
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nList underflow");                   //overflow
        exit(0);
    }
    else
    {
        ptr=head->next;
        while(ptr->next!=NULL)
        {
            head=head->next;
            ptr=ptr->next;
        }
        head->next=NULL;
        free(head->next);
    }
}

void print(struct node *head)              //printing linked list
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
    for(i=0;i<n;i++)                     //allocating memory
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
        printf("\nEnter Data %d : ",i+1);    // accepting data
        scanf("%d",&ptr->data);
    }
    ptr->next==NULL;
    print(head);
    printf("\nEnter your choice :\n1. Deleting at the begining.\n2. Deleting at the end.\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\nDeleting at the beginning:\n");
        head = start(head);
        printf("\n\n");
        print(head);
        break;
        
        case 2:
        printf("\nDeleting at the end:\n");
        end(head);
        printf("\n\n");
        print(head);
        break;
        
        default:
        exit(0);
    }
    return 0;
}
