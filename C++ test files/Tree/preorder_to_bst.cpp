//Don't run here or it will crash, go to LEETCODE #1008

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x): data(x), left(NULL), right(NULL) {}
};

node* bstFromPreorder(const vector<int>& preorder, int& pos, int min, int max)
{
    if(pos == (int) preorder.size() || preorder[pos] < min || preorder[pos] > max)
        return NULL; // if the value that we want to add to the tree is out of bounds with the min & max we set then return NULL

    int val = preorder[pos];
    node* root = new node(val); //else create a new node
    pos++; // increment the position in the vector for the element that we want add to the tree

    root->left  = bstFromPreorder(preorder, pos, min, val); // add the element to the left subtree
    root->right = bstFromPreorder(preorder, pos, val, max); // add the element to the right subtree

    return root;
}

void levelOrder(node* root)
{
    if(!root)
        return;
    queue<node*> q; 
    q.push(root); 
    while(!q.empty())
    {
        node* curr = q.front(); 
        cout<<curr->data<<" "; 
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL) 
            q.push(curr->right);
    } 
}

int main()
{
    vector<int> preorder = {8,5,1,7,10,12};
    int pos = 0;
    node* ans = bstFromPreorder(preorder, pos, 0, INT_MAX);
    levelOrder(ans);
}