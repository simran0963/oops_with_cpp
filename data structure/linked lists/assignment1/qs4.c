#include<stdio.h>
#include<stdlib.h>
#define max 50

int push(int arr[], int topa, int num)
{
	arr[++topa]=num;
	return topa;
}

int pop(int arr[], int topa)
{
	return --topa;
}

void display(int arr[],int top)
{
	for(top=top;top>=0;top--)
	{
		printf("%d  ",arr[top]);
	}
}

void sortstk(int arr[],int topa)
{
	int brr[max],crr[max], temp,i,j,k,topc=-1,topb=-1,tempi=0,temp1=0;
	for(i=topa;i>=0;i--){
		temp=arr[topa];
		topa=pop(arr,topa);
		topb=push(brr,topb,temp);
	}
	printf("\n\nBrr array is : ");
	display(brr, topb);
	for(i=topb;i>=0;i--){
		if(topa==-1){
			printf("#1");
			temp=brr[topb];
			topb=pop(brr,topb);
			topa=push(arr,topa,temp);
		}
		
		else if(topa>=0)
		{
			printf("\n#else The arr stack is:\n");
			display(arr,topa);
			printf("\n#else The brr stack is:\n");
			display(brr,topb);
			printf("#2");
			for(i=topb;i>=0;i--)
			{
				temp=brr[topb];
				for(k=topa;k>=0;k--){if(arr[k]>temp){tempi=k;}}
				for(j=topa;j>=tempi;j--)
				{
					printf("#3");
					temp1=arr[topa];
					topa=pop(arr,topa);
					topc=push(crr,topc,temp1);
					printf("\n#else The arr stack is:\n");
					display(arr,topa);
					printf("\n#else The crr stack is:\n");
					display(crr,topc);
				}
				arr[topa]=temp;
				for(int l=topc;l>=0;l--)
				{
					printf("#4");
					temp=crr[topc];
					topc=pop(crr,topc);
					topa=push(arr,topa,temp);
					printf("\n#else The arr stack is:\n");
					display(arr,topa);
					printf("\n#else The crr stack is:\n");
					display(crr,topc);
				}
			}
		}
	}
	printf("\nThe sorted stack is:\n");
	display(arr,topa);
}

int main(){
	int arr[50], top=-1, ch, num;
	while(1)
	{
		printf("\n\n\n1. Push\n2. Pop\n3. Display\n4. Sort and Exit\nEnter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			if(top>=max-1){
				printf("Stack Overflow.");
				return 0;
			}
			printf("Enter the number : ");
			scanf("%d",&num);
			top=push(arr,top,num);
			printf("\n");
			display(arr,top);
			break;

			case 2:
			if(top==-1){
				printf("Stack underflow");
				return 0;
			}
			top=pop(arr,top);
			display(arr,top);
			break;

			case 3:
			display(arr, top);
			break;

			case 4:
			sortstk(arr,top);
			exit(0);

			default:
			printf("Invalid input");
			exit(0);
		}
	}
	printf("The sorted stack is:\n");
	sortstk(arr,top);

}