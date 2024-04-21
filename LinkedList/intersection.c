#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE node;
node *insertAtBeginning(node *head, int ele)
{
    node *newNode = NULL;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = ele;
    newNode->next = head;
    head = newNode;
    return head;
}
void printNodes(node *head)
{
    node *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}
int length(node* head)
{
    int n = 0;
    while(head!=NULL)
    {
        n++;
        head = head->next;
    }
    return n;
}
int pointOfIntersection(node* head1,node* head2)
{   
    node *ptr1;
    node *ptr2;
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    if(l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d)
    {
        ptr1 = ptr1->next;
        if(ptr1 == NULL)
            return -1;
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data == ptr2->data)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;

}

int main()
{
    node *head1 = NULL;

    
    head1 = insertAtBeginning(head1, 2);
    head1 = insertAtBeginning(head1, 3);
    head1 = insertAtBeginning(head1, 4);
    head1 = insertAtBeginning(head1, 7);
    head1 = insertAtBeginning(head1, 11);
    head1 = insertAtBeginning(head1, 16);
    head1 = insertAtBeginning(head1, 19);

    printNodes(head1);

    node *head2 = NULL;
    head2 = insertAtBeginning(head2, 2);
    head2 = insertAtBeginning(head2, 3);
    head2 = insertAtBeginning(head2, 4);
    head2 = insertAtBeginning(head2, 12);
    head2 = insertAtBeginning(head2, 16);
    head2 = insertAtBeginning(head2, 21);
    printf("\n");
    printNodes(head2);
    printf("\n");
    int ans = pointOfIntersection(head1,head2);
    printf("%d\n",ans);
}