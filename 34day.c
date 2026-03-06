#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int x;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    x = temp->data;
    top = top->next;
    free(temp);

    return x;
}

int evaluatePostfix(char exp[])
{
    int i = 0;
    int a, b, result;

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch(exp[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
        i++;
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter Postfix Expression: ");
    scanf("%s", exp);

    int ans = evaluatePostfix(exp);

    printf("Result = %d", ans);

    return 0;
}