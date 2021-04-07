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

bool validSeq(node* root, const vector<int>& vec, int pos, int size)
{
    if(!root)
        return false;
    else if(root->data != vec[pos]) //if value at node doesn't matches that of the arr, return false
        return false;
    else if(pos == size) // if pos is goes over the last index of arr
        return false;
    else if(!root->left && !root->right && pos == size-1) // if there is no left or right of the current node(it is leaf) and pos is also the last element of the array, return true
        return true;

    return (validSeq(root->left, vec, pos+1, size) || validSeq(root->right, vec, pos+1, size)); // traversing left and right,with OR as true should be returned in either one of them, also incr the pos counter every time 
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

    vector<int> vec = {50,20,12,18};
    int size = vec.size();
    validSeq(root, vec, 0, size) ? cout<<"true" : cout<<"false";
    cout<<endl;
    //function you want to exec goes here
}