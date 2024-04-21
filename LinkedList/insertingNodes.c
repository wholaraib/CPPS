#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
};
typedef struct NODE node;

int main()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->data = 21;
    head->link = NULL;

    node *ptr = head;
    ptr = addAtEnd(ptr,43);
    ptr = addAtEnd(ptr,21);
    ptr = addAtEnd(ptr,12);

    return 0;
}