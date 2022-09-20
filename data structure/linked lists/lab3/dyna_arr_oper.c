#include<stdio.h>
#define MAX 100

void display(int arr[MAX],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d  ",*(arr+i));
	}
}

void insert(int arr[MAX],int n)
{
	int i, j, num, pos;
	printf("\nThe original array is:\t");
	display(arr,n);
	printf("\nEnter the position you want to insert in: ");
	scanf("%d",&pos);
	printf("\nEnter the number you want to insert: ");
	scanf("%d",&num);
	for(i=n;i>pos;i--)
	{
		arr[i]=*(arr+i-1);
	}
	*(arr+pos)=num;
	printf("\nThe new array is:\t");
	display(arr,n+1);
}

void delete(int arr[MAX],int n)
{
	int i, j, pos;
	printf("\nThe original array is:\t");
	display(arr,n);
	printf("\nEnter the position you want to delete: ");
	scanf("%d",&pos);
	for(i=pos;i<n-1;i++)
	{
		*(arr+i)=*(arr+i+1);
	}
	printf("\nThe new array is:\t");
	display(arr,n-1);
}

void search(int arr[MAX],int n)
{
	int i, j, num,ind, a=0;
	printf("\nThe original array is:\t");
	display(arr,n);
	printf("\nEnter the number you want to search: ");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if (*(arr+i)==num)
		{
			a++;
			ind=i;
			break;
		}
	}
	if(a>0)
	{
		printf("\nNumber %d was found at index %d",num, ind);
	}
	else{
		printf("\nNumber %d was not found :/",num);
	}
}

int main()
{
	int i, n, var, pos, num;
	printf("\nEnter the number of elements:  ");
	scanf("%d", &n);
	int *arr = (int*)malloc(n*sizeof(int));
	printf("\nEnter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the value as per the operation to be performed: \n1. Insertion\n2. Deletion\n3. Searching\n4. Displaying\n");
	scanf("%d",&var);
	switch(var)
	{
		case 1:
			printf("\nInsertion: ");
			insert(arr,n);
			break;
			
		case 2:
			printf("\nDeletion: ");
			delete(arr,n);
			break;
		
		case 3:
			printf("\nSearching: ");
			search(arr, n);
			break;
			
		case 4:
			printf("\nDisplaying: ");
			printf("\nThe array is:\t");
			display(arr,n);
			break;

		default:
			printf("Invalid choice =_=");
	}
	return 0;
}
