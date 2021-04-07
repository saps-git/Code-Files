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

void pathSum(node* root, int sum, vector<int> vec, vector<vector<int>>& ans){
    if(!root)
        return;
    
    vec.push_back(root->data);
    sum -= root->data;
    
    if(!root->left && !root->right && sum == 0){
        ans.push_back(vec);
        return;
    }
    
    pathSum(root->left, sum, vec, ans);
    pathSum(root->right, sum, vec, ans);
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

    vector<vector<int>> ans;
    vector<int> vec;
    pathSum(root, 100, vec, ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    //function you want to exec goes here
}
