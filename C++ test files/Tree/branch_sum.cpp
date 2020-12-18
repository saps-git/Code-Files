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

// O(n) time and space
// A running sum will be kept track for every brach, which will be added to the resultant vector on reaching the leaf node of that brach 
void branchSum(node* root, int sum, vector<int>& vec)
{
    sum += root->data; 

    if(!root->left && !root->right) // if it doesnt have any left or right (leaf node)
    {
        vec.push_back(sum); // then add the current running sum to the vector
        return;
    }

    branchSum(root->left, sum, vec);
    branchSum(root->right, sum, vec);
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

    vector<int> vec;
    branchSum(root, 0, vec);
    for(int i: vec)
        cout<<i<<"\n";
    cout<<endl;
    //function you want to exec goes here
}