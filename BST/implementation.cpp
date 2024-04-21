#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertIntoBST(Node* root, int data)
{
    if(!root)
    {
        root  = new Node(data);
        return root;
    }
    if(data > root->data) root->right = insertIntoBST(root->right,data);
    else root->left = insertIntoBST(root->left,data);

    return root;
}
void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data!=-1)
    {
        root = insertIntoBST(root,data);
        cin >> data;
    }
    
}
void levelOrderTraversal(Node* root)
{
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp  = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
    }
}
void inorderTraversal(Node* root,vector <int> &ans)
{
    if(root == NULL) return;
    inorderTraversal(root->left,ans);
    ans.push_back(root->data);
    inorderTraversal(root->right,ans);
}
void print(vector <int> arr)
{
    int n = arr.size();
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void inorderStore(Node* root, vector <Node* > &inorderPath)
{
    if(root == NULL) return;
    inorderStore(root->left,inorderPath);
    inorderPath.push_back(root);
    inorderStore(root->right,inorderPath);
}
Node* makeBalancedTree(vector <Node* > &inorderPath,int s, int e)
{
    if(s > e) return NULL;
    int m = s + (e - s)/2;
    Node* root = new Node(inorderPath[m]->data);
    root->left = makeBalancedTree(inorderPath,s,m-1);
    root->right = makeBalancedTree(inorderPath,m+1,e);
    return root;
    
}
Node* balancedBst(Node* root) 
{
    vector <Node*> inorderPath;
    inorderStore(root,inorderPath);
    
    int s = 0;
    int e = inorderPath.size() - 1;
    return makeBalancedTree(inorderPath,s,e);

}

int main()
{   
    // 6 2 8 0 4 7 9 -1 -1 3 4 -1 -1 -1 -1 -1 -1 -1 -1 
    Node* root = NULL;
    cout << "Enter the data to be Inserted in the BST : ";
    takeInput(root);
    // levelOrderTraversal(root);
    vector <int> ans;
    inorderTraversal(root,ans);
    
    

}