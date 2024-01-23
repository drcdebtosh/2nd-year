#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 5

char stack[MAX], p[MAX], q[MAX];
int top = -1;
char item;

void push(char item)
{
    top = top + 1;

    // printf("Enter value to push:\n");
    // scanf("%d", &item);
    // top++;
    stack[top] = item;
}

// void pop()
// {
//     if (top == -1)
//     {
//         printf("Underflow");
//     }
//     else
//     {
//         item = stack[top];
//         top--;
//     }
// }
int operator(char ch)
{
    if (ch == '+' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
}

int preference(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ToPrefix()
{

    int i = 0, j = 0;

    while (q[i] != '\0')
    {
        if (isalpha(q[i]))
        {
            p[j] = q[i];
            j++;
        }
        else if (q[i] == '(')
        {
            push(q[i]);
        }

        else if (q[i] == ')')
        {
            while (stack[top] != '(')
            {
                p[j++] = stack[top];
                top--;
            }
        }
        else if (operator(q[i]))
        {
            if (operator(stack[top]))
            {
                if (preference(q[i]) > preference(stack[top]))
                {
                    push(q[i]);
                }
                else if (preference(q[i]) <= preference(stack[top]))
                {
                    p[j] = stack[top];
                    top--;
                    j++;
                    push(q[i]);
                }
            }
            else
                push(q[i]);
        }
        i++;
    }
    p[j] = '\0';
}
int main(void)
{
    printf("Enter the expression :");
    scanf("%s", q);
    ToPrefix();
    printf("prefix expression is %s\n", p);
    return 0;
}