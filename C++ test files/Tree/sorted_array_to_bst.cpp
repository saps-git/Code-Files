#include<bits/stdc++.h>
using namespace std;
/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node 
never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

struct node
{
    int data;
    node *left;
    node *right;
};

node* constructTree(vector<int> vec, int start, int end) 
{
    if(start > end) //boundry case
        return NULL;

    int mid = start + (end - start) / 2; //getting the mid (this way we don't get integer overflow)
    node* root = new node(); //making a new node,
    root->data = vec[mid];   // and adding the mid element of that vector as the node

    root->left = constructTree(vec, start, mid-1); //calling for left with new start and end values
    root->right = constructTree(vec, mid+1, end); //calling for right with new start and end values

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
	
    vector<int> vec = {-10,-3,0,5,9};
    node* root = constructTree(vec, 0, vec.size()-1); //will do a binary search, hence passing the left and right values
    inorder(root);

    
    //function you want to exec goes here
}