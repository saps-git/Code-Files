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

We will check if the node is the node we want to burn, if it is, then print that node and put its childern(if any, in a queue) and
return 1 to the parent to let it know that its child is the the target. Then empty the queue and print, and repeat it.

*/


queue<node*> q;
// Utility function to print the sequence of burning nodes 
int burnTreeHelp(node* root, int target){
    if(!root)
        return 0;

    // Condition to check whether target node is found or not in a tree 
    if(root->data == target){
        cout<<root->data<<endl;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);

        return 1; // Return statements(1 to let the parent know its child is target) to prevent further function calls 
    }

    int a = burnTreeHelp(root->left, target); // if target is on left side
    if(a == 1){
        int n  = q.size();
        while(n--){
            node* temp = q.front();
            cout<<temp->data<<" "; //emptying the queue, i.e children of target
            q.pop();
            if(temp->left) //if those children also have children then store them
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(root->right) //if the node has a right child then add to queue for later
            q.push(root->right);
            
        cout<<root->data<<endl; //print the node
        return 1; 
    }

    int b = burnTreeHelp(root->right, target); //same for the right side
    if(b == 1){
        int n = q.size();
        while(n--){
            node* temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(root->left)
            q.push(root->left);

        cout<<root->data<<endl;    
        return 1;
    }
    return 0;
}

void burnTree(node* root, int target){
    burnTreeHelp(root, target); //calling the helper function 

    while(!q.empty()){ //then emptying the rest of the queue like done earlier
        int n = q.size();
        while(n--){
            node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL) 
                q.push(temp->left);  
            if(temp->right != NULL) 
                q.push(temp->right); 
        }
        cout<<endl;
    }

}

int main(){
    node* root = NULL;
    freopen("./CodeSamples/input.txt","r",stdin);
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        root = insert(root, x);
    }

    int target = 40;
    burnTree(root, target);
}