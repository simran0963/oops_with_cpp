// Given a BST, WAF to show right and left rotation

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

struct node *rotate_left(struct node *root){
	struct node *temp=root->rc;
	root->rc=temp->lc;
	temp->lc=root;
	return temp;
}

struct node *rotate_right(struct node *root){
	struct node *temp=root->lc;
	root->lc=temp->rc;
	temp->rc=root;
	return temp;
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
		printf("\nEnter your choice\n1. Insert\n2. Rotate Left\n3. Rotate Right\n4. Display\n5. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter the data : ");
			scanf("%d",&obj);
			root = insert(root,obj);
			break;
			
			case 2:
			root=rotate_left(root);
			ht = height(root);
			printf("Height : %d",ht);
			int lf = bal_fac(root);
			printf("\nBalance factor :  %d",lf);
			break;
			
			case 3:
			root=rotate_right(root);
			ht = height(root);
			printf("Height : %d",ht);
			int rf = bal_fac(root);
			printf("\nBalance factor :  %d",rf);
			break;
			
			case 4:
			inorder(root);
			break;
			
			case 5:
			exit(0);
			
			default:
			printf("Invalid input");
			break;
		}
	}
	return 0;
}
