// Given a bst, waf to find height and balance factor at the root node

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

int height(struct node*root){
	int hl=0,hr=0;
	if(root->lc){
		hl=height(root->lc) + 1;
	}
	if(root->rc){
		hr=height(root->rc) + 1;
	}
	//printf("\nBalance factor of the tree is : %d",(hl-hr));
	return (hl>hr)?hl:hr;
}

int bal_fac(struct node*root){
	int hl=0,hr=0;
	if(root->lc){
		hl=bal_fac(root->lc) + 1;
	}
	if(root->rc){
		hr=bal_fac(root->rc) + 1;
	}
	return (hl-hr);
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
		printf("\nEnter your choice\n1. Insert\n2. Height\n3. Display\n4. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter the data : ");
			scanf("%d",&obj);
			root = insert(root,obj);
			break;
			
			case 2:
			ht = height(root);
			printf("Height : %d",ht);
			int bf = bal_fac(root);
			printf("\nBalance factor :  %d",bf);
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