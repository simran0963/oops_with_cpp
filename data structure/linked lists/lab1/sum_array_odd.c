#include<stdio.h>
#define max 100
int main()
{
	int i, n, sum=0, arr[max];
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]%2==1)
		{
			sum+=arr[i];
		}
	}
	printf("The sum of all odd elements of the array is: %d",sum);
	return 0;
}

