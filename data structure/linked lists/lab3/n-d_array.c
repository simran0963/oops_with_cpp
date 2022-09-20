#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int main()
{
	int i,j,k,n,d,*ptr,total=0,ind[MAX];
	printf("Enter the number of dimensions: ");
	scanf("%d",&d);
	int arr[d];
	for(i=0;i<d;i++)
	{
		printf("Max value[%d]",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\n\n");
	for(i=0;i<d;i++)
	{
		printf("index[%d]",i+1);
		scanf("%d",&ind[i]);
	}
	
	ptr=(int*)malloc(n*sizeof(int));
	int *base;
	base=ptr;
	total=ind[0];
	for(i=1;i<d;i++)
	{
		total*=arr[i];
		total+=ind[i];
	}
	printf("\nBase address: %d",base);
	printf("\n%d",total);
	printf("\nPositional Address %d",(base + total));
	return 0;
}
