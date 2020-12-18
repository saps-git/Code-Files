#include<bits/stdc++.h>
using namespace std;

class node
{
    private:
        int data;
        node* left;
        node* right;

    public:
        //default constructor
        node() // to create a new node,without any data, root;
        {
            data = 0;
            left = right = NULL;
        }
        //parameterized constructor
        node(int data) // to create a new node with data
        { 
            this->data = data;
            left = right = NULL;
        }

        //member functions and declarations
        node* insert(node* root, int data);
        void Search(node*, int);
        void Inorder(node *root);
};

//function defination
node* node :: insert(node* root, int data)
{
    if(!root)
    {
        node* temp = new node(data);
        return temp;
    }
    else if(data > root->data)
        root->right = insert(root->right, data);
    else
        root->left = insert(root->left, data);

    return root;
}

void node :: Search(node* root, int data)
{
    if(root == NULL)
        cout<<"0";
        //return false;
    
    else if(root->data == data)
    {
        cout<<root->data<<" "<<"found\n";
        //return true;
    }

    else if(data <= root->data)
        return Search(root->left, data);

    else
        return Search(root->right, data);
}

void node :: Inorder(node *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    Inorder(root->left); 
    cout << root->data << "\n";
    Inorder(root->right); 
} 

int main()
{
    freopen("input.txt","r",stdin);
    node *root = NULL;
    node b;
    
    int n; 
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        root = b.insert(root,x);
    }
    
    b.Inorder(root);
    cout<<endl;
    b.Search(root, 20);
}
