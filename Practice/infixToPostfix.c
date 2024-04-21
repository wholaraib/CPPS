#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size 50
char infix[100];
char postfix[100];
int stack[size];
int top = -1;
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
    case '(':
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
void push(char ele)
{
    stack[++top] = ele;
}
char pop()
{
    return stack[top--];
}
void intopost()
{
    int j = 0;
    char symbol;
    char x;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        if(isOperand(symbol))
        {
            postfix[j++] = symbol;
        }
        else if(symbol == '(')
        {
            push(symbol);
        }
        else if(symbol == ')')
        {
            while((x = pop()) != '(')
                postfix[j++] = x;
        }
        else if(isOperator(symbol))
        {
            while(precedence(stack[top]) > precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }
        else
        {
            printf("Invalid Expression\n");
            exit(1);
        }
        //(a+b)*(c/d*e+3) 
    }
    while((x = pop()) != '#')
        postfix[j++] = x;
    postfix[j] = '\0';
}
int main()
{
    stack[-1] = '#';
    printf("Enter the infix expression : ");
    scanf("%s", infix);
    intopost();
    printf("%s = %s\n",infix,postfix);
    return 0;
}