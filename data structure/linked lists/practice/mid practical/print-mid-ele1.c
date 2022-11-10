#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void middle(struct node *head, int ch){
	struct node *ptr=head;
	int ind=ch/2;
	for(int i=0;i<ind;i++){
		ptr=ptr->next;
	}
	printf("\nMiddle element : %d",ptr->data);
}

int main(){
	struct node *head=NULL, *ptr=NULL;
	int ch;
	printf("Enter the number of nodes : ");
	scanf("%d",&ch);
	for(int i=0;i<ch;i++){
				if(head==NULL){
			head=ptr=(struct node *)malloc(sizeof(struct node));
		}
		else{
			ptr->next=(struct node *)malloc(sizeof(struct node));
			ptr=ptr->next;
		}
		printf("Enter the data : ");
		scanf("%d",&ptr->data);
	}
	ptr->next=NULL;
	middle(head,ch);
	return 0;
}