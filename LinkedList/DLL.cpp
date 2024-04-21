#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;
    node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(node *&head, int d)
{
    node *newNode = new node(d);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(node *&head, int d)
{
    node *temp = head;
    node *newNode = new node(d);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAtPosition(node *&head, int d, int pos)
{
    // if we want to add a node in the front itself
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    
    int iterIndex = 1;
    node *temp = head;
    //pointing my temp to desire position
    while (iterIndex != pos - 1)
    {
        iterIndex++;
        temp = temp->next;
    }
    // if we want to add a node at the end
    if(temp -> next == NULL)
    {
        insertAtTail(head,d);
        return;
    }
    //if we want to add a node in the middle somewhere
    node *newNode = new node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = new node(2);

    // inserting values at Head
    insertAtHead(head, 3);
    insertAtHead(head, 6);
    print(head);
    insertAtTail(head, 5);
    insertAtTail(head, 9);
    print(head);

    insertAtPosition(head,100,3);
    insertAtPosition(head,12,7);
    print(head);
    return 0;
}

