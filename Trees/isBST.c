#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
};
typedef struct NODE node;

node *createNode(int ele)
{
    node *n = NULL;
    n = (node *)malloc(sizeof(node));
    n->data = ele;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder_Traversal(node *root)
{
    if (root != NULL)
    {
        inOrder_Traversal(root->left);
        printf("%d ", root->data);
        inOrder_Traversal(root->right);
    }
}

//function to check if a given tree is a BST




int main()
{
    node *p = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(6);
    node *p3 = createNode(1);
    node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = NULL;
    p2->right = NULL;

    inOrder_Traversal(p);
     
    return 0;
}