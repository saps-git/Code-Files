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

/*

There are three cases here, 

1) current node is in the straight path for max sum.
2) current node you are on is the root for the max sum.
3) current node isn't in the path of the max sum.

*/

// O(n)

int max_sum(node* root, int &result)
{
    if(!root)
        return 0;

    int left = max_sum(root->left, result);
    int right = max_sum(root->right, result);

    int max_straight = max(max(left,right)+root->data, root->data); // case 1
    int max_root = max(root->data + (left+right), max_straight); // comparing case 1 and case 2
    result = max(result, max_root); // taking the max of the stored result and the max of case 1 and case 2

    return max_straight; // returning max_straight, as we want to traverse the whole tree
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

    int result = INT_MIN;
    max_sum(root, result);
    cout<<result<<endl;
    //function you want to exec goes here
}