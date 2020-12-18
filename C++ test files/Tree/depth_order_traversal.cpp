#include<bits/stdc++.h>
using namespace std;
struct node
{
     int data;
     node* left;
     node* right;
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

void preorder(node* root)
{
    if(!root)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(!root)
        return; 

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root)
{
    if(!root)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = NULL;
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        root = insert(root, x);
    }

    cout<<"PREORDER"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"INORDER"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"POSTORDER"<<endl;
    postorder(root);
    cout<<endl;
}