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

bool isBst(node* root, int min, int max)
{
    if(!root)
        return true;

    if(root->data > min && root->data < max)
        return (isBst(root->left, min, root->data) && isBst(root->right, root->data, max));
    
    return false;
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

    cout<<isBst(root, 0, INT_MAX)<<endl;
    //function you want to exec goes here

}