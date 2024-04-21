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
node *searchInBST(node *root, int key)
{
    //recursive approach
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (root->data > key)
        return searchInBST(root->left, key);
    else
        return searchInBST(root->right, key);
}

node *iterativeSearchInBST(node *root, int key)
{
    //iterative Approach
    while(root!=NULL)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
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

    // inOrder_Traversal(p);

//key to be searched
    int key = 5;


//Recursive Approach
    node *result = searchInBST(p, key);
    printf("\nRecursive Approach");
    if(result!=NULL)
        printf("\n%d = %d\nElement found", key, result->data);
    else
        printf("\nElement not found\n");


    printf("\n\n");


//Iterative Approach
    node *ans = iterativeSearchInBST(p, key);
    printf("Iterative Approach");
    if(ans!=NULL)
        printf("\n%d = %d\nElement found", key, ans->data);
    else
        printf("\nElement not found\n");

    return 0;
}