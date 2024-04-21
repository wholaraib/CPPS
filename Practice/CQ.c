#include <stdio.h>
#include <stdlib.h>
#define size 3
struct QUEUE
{
    char data[size];
    int r,f;
};
typedef struct QUEUE queue;
int isFull(queue q)
{
    if((q.r + 1) % size == q.f)
        return 1;
    return 0;
}
int isEmpty(queue q)
{
    if(q.f == -1)
        return 1;
    return 0;
}
void insert(queue *q, char ele)
{
    if(q->f == -1)  
        q->f = 0;
    q->r = (q->r + 1) % size;
    q->data[q->r] = ele;
    printf("Character %c inserted in the queue\n",ele);
}
char delete(queue *q)
{
    char ele = q->data[q->f];
    if(q->f  == q->r){
        q->f = -1;
        q->r = -1;
    }
    else
    {
        q->f = (q->f + 1)%size;
    }
    return ele;
}
void display(queue q)
{
    int i;
    for(i = q.f; i != q.r; i = (i+1)%size)
        printf("%c  ",q.data[i]);
    printf("%c ",q.data[i]);
}
int main()
{
    queue q;
    q.r = -1;
    q.f = -1;
    int choice;
    char data;
    while (1)
    {
        printf("\n\n1:Insert\n2:Delete\n3:Display\n4:Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(q))
                printf("\nQueue Overflow !!!");
            else
            {
                printf("\nEnter the character to be inserted: ");
                getchar();
                scanf("%c", &data);
                insert(&q, data);
            }
            break;
        case 2:
            if (isEmpty(q))
                printf("\nQueue Underflow !!!");
            else
                printf("\nCharacter %c is deleted from queue", delete(&q));
            break;
        case 3:
            if (isEmpty(q))
                printf("\nQueue is Empty !!!");
            else
                display(q);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}