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

void addNode(node *head,int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->link = NULL;
    node *ptr = head;    
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newNode;
}

int main()
{
    //creating first NODE
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->data = 34;
    head->link = NULL;

    //creating second NODE
    node *current = (node *)malloc(sizeof(node));
    current->data = 45;
    current->link = NULL;
    head->link = current;

    //creating third NODE without using extra pointer
    current = (node *)malloc(sizeof(node));
    current->data = 29;
    current->link = NULL;
    head->link->link = current; 

    
    //adding a node at the end
    int value = 21; // value to be added
    addNode(head,value);
    
    printNodes(head);

}
