#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct Stack
{
    int data[SIZE];
    int top;

};
typedef struct Stack stack;
int isFull(stack s)
{
    if(s.top == SIZE -1)
        return 1;
    return 0;
}
int isEmpty(stack s)
{
    if(s.top == -1)
        return 1;
    return 0;
}
void push(stack s,int ele)
{
    if(!isFull(s))
        s.data[++s.top] = ele;
    else
        printf("Stack overflow\n");
}
int pop(stack s)
{
    if(!isEmpty(s))
        return s.data[s.top--];
    printf("Stack underflow\n");
    return -1;
}
void display(stack s)
{
    for(int i = 0; i < s.top; i++)
        printf("%d\n",s.data[i]);
}
int main()
{
    stack s;
    s.top = -1;
    push(s,3);
    push(s,5);
    display(s);


}