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

void inorder(node* root) //to print
{
    if(!root)
        return; 

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    
    cout<<branchSum(root);
    
    

    //function you want to exec goes here
}