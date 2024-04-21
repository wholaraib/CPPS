#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct NODE{
        int data;
        struct NODE *link;
    };
    //creating first NODE
    struct NODE *head = NULL;
    head = (struct NODE *)malloc(sizeof(struct NODE));
    head->data = 34;
    head->link = NULL;
    printf("%d\n",head->data);

    //creating second NODE
    struct NODE *current = (struct NODE *)malloc(sizeof(struct NODE));
    current->data = 45;
    current->link = NULL;
    head->link = current; // storing the address of 2nd NODE in the link of first NODE
    printf("%d\n",current->data);
}
