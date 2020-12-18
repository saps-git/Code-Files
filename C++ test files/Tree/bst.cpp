#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int data)
{
    if(root == NULL) //if tree is empty
        root = newNode(data);
    
    else if(data < root->data)
        root->left = insert(root->left, data);

    else
        root->right = insert(root->right, data);

    return root; 
}

bool Search(node* root, int data)
{
    if(root == NULL)
        return false;
    
    else if(root->data == data)
    {
        cout<<root->data<<" ";
        return true;
    }

    else if(data <= root->data)
        return Search(root->left, data);

    else
        return Search(root->right, data);
}

int findMin(node* root)
{
    if(root->left == NULL)
        return root->data;
    
    return findMin(root->left);

    //iterative
    /*
    if(root == NULL)
    {
        cout<<"tree empty"<<endl;
        return -1;
    }
    while(root->left != NULL)
        root = root->left;
    
    return root->data;
    */
}

int findMax(node* root)
{
    /*
    if(root->right == NULL)
        return root->data;

    return findMax(root->right);
    */

    //iterative
    if(root == NULL)
    {
        cout<<"tree empty"<<endl;
        return -1;
    }
    while(root->right != NULL)
        root = root->right;
    
    return root->data;
}

int Findheight(node* root)
{
    if(!root)
        return -1; //as in height we count the no of edges, so to subtract the last edge, that is the null edge
    
    //maximum of the left and right subtree is the height of the tree
    return max(Findheight(root->left), Findheight(root->right)) + 1; // +1 for the edge connecting the left or right subtrees to the root
}

int main()
{
    freopen("./CodeSamples/input.txt","r",stdin);

    node* root = NULL; //making a root node, that is empty ( creating a empty tree)
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        root = insert(root,a);
    }

    int num;
    cin>>num;

    if(Search(root,60) == true )
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    cout<<"min node "<<findMin(root)<<endl;
    cout<<"max node "<<findMax(root)<<endl;

    cout<<"height "<<Findheight(root)<<endl; // no of edges between the root node and the farthest leaf node
}

/*    THE TREE
       
       50
     /    \
    20    70 
   / \   /  \
  10 40 60  80 
 /  \
5   15 

*/