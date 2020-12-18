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

void levelOrder(node* root)
{
    if(!root)
        return;
    queue<node*> q; //make a queue of type node
    q.push(root); // push the root node
    while(!q.empty()) // while the queue isn't empty
    {
        node* curr = q.front(); // put the front element of the queue in a node and pop it
        q.pop();
        cout<<curr->data<<" "; // print its data
        if(curr->left != NULL) // if it has a left, push it into the queue
            q.push(curr->left);
        if(curr->right != NULL) // if it has a right push it into the queue
            q.push(curr->right);
    } // repeat till the queue isnt empty
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

    levelOrder(root);
}