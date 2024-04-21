#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
typedef struct node NODE;
int isEmpty(NODE *head)
{
    if (head == NULL)
        return 1;
    return 0;
}
// INSERTION
NODE *insert(NODE *head, int n)
{
    NODE *newN = malloc(sizeof(NODE));
    newN->val = n;
    newN->next = NULL;
    if (head == NULL)
    {
        head = newN;
        head->next = head;
    }
    NODE *t = head;
    while (t->next != head)
    {
        t = t->next;
    }
    t->next = newN;
    newN->next = head;
    return head;
}
// DELETION
NODE *remov(NODE *head)
{
    if (isEmpty(head))
    {
        printf("QUEUE UNDERFLOW!!!\n");
        return NULL;
    }
    if (head->next == head)
    {
        printf("DELETED ELEMENT : %d\n", head->val);
        free(head);
        return NULL;
    }
    NODE *t = head;
    NODE *p = head;
    while (t->next != head)
    {
        t = t->next;
    }
    head = head->next;
    t->next = head;
    printf("DELETED ELEMENT = %d\n", p->val);
    free(p);
    return head;
}
// DISPLAY
void display(NODE *head)
{
    if (head == NULL)
    {
        printf("QUEUE IS EMPTY!!\n");
        return;
    }
    NODE *t = head;
    printf("FRONT-->\t");
    do
    {
        printf("%d\t", t->val);
        t = t->next;
    } while (t != head);
    printf("<--REAR\n");
}
int main()
{
    NODE *head = NULL;
    int c, n;
    printf("1)INSERT\n2)DELETE\n3)DISPLAY\n4)EXIT\n");
    while (1)
    {
        printf("Enter Choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("ENTER ELEMENT\n");
            scanf("%d", &n);
            head = insert(head, n);
            break;
        case 2:
            head = remov(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("INVALID CHOICE\n");
        }
    }
}
