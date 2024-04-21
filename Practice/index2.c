// infix to postfix conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 50
char infix[100];
char postfix[100];
char stack[size];
int top = -1;
void rev(char *infix)
{
    char temp;
    int len = strlen(infix);
    int s = 0;
    int e = len - 1;
    for (int i = 0; i < len / 2; i++)
    {
        temp = infix[s];
        infix[s] = infix[e];
        infix[e] = temp;
        s++;
        e--;
    }
}
int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return 1;
    return 0;
}
int isOperand(char x)
{
    if (isalnum(x))
        return 1;
    return 0;
}
int precedence(char x)
{
    switch (x)
    {
    case '#':
    case ')':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '^':
        return 3;
        break;
    }
}
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    return stack[top--];
}
void inToPost()
{
    rev(infix);
    char symbol, x;
    int j = 0;
    int len = strlen(infix);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        if (isOperand(symbol))
        {
            postfix[j++] = symbol;
        }
        else if (symbol == ')')
        {
            push(symbol);
        }
        else if (symbol == '(')
        {
            while ((x = pop()) != ')')
                postfix[j++] = x;
        }
        else if (isOperator(symbol))
        {
            while (precedence(stack[top]) > precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        else
        {
            printf("Invalid Expression\n");
            exit(1);
        }
    }
    while ((x = pop()) != '#')
        postfix[j++] = x;
    postfix[j] = '\0';
    rev(postfix);
}
int main()
{
    stack[-1] = '#';
    printf("Enter a infix expression : ");
    scanf("%s", infix);
    inToPost();
    printf("\n%s", postfix);
}