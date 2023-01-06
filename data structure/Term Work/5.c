#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *l;
    struct node *r;
};

struct node *insert(struct node *root,int n){
    if(root == NULL){
      root = (struct node*)malloc(sizeof(struct node));
        root->data = n;
        root->l = NULL;
        root->r = NULL;   
    }
    
    else if(root->data > n)
        root->l = insert(root->l,n);
        
    else
        root->r = insert(root->r,n);
        
    return root;
}

struct node *swap(struct node *ptr){
	struct node *p = ptr->r;
    while(p->l != NULL){
        p = p->l;
    }
    ptr->data = p->data;
    free(p);
    return ptr;
}

struct node *delete(struct node *root,int d){
    if(root == NULL) return NULL;
    
    int num;
    
    if(root->data > d )
        root->l = delete(root->l,d);
    else if(root->data < d )
        root->r = delete(root->r,d);
    
    else{
        if(root->r == NULL && root->l == NULL){
            free(root);
            return NULL;
        }
        else if(root->r == NULL ){
            struct node *temp = root->l;
            free(root);
            return temp;
        }
        else if(root->l == NULL ){
            struct node *temp = root->r;
            free(root);
            return temp;
        }
        else{
        	root = swap(root);            
        }
    }    
    return root;
}

unsigned int getLeafCount(struct node* n)
{
	if(n == NULL)       
    	return 0;
    if(n->l == NULL && n->r == NULL)      
    	return 1;            
    else 
    	return getLeafCount(n->l) + getLeafCount(n->r);      
}

int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->l);
        int rDepth = maxDepth(node->r);
  
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int found(struct node* root, int value) 
{ 
    while (root != NULL){

        if (value > root->data) 
            root = root->r; 

        else if (value < root->data) 
            root = root->l; 
        else if (value == root->data)
            return 1; 
    } 
    return 0; 
}

static int count = 0;
int countnodes(struct node *root){
    if(root != NULL){
        countnodes(root->r);
        count++;
        countnodes(root->l);
    }
    return count;
}

void disp(struct node *root){
    if(root == NULL)
        return;
    
    disp(root->l);
    printf("%d\t",root->data);
    disp(root->r);
}

void main(){
    struct node *root = NULL;
    int ch = 0,n,num,item;
    while(ch != 8){
        printf("\n1 - insert\t2 - Delete\t3 - Display\t4 - Search\t5 - Total number of leaf nodes\t6 - Height of tree\t7 - Total numbers of nodes\t8 - Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("ELemnt : ");
                scanf("%d",&n);
                root = insert(root,n);
                break;
            case 2:
                printf("ELemnt : ");
                scanf("%d",&num);
                root = delete(root,num);
                break;
            case 3:
                disp(root);
                break;
            case 4:
            	printf("ELemnt  to Search : ");
                scanf("%d",&item);
            	if(found(root,item))
       				printf("%d value is found in the tree\n",item);
    			else
        			printf("%d value not found\n",item);
                break;
            case 5:
            	printf("Total Numbers of leaf Nodes = %d\n",getLeafCount(root));
                break;
            case 6:
            	printf("Height of the Tree = %d\n",maxDepth(root));
                break;
            case 7:
            	printf("Total numbers of nodes from right hand side of root node = %d\n",countnodes(root));
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("\nInvalidChoice\n");
                break;
        }
    }
}
