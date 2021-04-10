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

node* lowestCommonAncestor(node* root, node* p, node* q){
    if(!root)
        return NULL;

    if(root->data == p->data || root->data == q->data)
        return root;

    node* left = lowestCommonAncestor(root->left, p, q);
    node* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL && right == NULL)
        return NULL;

    if(left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;

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
    //function you want to exec goes here
}
