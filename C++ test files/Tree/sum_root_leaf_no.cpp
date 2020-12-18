#include<bits/stdc++.h>
using namespace std;

// Run in LEETCODE #129
/*explanation :-

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number

Input: [4,9,0,5,1]
     4
    / \
   9   0
  / \
 5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

*/
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

int ans = 0; //final answer var
void sumNumbers(node* root, int sum) {
    if(!root) //if no node then just simply return (helps when there is only root, and one child)
        return;

    sum = sum*10 + root->data; //adding a node value to form a digit

    if(!root->left && !root->right){ //if it is a leaf node
        ans += sum; //add the current digit to the final sum, 
        return;     // and return
    }

    sumNumbers(root->left, sum); 
    sumNumbers(root->right, sum);
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
    sumNumbers(root, 0);
    cout<<ans<<endl;
    //function you want to exec goes here
}