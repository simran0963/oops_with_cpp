#include<stdio.h>
#define max 100
int main()
{
	int i, j, k, ncop, yes=0, temp, n, m, arr[max], arr1[max], arr2[max];
	printf("Enter the size of first array: ");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}
	printf("Enter the size of second array: ");
	scanf("%d",&m);
	printf("Enter the elements : \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr1[i]);	
	}
	ncop=n;
	for(j=0;j<m;j++)
	{
		arr[ncop]=arr1[j];
		ncop++;
		
	}
	for(i=0;i<ncop;i++)
	{
		for(j=i+1;j<ncop;j++)
		{
			if(arr[i]==arr[j])
			{
				for(k=j;k<ncop-1;k++)
				{
					arr[k]=arr[k+1];
				}
				ncop--;
				j--;
			}
		}
	}
	printf("The new array after union is: \n");
	for(i=0;i<ncop;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}

