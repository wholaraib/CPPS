
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    ;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *middle(node *h1)
{
    node *slow = h1;
    node *fast = h1->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *merge(node *h1, node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;
    if (h1 == NULL && h2 == NULL)
        return NULL;
    node *c1 = h1;
    node *c2 = h2;

    if (c1->data <= c2->data)
    {
        c1->next = merge(c1->next, c2);
        return h1;
    }
    else
    {
        c2->next = merge(c2->next, c1);
        return h2;
    }
}
node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *mid = middle(head);
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node *ans = merge(left, right);
    return ans;
}

void insertAtHead(node *&head, int d)
{
    node *newNode = new node(d);
    // newNode->data = d;
    newNode->next = head;
    head = newNode;
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
    node* head = new node(9);
    
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,1);
    insertAtHead(head,7);
    insertAtHead(head,2);
    print(head);
    head = mergeSort(head);
    print(head);
    return 0;


}