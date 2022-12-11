#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node *rc, *lc;
	bool tread;
};

int main(){                                           // main function
 	struct node *head = NULL;
  	int ch = 0,n;
 	
	while(1){
		printf("\n1 - Insert\n2 - Display\n3 - Delete\n4 - Exit\nEnter your Choice : ");
		scanf("%d",&ch);
		switch (ch){
			case 1:
				printf("Element : ");
				scanf("%d",&n);
				head = insert(head,n);
				break;
				
			case 2:
				traverse(head);
				break;
				
			case 3:
				printf("Element : ");
				scanf("%d",&n);
				head = deleteNode(head, n);
				break; 
				
			case 4:
				exit(0);	
				
			default:
				printf("\nInvalid Choice !\n");
		}
	}
	return 0;
}