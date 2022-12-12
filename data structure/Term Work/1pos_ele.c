// Write a program to store N elements to an array and the send all positive elements of the array to the end without altering the original experience. 
#include<stdio.h>
#include<stdlib.h>

int push(int arr[],int mx){
	printf("Enter the number to be pushed : ");
	scanf("%d",&arr[++mx]);
	return mx;
}

void display(int arr[],int mx){
	for(int i=0;i<=mx;i++){
		printf("%d\t",arr[i]);
	}
}

int rearrange(int arr[],int mx){
	int k=0, temp;
	for(int i=0; i<=mx;i++){
		if(arr[i]<0){
			for(int j=i;j!=k;j--){
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
			k++;
		}
	}
	return mx;
}

int main(){
	int n, i=0,num, mx=-1, arr[20],ch;
	while(1){
		printf("\n1. Push\n2. Display\n3. Rearrange\n4. Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			mx=push(arr,mx);
			break;

			case 2:
			display(arr,mx);
			break;

			case 3:
			mx=rearrange(arr,mx);
			break;

			case 4:
			exit(0);

			default:
			printf("Invalid choice");
		}
	}
}