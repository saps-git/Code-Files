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

map<int, map<int, set<int>>> ans; //taking a map of map of set as it will be a 2D
/*

x--
     
-1 | 0 1 2 3 4  y
0  | 0 1 2 3 4  |
1  | 0 1 2 3 4  |

         1              y
       /   \            \
    2       3           \   
  /   \    /             
4       5 6
 
-2  -1  0   1        <--x

-2 -> 4
-1 -> 2
0  -> 1->5->6
1  -> 3





*/


// THINK THE TREE TO BE ON A GRAPH, EACH NODE IS ON A PARTICULAR X AND Y AXIS POINT, ASSUMING ROOT TO BE 0,0
void verticalTraversal(node* root, int col, int row){
    if(!root)
        return;

    ans[col][row].insert(root->data); //inserting the value in the appropriate place in the above DS
    verticalTraversal(root->left, col-1, row+1); 
    verticalTraversal(root->right, col+1, row+1);
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

    verticalTraversal(root, 0, 0);
    
    for(auto i: ans){ //for printing the values as an array of array
        for(auto j: i.second){
            for(auto k: j.second)
                cout<<k<<"\t";
        }
    }

    cout<<endl;

}
