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

node* lowestCommonAncestor(node* root, node* p, node* q){
    if(root->data > p->data && root->data > q->data) //if both values are less than root, i.e they are present in left side of the root
        return lowestCommonAncestor(root->left, p, q); //hence we move to left
    else if(root->data < p->data && root->data < q->data) //if both values are more than root, i.e they are present in right side of the root
        return lowestCommonAncestor(root->right, p, q); //hence we move to right
    else //the node on which the disperse is the answer
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

    node* p = new node();
    p->data = 18;
    node* q = new node();
    q->data = 60;
    node* ans = lowestCommonAncestor(root, p, q);
    cout<<ans->data<<endl;
}