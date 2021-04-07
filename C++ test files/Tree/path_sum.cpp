//determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

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

bool hasPathSum(node* root, int sum) {
    if(!root)
        return false;
    
    sum -= root->data;
    if(!root->left && !root->right && sum == 0)
        return true;
    
    return hasPathSum(root->left, sum) || hasPathSum(root->right,sum);
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

    int sum = 180;
    hasPathSum(root, sum) ? cout<<"true" : cout<<"false";
    cout<<endl;
    //function you want to exec goes here
}
