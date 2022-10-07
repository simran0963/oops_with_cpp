//Stack using array Implementation of push(), pop() and display() functions 

#include<stdio.h>
#include<stdlib.h>
#define max 10

int push(int *arr, int top);
int pop(int *arr, int top);
void display(int *arr,int top);

int main()
{
    int ch, i, top=-1, arr[max];
    while(1){
    printf("\n1. Push\n2. Pop \n3. Display 4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\n");
        top = push(arr,top);
        display(arr,top);
        break;
        
        case 2:
        printf("\n");
        top = pop(arr,top);
        display(arr,top);
        break;
        
        case 3:
        printf("\n");
        display(arr,top);
        break;
        
        case 4:
        exit(0);
        
        default:
        printf("Wrong choice");
    }
}
}

int push(int *arr, int top)
{
    int num;
    if(top==max-1)
    {
        printf("Overflow");
    }    
    else
    {
        top++;
        printf("Enter the element : ");
        scanf("%d",&num);
        arr[top]=num;
    }
    return top;
}

int pop(int *arr, int top)
{
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        printf("Element deleted : %d\n",arr[top]);
        top--;
    }
    return top;
}

void display(int *arr,int top)
{
    if(top==-1)
    {
        printf("\nNo elements to display");
    }
    
    else
    {
         while(top>=0)
        {
            printf("%d\t",arr[top]);
            top--;
        }
    }
}
