#include<stdio.h>

void disp(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

int *PosToEnd(int arr[],int n){
	int i,err[100],orr[100],j=0,k=0;
	for(i=0;i<n;i++){
		if(arr[i] > 0){
			err[j] = arr[i];
			j++;
		}
		else{
			orr[k] = arr[i];
			k++;
		}
	}

	for(i=0;i<k;i++){
		arr[i] = orr[i];
	}
	for(i=0;i<j;i++){
		arr[k] = err[i];
		k++;
	}
	return arr;
}

int main(){
	int i,n,arr[100],*brr;
	printf("Enter the limit of Array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Element [%d] : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEntered data : \n");
	disp(arr,n);
	
	brr = PosToEnd(arr,n);
	printf("\nNew data : \n");
	disp(brr,n);
}