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
void insertInBST(node* root, int key)
{
    node* prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(root->data == key)
        {
            printf("Element cannot be inserted\n");
            break;
        }
        else if(root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    node *ptr = createNode(key); 
    if(key < prev->data)
        prev->left = ptr;
    else
        prev->right = ptr;
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


    //before insertion
    inOrder_Traversal(p);
    printf("\n");

    //after insertion
    int key = 9;
    insertInBST(p,key);
    inOrder_Traversal(p);

    // printf("%d\n",p->right->right->data);
    return 0;
}