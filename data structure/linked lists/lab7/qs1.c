// WAP to evaluate the given postfix expression

#include<stdio.h>
#include<math.h>

char push(char stack[],int top, int x)
{
    stack[++top] = x;
    return stack[top];
}

int pop(char stack[],int top)
{
    return stack[top--];
}

int isdigit(int e)
{
	if('e'>=48 || 'e'<=57)
	{
		return 1;
	}
	return 0;
}

int main()
{
    char exp[20], stack[20];
    char *e;
    int n1,n2,n3,num,top=-1;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(stack,top,num);
        }
        else
        {
            n1 = pop(stack,top);
            n2 = pop(stack,top);
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }

			case '^':
			{
				n3 = pow(n1,n2);
				break;
			}
            }
            push(stack,top,n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop(stack,top));
    return 0;
}