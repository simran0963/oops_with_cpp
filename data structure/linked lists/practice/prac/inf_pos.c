#include<stdio.h>
#include<ctype.h>

void push(char x, char *stack[], int *top)
{
    stack[++(*top)] = x;
}

char pop(char *stack[], int *top)
{
    if(*top == -1)
        return -1;
    else
        return stack[(*top)--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100],stack[100];
    char *e, x;
	int top=-1;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e,&stack,&top);
        else if(*e == ')')
        {
            while((x = pop(&stack,&top)) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
				x=pop(&stack,&top);
                printf("%c ",x);
            push(*e,&stack,&top);
        }
        e++;
    }
    
    while(top != -1)
    {
		x=pop(&stack,&top);
        printf("%c ",x);
    }return 0;
}
