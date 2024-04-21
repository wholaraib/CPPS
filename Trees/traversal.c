#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE* left;
    struct NODE* right;
};
typedef struct NODE node;

/*Tree representation of our data

        7
      /   \
     /     \
    5      10
   / \    /  \
  0   6  9   13

*/
    

node* create_node(char ele)
{
    node *n;
    n = (node*)malloc(sizeof(node));
    n->data = ele;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder_traversal(node *root)
{

    //root -> left node -> right node
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder_traversal(root->left);
        preOrder_traversal(root->right);
    }
    return;
}
void postOrder_traversal(node *root)
{
    // left node -> right node -> root

    if(root!=NULL)
    {
        postOrder_traversal(root->left);
        postOrder_traversal(root->right);
        printf("%d ",root->data);
    }
    return;
}
void inOrder_traversal(node *root)
{
    // left node -> root -> right node 

    if(root!=NULL)
    {
        inOrder_traversal(root->left);
        printf("%d ",root->data);
        inOrder_traversal(root->right);
        
    }
    return;
}
int main()
{
    //creating each node
    node *p = create_node(7);
    node *p1 = create_node(5);
    node *p2 = create_node(10);
    node *p3 = create_node(0);
    node *p4 = create_node(6);
    node *p5 = create_node(9);
    node *p6 = create_node(13);


    //linking nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p3->left = NULL;
    p3->right = NULL;
    p4->left = NULL;
    p4->right = NULL;


    //printing nodes with each traversal
    printf("Pre Order traversal\n");
    preOrder_traversal(p);
    printf("\nPost Order traversal\n");
    postOrder_traversal(p);
    printf("\nIn Order traversal\n");
    inOrder_traversal(p);

    return 0;

}

