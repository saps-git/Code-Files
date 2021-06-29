#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* createNode(int x)
{
    node* ptr = new node;
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}

void printNode(node* ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

vector<int> nextGreater(node* head){

    vector<int> ans;
    while(head){
        ans.push_back(head->data);
        head = head->next;
    }

    int n = ans.size();
    stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && ans[st.top()] < ans[i]){
            ans[st.top()] = ans[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main()
{
    node* head = new node;
    head->data = 0;
    head->next = createNode(11);
    head->next->next = createNode(13);
    head->next->next->next = createNode(21);
    head->next->next->next->next = createNode(1);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    node* root = head->next;
    vector<int> ans  = nextGreater(root);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
}

