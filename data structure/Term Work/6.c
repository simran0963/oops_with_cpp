#include<stdio.h>
#include<stdlib.h>
 
struct Node{
	int info;
    struct Node *prev, *next;
};
 
void nodeInsetail(struct Node **head,struct Node **tail,int key){
 
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->info = key;
    p->next = NULL;
 
    if ((*head) == NULL){
        (*head) = p;
        (*tail) = p;
        (*head)->prev = NULL;
        return;
    }
 
    if ((p->info) < ((*head)->info)){
        p->prev = NULL;
        (*head)->prev = p;
        p->next = (*head);
        (*head) = p;
        return;
    }

    if ((p->info) > ((*tail)->info)){
        p->prev = (*tail);
        (*tail)->next = p;
        (*tail) = p;
        return;
    }

    struct Node *temp = (*head)->next;
    while ((temp->info) < (p->info))
        temp = temp->next;

    (temp->prev)->next = p;
    p->prev = temp->prev;
    temp->prev = p;
    p->next = temp;
}
 
void printList(struct Node *temp){
    while (temp != NULL){
        printf("%d ", temp->info);
        temp = temp->next;
    }
}
 
int main(){
	struct Node *left = NULL, *right = NULL;
	int n,c=0 ;	
	do{
		printf("Element : ");
		scanf("%d",&n);
		
		nodeInsetail(&left, &right, n);
		
		printf("\nDo you want to continue (1/0)  : ");
		scanf("%d",&c);
	} while (c != 0);
	 	
    printf("\nDoubly linked list on printing from left to right\n");
    printList(left);
 
    return 0;
}
