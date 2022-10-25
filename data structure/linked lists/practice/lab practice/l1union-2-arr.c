// WACP to find out union of two given arrays
#include<stdio.h>
#define max 10

void print(int *arr, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}

int main()
{
	int arr[max],brr[max],i, j, n, m;
	printf("\nEnter the number of entries in first array: ");
	scanf("%d",&n);
	printf("Enter the values: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("\nEnter the number of entries in second array: ");
	scanf("%d",&m);
	printf("Enter the values: \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&brr[i]);
	}
}