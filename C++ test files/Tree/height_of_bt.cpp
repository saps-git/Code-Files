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

int height(node* root)
{
    if(!root)
        return 0;
    
    int left = height(root->left); //height of left tree
    int right = height(root->right); //height of right tree

    return max(left, right) + 1; // taking the max of it, and adding 1 while returning at every parent node
}

int main()
{
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

    cout<<height(root)<<endl;
    //function you want to exec goes here
}