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

node* lowestCommonAncestor(node* root, int p, int q){
    if(root->data > p && root->data > q)
        return lowestCommonAncestor(root->left, p, q);

    else if(root->data < p && root->data < q)
        return lowestCommonAncestor(root->right, p, q);

    else
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

    node* ans = lowestCommonAncestor(root, 13, 30);
    cout<<ans->data<<endl;

    //function you want to exec goes here
}