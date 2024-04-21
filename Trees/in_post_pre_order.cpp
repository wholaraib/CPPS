#include <iostream>
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
void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
// void inOrderTraversalIterative(node* root)
// {

// }
// void preOrderTraversalIterative(node* root)
// {

// }
// void postOorderTraversalIterative(node* root)
// {

// }
void preOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    cout << "\nIn Order traversal" << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Pre Order traversal" << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "Post Order traversal" << endl;
    postOrderTraversal(root);
    cout << endl;
}