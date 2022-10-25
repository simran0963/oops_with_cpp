// WACP to add the even and odd elements of the array
#include<stdio.h>
#define max 100

void even(int *arr, int n);
void odd(int *arr, int n);
void print(int *arr, int n);

int main()
{
	int arr[max],n, i, ch;
	printf("Enter the number of entries: ");
	scanf("%d",&n);
	printf("\nEnter the elements: ");
	i=0;
	while(i<n)
	{
		scanf("%d",&arr[i]);
		i++;
	}
	i=0;
	printf("\nThe array is: \n");
	void print(int *arr, int n);
	printf("\n1. Even elements\n2. Odd elements\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		even(arr, n);
		break;

		case 2:
		odd(arr, n);
		break;
	}
}

void even(int *arr, int n)
{
	printf("Even elements: \n");
	for(int i=0;i<n;i++){
		if(arr[i]%2==0){
			printf("%d\t",arr[i]);
		}
	}
}

void odd(int *arr, int n)
{
	printf("\nOdd elements: \n");
	for(int i=0;i<n;i++){
		if(arr[i]%2==1){
			printf("%d\t",arr[i]);
		}
	}
}

void print(int *arr, int n)
{
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}