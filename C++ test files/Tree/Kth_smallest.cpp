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

//O(n) with O(n) space
//doing an inorder traversal and storing all the values in a vector, then looking for the desired element
/*
void kthElement(node* root, vector<int>& vec)
{
    if(!root)
        return;

    kthElement(root->left, vec);
    vec.push_back(root->data);
    kthElement(root->right, vec);
}
*/

//O(n) with no extra space
//decreasing k everytime a node is visited and it returns 0 on the left side, while doing a inorder traversal
int kthSmallest(node* root, int& k)
{
    if(!root)
        return 0;

    int left = kthSmallest(root->left, k);
    if(left) //if left is not zero, that means we have found the element on the left and return it 
        return left;

    k -= 1; // decrease k if not found on left, which means k is not a element less than it
    if(k==0)
        return root->data; // when k reaches to zero return the data of that node

    int right = kthSmallest(root->right, k); // if not in left search in right side
    return right;
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

    int k = 2;
    //vector<int> vec;
    //kthElement(root, vec);
    //cout<<vec[k-1]<<endl;


    cout<<kthSmallest(root,k)<<endl;
}