#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void rev(char *infix)
{
    char temp;
    int len = strlen(infix);
    int s = 0;
    int e = len - 1;
    for(int i = 0; i < len/2; i++)
    {
        temp = infix[s];
        infix[s] = infix[e];
        infix[e] = temp;
        s++;
        e--;
    }
}

int main()
{
    char infix[30];
    printf("Enter expression : ");
    scanf("%s",infix);
    rev(infix);
    printf("\n%s",infix);
}