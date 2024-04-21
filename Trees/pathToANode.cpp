#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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


node *buildTree(node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data to be inserted in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data to be inserted in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void buildFromLevelOrder(node *&root)
{
    int data;
    queue<node *> q;
    cout << "Enter a data for root : ";
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the left node data for " << temp->data << " : ";
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right node data for " << temp->data << " : ";
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
bool pathToANode(node* root, vector <int> &path, int node)
{
    if(!root) return false;
    path.push_back(root->data);

    if(root->data == node) return true;
    
    bool left = pathToANode(root->left,path,node);
    bool right = pathToANode(root->right,path,node);
    if(left || right) return true;
    path.pop_back();
    return false;
}
void print(vector <int> arr)
{
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    node *root;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1
    // 1 2 7 3 6 -1 -1 -1 4 -1 -1 5 -1 -1 -1
    // 1 2 3 4 5 -1 -1 -1 -1 7 8 -1 -1 -1 9 -1 -1 
    // 6 2 8 0 4 7 9 -1 -1 3 4 -1 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    cout << endl;
    levelOrderTraversal(root);
    
    vector <int> path;
    int node = 2;
    pathToANode(root,path,node);
    cout << endl << endl;
    print(path);
}
