#include<bits/stdc++.h>
using namespace std;

// LCA in a BST with all unique values

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

node* lowestCommonAncestor(node* root, int p, int q){
    if(root->data > p && root->data > q) //if both values are less than root, i.e they are present in left side of the root
        return lowestCommonAncestor(root->left, p, q); //hence we move to left
    else if(root->data < p && root->data < q) //if both values are more than root, i.e they are present in right side of the root
        return lowestCommonAncestor(root->right, p, q); //hence we move to right
    else //the node on which the disperse is the answe
        return root;
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

    node* ans = lowestCommonAncestor(root, 15, 40);
    cout<<ans->data<<endl;
}