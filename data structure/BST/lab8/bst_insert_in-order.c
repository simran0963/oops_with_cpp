// WACP to insert elements in a Binary Search Tree 

#include <stdio.h>
#include <stdlib.h>

struct node {                                     // structure declaration
  int data;
  struct node *lc, *rc;
};

struct node *newNode(int obj) {                 // making new node
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = obj;
  temp->lc = temp->rc = NULL;
  return temp;
}

void traverse(struct node *head) {                     // in-order traversing
  if (head != NULL) {
    traverse(head->lc);

    printf("%d, ", head->data);

    traverse(head->rc);
  }
}

struct node *insert(struct node *node, int data) {         // inserting node
  if (node == NULL) return newNode(data);

  if (data < node->data)
    node->lc = insert(node->lc, data);
  else
    node->rc = insert(node->rc, data);

  return node;
}

int main() {                                           // main function

 	struct node *head = NULL;
  	int ch = 0,n;
 	
	while(1){
		printf("\n1 - Insert\n2 - Display\n3 - Exit\nEnter your Choice : ");
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
				exit(0);	
				
			default:
				printf("\nInvalid Choice !\n");
		}
	}
	return 0;
}