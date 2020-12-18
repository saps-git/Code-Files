#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
};

node* insert(node* root, int data){
	if(!root){
		root = new node();
		root->val = data;
		root->left = root->right = NULL;
	}

	else if(data <= root->val)
		root->left = insert(root->left, data);

	else
		root->right = insert(root->right, data);

	return root;
}

void nodeDepth(node* root, int depth, int& sum){
	sum += depth;
	
	if(!root->left || !root->right)
		return;

	nodeDepth(root->left, depth+1, sum);
	nodeDepth(root->right, depth+1, sum);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	node* root = NULL;
	freopen("./CodeSamples/input.txt", "r", stdin);

	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		root = insert(root, x);
	}

	int sum = 0;
	nodeDepth(root, 0, sum);
	cout<<sum<<endl;

}





