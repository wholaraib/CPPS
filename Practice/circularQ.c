#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct student
{
    char name[40], usn[40];
} std;

struct queue
{
    std data[SIZE];
    int front, rear;
};
typedef struct queue que;

int isfull(que *q)
{
    if ((q->rear + 1) % SIZE == q->front)
        return 1;
    return 0;
}
int isempty(que *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}
void input(que *q, std ele)

{
    if (isfull(q))
    {
        printf("Queue is Overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % SIZE;
    strcpy(q->data[q->rear].name, ele.name);
    strcpy(q->data[q->rear].usn, ele.usn);
    if (q->front == -1)
    {
        q->front = 0;
    }
}
std del(que *q)
{
    std ele = {"", "0"};
    if (isempty(q))
    {
        printf("Queue Underflow\n");
        return ele;
    }
    strcpy(ele.name, q->data[q->front].name);
    strcpy(ele.usn, q->data[q->front].usn);
    q->front = (q->front + 1) % SIZE;

    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return ele;
}
void display(que *q)
{
    int i;
    if (isempty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("\nQueue Elements :\n");
    for (i = q->front; i != q->rear; i = (i + 1) % SIZE)
        printf("Name : %s\nUSN : %s\n", q->data[i].name, q->data[i].usn);
    printf("Name : %s\nUSN : %s\n", q->data[i].name, q->data[i].usn);
}

int main()
{
    que q;
    q.front = q.rear = -1;
    int choice;
    std ele;

    while (1)
    {
        printf("1. Insert\n2. Delete \n3. Display\n4. Exit");
        printf("\nEnter the choice :  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Student details(name,usn):  ");
            scanf("%s%s", ele.name, ele.usn);
            input(&q, ele);
            break;

        case 2:
            ele = del(&q);
            if (strcmp(ele.usn, "0"))
                printf("Deleted std :\nName : %s\nUSN : %s\n", ele.name, ele.usn);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
}