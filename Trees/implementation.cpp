#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}


Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data to be inserted in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data to be inserted in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void buildFromLevelOrder(Node *&root)
{
    int data;
    queue<Node *> q;
    cout << "Enter a data for root : ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left Node data for " << temp->data << " : ";
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right Node data for " << temp->data << " : ";
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 3 4 5 -1 -1 -1 -1 7 8 -1 -1 -1 9 -1 -1 
    buildFromLevelOrder(root);
    cout << endl;
    levelOrderTraversal(root);
}
