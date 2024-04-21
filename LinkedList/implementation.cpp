#include <iostream>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *next;

    //constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};
void insertAtHead(node* &head, int d)
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

void insertAtTail(node *&head, int d)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *newNode = new node(d);
    temp->next = newNode;
}

void insertAtPosition(node *&head, int pos, int d)
{
    if (pos == 1) // if we are inserting at the starting
    {
        insertAtHead(head, d);
        return;
    }
    // inserting at position p
    int iterPos = 1;
    node *temp = head;
    while (iterPos != pos - 1)
    {

        iterPos++;
        temp = temp->next;
    }
    node *newNode = new node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(node *&head, int pos)
{
    node *temp = head;
    int iterIndex = 1;
    if (pos == 1) // if first node is being deleted
    {
        head = head->next;
        free(temp);
        temp = NULL;
        return;
    }

    node *prev = NULL;
    while (iterIndex != pos)
    {
        prev = temp;
        temp = temp->next;
        iterIndex++;
    }
    prev->next = temp->next;
    temp->next = NULL;
    free(temp);
    temp = NULL;
}

bool isCircular(node *head)
{
    node *temp = head->next;
    if (head == NULL)
    {
        return true;
    }
    if (head->next == NULL)
    {
        return false;
    }
    while (temp->next != NULL && temp->next != head)
    {
        temp = temp->next;
    }
    if (temp->next == head)
        return true;
    return false;
}
// loop detection
bool detectLoop(node *head)
{
    if (head == NULL)
        return false;
    map<node *, bool> visited;
    node *temp = head;
    bool i;
    while (temp != NULL)
    {
        if (visited[temp] == true)
            return true;
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
node *floydsLoopDetectionAlgo(node *head)
{
    if (head == NULL)
        return NULL;
    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}
node *getStartingNodeOfLoop(node *head)
{
    if (head == NULL) // empty list
        return NULL;
    // getting point of intersection of slow and fast pointer inside the loop
    node *intersectioNode = floydsLoopDetectionAlgo(head);
    if (intersectioNode == NULL)
        return NULL;
    node *slow = head;
    while (slow != intersectioNode)
    {
        slow = slow->next;
        intersectioNode = intersectioNode->next;
    }
    return slow;
}
void removeTheLoop(node *head)
{
    if (head == NULL)
        return;
    node *startingOfLoop = getStartingNodeOfLoop(head);
    if (startingOfLoop == NULL)
        return;
    node *temp = startingOfLoop;

    while (temp->next != startingOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
      // creating the first node
      node *head = new node(2);
      // print(head);
    //   cout << head->next->data << endl;


      // inserting a node at the beginning of the SLL
      insertAtHead(head, 3);
      // print(head);

      // inserting a node at the End of the SLL
      insertAtTail(head, 11);
      // print(head);

      // inserting a node at position p of the SLL
      insertAtPosition(head, 3, 22);
      // print(head);

      // inserting at head
      insertAtPosition(head, 1, 31);
      // print(head);

      // inserting a node at the End of the SLL
      insertAtTail(head, 88);
      // print(head);

      // deleting the node at position p
      // deleteNode(head, 6);
      print(head);

      // making a loop in a linked list
      head->next->next->next = head->next;

      // checking if loop exists
      //Approach 1:

      //  cout << detectLoop(head) << endl;  //this function takes extra space as we use maps

      //Approach 2:
      if (floydsLoopDetectionAlgo(head) != NULL) // floyds algo doesn't take extra space
          cout << "Loop exist" << endl;
      else
          cout << "Loop doesn't exist" << endl;


      // getting starting node of the loop

      node *startingNodeOfLoop = getStartingNodeOfLoop(head);
      cout << "Starting node of the loop has data " << startingNodeOfLoop->data << endl;

      //removing the loop from linkedlist
      removeTheLoop(head);

      if (floydsLoopDetectionAlgo(head) != NULL)
          cout << "Loop exist" << endl;
      else
          cout << "Loop doesn't exist" << endl;

    cout << endl << endl;
    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;
    
    return 0;
}
