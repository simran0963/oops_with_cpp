#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node *rc, *lc;
	bool tread;
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

struct node *minValueNode(struct node *node) {            //minimum value node
  struct node *current = node;

  while (current && current->lc != NULL)
    current = current->lc;

  return current;
}

struct node *deleteNode(struct node *head, int data) {      // deleting node
  if (head == NULL) return head;

  if (data < head->data)
    head->lc = deleteNode(head->lc, data);
  else if (data > head->data)
    head->rc = deleteNode(head->rc, data);

  else {
    if (head->lc == NULL) {
      struct node *temp = head->rc;
      free(head);
      return temp;
    } else if (head->rc == NULL) {
      struct node *temp = head->lc;
      free(head);
      return temp;
    }

    struct node *temp = minValueNode(head->rc);

    head->data = temp->data;

    head->rc = deleteNode(head->rc, temp->data);
  }
  return head;
}

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