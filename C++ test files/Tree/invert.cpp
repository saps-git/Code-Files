#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node* insert(node* root, int data) 
{
    if(!root)
    {
        root = new node();
        root->data = data;
        root->left = root->right = NULL; 
    }
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void inorder(node* root){
    if(!root)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void invertTree(node* root)
{
    if(!root)
        return;

    invertTree(root->left);
    invertTree(root->right);
    // after both recursion, we will return to the parent of leaf nodes

    // just swap the left and right pointer for every child
    node* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    node* root = NULL;
    freopen("./CodeSamples/input.txt","r",stdin);
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        root = insert(root, x);
    }

    invertTree(root);
    inorder(root);
}