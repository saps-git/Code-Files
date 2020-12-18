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
//applying bfs and storing the last value of every level in the output vector
vector<int> rightSideView(node* root){
    vector<int> ans;
    if(!root)
        return ans;

    queue<node*> q; 
    q.push(root);//pushing root
    while(!q.empty()){
        int size = q.size(); //size will indicate total number of nodes on an level
        for(int i=0;i<size;i++){
            node* temp = q.front();
            q.pop();
            if(i == size-1) //if i is the last element, then push node to the output vector
                ans.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

    return ans;
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

    vector<int> vec = rightSideView(root);
    for(int i: vec)
        cout<<i<<" ";
    cout<<endl;
}