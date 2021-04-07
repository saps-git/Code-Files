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

// log(n) as on every step we check for if the target is smaller or greater than value at the root
int closestValHelp(node* root, int target, int val)
{
    if(!root)
        return val;

    if(abs(target - val) > abs(target - root->data)); 
        val = root->data;

    if(root->data > target)
        return closestValHelp(root->left, target, val);

    else if(root->data < target)
        return closestValHelp(root->right, target, val);

    return val;
}

int closestVal(node* root, int target)
{
    return closestValHelp(root, target, INT_MAX);
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

    int target = 31;
    cout<<closestVal(root, target)<<endl;

    //function you want to exec goes here
}