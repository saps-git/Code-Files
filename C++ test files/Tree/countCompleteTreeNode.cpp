/*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, 
and all nodes are as far left as possible.
*/

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

// can also be done by DFS techniques, but it will be O(n)

// O(logN * logN)

// will check if depth of both left and right side is equal, if not then will go to either left or right child node
// and do the process again, if they are equal(full binary tree i.e all nodes filled) they will return the number of nodes by 
// pow(2, no. of levels)-1

int countNodes(node* root){
    if(!root)
        return 0;

    int left_lv = 1; // counter to count the levels, 1 as the node itself is counted
    node* l = root->left;
    while(l){ 
        l = l->left;
        left_lv += 1;
    }

    int right_lv = 1; // counter to count the levels, 1 as the node itself is counted
    node* r = root->right;
    while(r){
        r = r->right;
        right_lv += 1;
    }

    if(left_lv == right_lv) // if they are equal total number of nodes for that subtree will be returned and no further checking for that subtree is required
        return pow(2, left_lv)-1;

    return 1 + countNodes(root->left) + countNodes(root->right); // 1 is added for root node
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

    cout<<countNodes(root)<<endl;
}