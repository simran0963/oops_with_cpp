// WAP to find the in-order predecessor and in-order successor of the root value

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lc, *rc;
};

// Create node
struct node *insert(struct node *root, int obj){
	if(root==NULL){
		root=(struct node *)malloc(sizeof(struct node));
		root->data=obj;
		root->lc=NULL;
		root->rc=NULL;
	}
	else if(root->data==obj){
		printf("Error");
	}
	else{
		if(root->data > obj){
			root->lc=insert(root->lc, obj);
		}
		else 
			root->rc=insert(root->rc, obj);
	}
	return root;
}

void pred(struct node *root){
	if(root==NULL){
		return;
	}
	if(root->lc!=NULL){
		root=root->lc;
		while(root->rc!=NULL){
			root=root->rc;
		}
		printf("\nIn-order predessor : %d",root->data);
	}
	else{
		printf("No predessor exists");
	}
}

void succ(struct node *root){
	if(root==NULL){
		return;
	}
	if(root->rc!=NULL){
		root=root->rc;
		while(root->lc!=NULL){
			root=root->lc;
		}
		printf("\nIn-order successor : %d",root->data);
	}
	else{
		printf("No successor exists");
	}
}

// Tree Display
void inorder(struct node *root){
	if(root==NULL){
		return;
	}
	inorder(root->lc);
	printf("%d\t",root->data);
	inorder(root->rc);
}

int main(){
	struct node *root=NULL;
	int ch,obj,ht=0;
	while(1){
		printf("\nEnter your choice\n1. Insert\n2. Predessor and successor\n3. Display\n4. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter the data : ");
			scanf("%d",&obj);
			root = insert(root,obj);
			break;
			
			case 2:
			pred(root);
			succ(root);
			break;
			
			case 3:
			inorder(root);
			break;
			
			case 4:
			exit(0);
			
			default:
			printf("Invalid input");
			break;
		}
	}
	return 0;
}