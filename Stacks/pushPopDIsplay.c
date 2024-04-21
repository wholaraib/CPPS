#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct STACK
{
    int stackarr[SIZE];
    int sp;
};
typedef struct STACK stack;
void push(stack *s)
{
    int x;
    if (s->sp == (SIZE - 1))
    {
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        printf("Enter the element to be added onto the stack : ");
        scanf("%d", &x);
        s->sp = s->sp + 1;
        s->stackarr[s->sp] = x;
    }
}
int pop(stack *s)
{
    int y;
    if (s->sp == -1)
    {
        printf("Stack underflow!");
        return -1;
    }
    else
    {
        y = s->stackarr[s->sp];
        s->sp = s->sp - 1;
        return y;
    }
}
void display(stack s)
{
    int tsp = s.sp;
    if (tsp == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = tsp; i > -1; i--)
    {
        printf("%d\n", s.stackarr[i]);
    }
}
int checkPallindrome(stack s)
{
    int tsp = 0;
    int ssp = s.sp;
    for(int i = 0; i < ssp/2; i++)
    {
        if(s.stackarr[tsp]!=s.stackarr[ssp])
            return 0;
        else
        {
            tsp++;
            ssp--;
        }
    }
    return 1;
}
void peek(stack s)
{
    printf("Top most element is %d\n", s.stackarr[s.sp]);
}
int main()
{
    stack s;
    int choice;
    int ele;
    s.sp = -1;

    while (1)
    {
        printf("Enter choice :\n1.For push operation\n2.For pop operation\n3.For displaying stack elements\n4.Peek\n5.Check Pallindrome\n6.Exit\n-->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&s);
            break;

        case 2:
            ele = pop(&s);
            if (ele != -1)
                printf("Popped element is %d", ele);
            break;
        case 3:
            display(s);
            break;
        case 4:
            peek(s);
            break;
        case 5 : printf("%d",checkPallindrome(s));
        case 6:
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
        }
    }
}