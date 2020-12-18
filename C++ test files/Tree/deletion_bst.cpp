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

void inorder(node* root){
    if(!root)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* findMin(node* root){ // helper function to find leftmost value to replace a node with two childs
    while(root->left)
        root = root->left;
    
    return root;
}

//O(log(n)) or O(n)
node* deleteNode(node* root, int x){
    if(!root)
        return root;
    
    else if(x < root->data) // search for the node in left
        root->left = deleteNode(root->left, x);
    else if(x > root->data) // search for the node in left
        root->right = deleteNode(root->right, x);

    else{ // when you find the node

        // Case 1:  No child
        if(!root->left && !root->right){ 
            delete root; // delete the node
            root = NULL; // change the value to null for parent to point
        }
        //Case 2(a): One child(no left child)
        else if(!root->left){
            node* temp = root; //storing that nodes in the info 
            root = root->right; //now storing its right childs value in it
            delete temp; // deleting that node's value from temp
        }
        //Case 2(b): One child(right)
        else if(!root->right){
            node* temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else{
            node* temp = findMin(root->right); // find the min on the right subtree
            root->data = temp->data; // replace its data with the node
            root->right = deleteNode(root->right, temp->data); // delete that min node from right subtree
        }

    }

    return root;    
}

//DOUBT
/* 
Q.  How are you making sure that once the node to be is deleted, is deleted and the link to its parent is still maintained now between the child of the node deleted and its parent ?
    More specifically,
    else if(root->left == NULL) {
    struct Node *temp = root;
    root = root->right;
    delete temp;
    }

ANS. After deleting the temp, what about the link between temp's parent and current root ? I am little confused here.


    That's why the Delete function has a return statement. It's returning the same node that's being deleted, which is most of the time is NULL.

    For example, let say we're deleting node 11. A recursive function ended up in node 10, line 20. The root in this context is the node 10 itself.

    line 20: root(node10)->right = Delete(root->right(node11), 11)

    Here, the Delete function is called again and the root in this context become node 11. Since node 11 has no child, the logic ends up on line 24. The root is deleted and set to NULL.

    This NULL value is then returned to the earlier call we had above:

    back to line 20: root(node10)->right = NULL;

    So effectively, from node 10 perspective, node 11 is truly gone.

    You could argue with the same logic for any other cases.

*/

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

    inorder(root); // before
    cout<<endl;
    deleteNode(root, 40);
    inorder(root); // after
    cout<<endl;
}