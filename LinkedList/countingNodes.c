#include <stdio.h>
#include <stdlib.h>
struct NODE{
        int data;
        struct NODE *link;
    };
typedef struct NODE node;
void countNodes(struct NODE *head)
{
    int count = 0;
    if(head == NULL)
    {
        printf("Linked List is empty\n");
        exit(0);
    }
    node *ptr = head;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("Count = %d\n",count);
}
int main()
{
    //creating first NODE
    struct NODE *head = NULL;
    head = (struct NODE *)malloc(sizeof(struct NODE));
    head->data = 34;
    head->link = NULL;

    //creating second NODE
    struct NODE *current = (struct NODE *)malloc(sizeof(struct NODE));
    current->data = 45;
    current->link = NULL;
    head->link = current;

    //creating third NODE without using extra pointer
    current = (struct NODE *)malloc(sizeof(struct NODE));
    current->data = 29;
    current->link = NULL;
    head->link->link = current; 
    countNodes(head);
    // printf("Number of Nodes are %d\n",count);

}
