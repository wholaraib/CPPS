#include <stdio.h>
#include <stdlib.h>
struct NODE
{   
    int data;
    struct node *next;
};
typedef struct NODE node;
node* insertAtFirst(node *head, int val)
{
    node *newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = head;
    printf("\nNode with value %d is inserted as first node in the list.", val);
    return newnode;
}
node* insertAtLast(node *head, int val)
{
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\nNode with value %d is inserted as the last node in the list", val);
    return head;
}
node* delAtFirst(node *head)
{
    node *temp;
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        temp = head;
        head = head->next;
        printf("First node with value %d is deleted", temp->data);
        free(temp);
    }
    return head;
}
node* delLastNode(node *head)
{
    node *temp = NULL;
    node *prev = NULL;
    if (head == NULL)   
        printf("\nEmpty List");
    else
    {
        temp = head;
        {
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
        }
        if (prev == NULL)
            head = NULL;
        else
            prev->next = NULL;
        printf("\nLast Node with info %d is deleted", temp->data);
        free(temp);
    }
    return (head);
}
void display(node *head)
{
    if (head == NULL)
    {
        printf("\nEmpty List");
        return;
    }
    printf("\nListContents : \n");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    node* head = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1 : Insert at first\n");
        printf("2 : Insert at end\n");
        printf("3 : Delete at first\n");
        printf("4 : Delete at end\n");
        printf("5 : Display\n");
        printf("6 : EXIT\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d",&data);
            head = insertAtFirst(head, data);
            break;
        case 2:
            printf("\nEnter the data to be inserted : ");
            scanf("%d",&data);
            head = insertAtLast(head, data);
            break;
        case 3:
            head = delAtFirst(head);
            break;
        case 4:
            head = delLastNode(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("...EXITING...");
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}