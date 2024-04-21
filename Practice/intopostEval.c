#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
float stack[100];
int sp = -1;
float stable[26];
void push(float ele)
{
    stack[++sp] = ele;
}

float pop()
{
    if (sp == -1)
    {
        printf("Invalid Expression");
        exit(1);
    }
    return (stack[sp--]);
}

float expeval(char postfix[])
{
    char ips;
    float op1, op2, res;
    int ind;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        ips = postfix[i];
        if (isdigit(ips))
            push(ips - '0');
        else if (isalpha(ips))
        {
            if (ips >= 'A' && ips <= 'Z')
                ind = ips - 'A';
            else
                ind = ips - 'a';
            if (stable[ind] == -1)
            {
                printf("Enter the value of %c : ", ips);
                scanf("%f", &stable[ind]);
            }
            push(stable[ind]);
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ips)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '^':
                res = pow(op1, op2);
                break;
            case '/':
                if (op2 != 0)
                    res = op1 / op2;
                else
                {
                    printf("divide by zero error");
                    exit(1);
                }
                break;
            default:
                printf("invalid OP");
                exit(1);
            }
            push(res);
        }
    }
    if (sp > 0)
    {
        printf("Invalid Expression");
        exit(1);
    }

    return (pop());
}

int main()
{
    char pf[40];
    printf("Enter postfix expression :  ");
    scanf("%s", pf);
    for (int i = 0; i < 26; i++)
        stable[i] = -1;
    printf("%s = %f", pf, expeval(pf));
    return 0;
}