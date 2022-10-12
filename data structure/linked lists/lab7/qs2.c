// WAP to convert infix to postfix. Consider the precedence low to high as =,(,<+->,<*/>,^

#include<stdio.h>
#include<ctype.h>

char stack[100]; //defining stack
int top = -1;

void push(char x)  // push fun in a=stack
{
    stack[++top] = x;
}

char pop()     // pop fun in stack
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)     // check priority
{
	if(x == '=')
		return 0;
    if(x == '(')
        return 1;
    if(x == '+' || x == '-')
        return 2;
    if(x == '*' || x == '/')
        return 3;
	if(x == '^')
		return 4;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}