// Two nodes are cousins of each other if they are at same level and have different parents.

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

int cousinsUtil(node* root, int val, int& par, int height)
{
    if(!root)
        return 0;

    if(root->data == val) // return total height if you find the value in the tree
        return height;

    par = root->data; // else make the curr node as parent (for next call)
    int height_left = cousinsUtil(root->left, val, par, height+1); // calling left, and storing the height
    if(height_left) // if height is not 0, then return height
        return height_left;

    // if height is 0
    
    par = root->data;
    int height_right = cousinsUtil(root->right, val, par, height+1); // call for the right side
    return height_right;
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

    int x = 30;
    int y = 80;

    if(root->data == x || root->data == y)
        cout<<false;

    int x_par = -1; //initializing the parents as -1
    int x_height = cousinsUtil(root, x, x_par, 0);

    int y_par = -1;
    int y_height = cousinsUtil(root, y, y_par, 0);

    if(x_par != y_par && x_height == y_height) // same height different parents 
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    //function you want to exec goes here
}