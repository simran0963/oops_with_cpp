#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50

struct node{
    int data;
    struct node *l;
    struct node *r;
};

struct stack{
    int top;
    struct node **arr;

};

struct stack *create_stack(int n){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->arr=(struct node**)malloc(sizeof(struct node)*n);
    s->top=-1;
    return s;
}

void push(struct stack* s,struct node *n){
    s->top++;
    s->arr[s->top]=n;

}

struct node* pop(struct stack *s){
    s->top--;
    return s->arr[s->top+1];

}

int isEmpty(struct stack* s){
    if(s->top==-1) return 1;
    
    return 0;
}


int dfs(struct node *root,int n){
    struct stack *s=create_stack(20);
    push(s,root);
    while(!isEmpty(s)){
        struct node *front=pop(s);

        if(front->data==n) return 1;
       
        if(front->r) push(s,front->r);
        
        if(front->l) push(s,front->l);  
    }
    return 0;

}

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

void disp(struct node *root){
    if(root == NULL)
        return;
    
    disp(root->l);
    printf("%d\t",root->data);
    disp(root->r);
    
}

void main(){
    struct node *root = NULL;
    int ch = 0,n,num,ans,sr;
    while(ch != 5){
        printf("\n1 - insert\n2 - Delete\n3 - Display\n4 - DFS\n5 - Exit");
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
                printf("\n");
                
                break;
            case 4:
                printf("Enter the element you want to find : ");
			   scanf("%d",&sr);
			    ans = dfs(root,sr);
			   if(ans==1)
			   {
			   	 printf("Element found\n");
			   }
			   else{
			    	printf("Not found\n");
			   }
                break;
            case 5:
            	exit(0);
            	break;
            default:
                printf("\nInvalidChoice\n");
                break;
        }
    }  
}
