#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct NODE{
        int data;
        struct NODE *link;
    };
    typedef struct NODE node;

    node *head = NULL;

    head = (node *)malloc(sizeof(node));
    head->data = 34;
    head->link = NULL;
    printf("%d\n",head->data);
    printf("%s\n",head->link);
}
