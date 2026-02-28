#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int math(char exp[]) 
{
    int i = 0;
    int op1, op2;

    while (exp[i] != '\0') 
    {
        if (isdigit(exp[i])) 
        {
            int num = 0;

            while (isdigit(exp[i])) 
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
            i--;   
        } 
        
        else if (exp[i] == ' ' || exp[i] == '\n') 
        {
            // Ignore spaces
        }

        else 
        {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) 
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }

        i++;
    }

    return pop();
}

int main() 
{
    char exp[MAX];

    printf("Enter Postfix Expression (use space between numbers): ");
    fgets(exp, sizeof(exp), stdin);

    int result = math(exp);

    printf("Result = %d\n", result);

    return 0;
}
