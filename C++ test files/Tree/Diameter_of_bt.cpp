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

// Diameter is just maximum height of left subtree + right subtree for any node, hence we compare that value for every node
// Just a modification on the height of a BT

int diameter(node* root, int& ans)
{
    if(!root)
        return 0;
    
    int left = diameter(root->left, ans);
    int right = diameter(root->right, ans);

    // To return the number of edges
    //ans = max(ans, left+right); //to keep track of the node(root) of the largest diameter at any time, will compare this at every node to see if there is a new one

    //return max(left,right) + 1; //this is for the running through the tree, i.e passing the value(height) at each node to its parent

    // To return the number of nodes
    int temp = max(left, right) + 1; //this is for the running through the tree, i.e passing the value(height) at each node to its parent
    int res = max(temp, 1+left+right); //max if keeping this node as root, or the runnig value
    ans = max(ans, res); //max of previous ans or res

    return temp;
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

    int ans = INT_MIN;
    diameter(root, ans);
    cout<<ans<<endl;

    //function you want to exec goes here
}