#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
};
typedef struct NODE node;
void printNodes(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr = ptr->link;
    }
}
int main()
{   
    //first node
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;

    //second node
    node *current = NULL;
    current = (node *)malloc(sizeof(node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    //third node
    current = (node *)malloc(sizeof(node));
    current->data = 32;
    current->link = NULL;
    head->link->link = current;
    printNodes(head);
    return 0;
}