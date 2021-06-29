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

vector<int> nextGreat(node* head)
{
    vector<int> vec;
    while(head) //pushing the data of the link list to a vector
    {
        vec.push_back(head->data); 
        head = head->next;
    }

    // same as next greater in normal array
    int n = vec.size();
    vector<int> sol(n, -1); //intializing the solution vector
    stack<int> s;
    s.push(0);

    for(int i=1;i<n;i++)
    {
        /*
        if(s.empty())
        {
            s.push(vec[i]);
            continue;
        }
        */
        while(!s.empty() && vec[s.top()] < vec[i])
        {
            sol[s.top()] = vec[i];
            s.pop();
        }
        s.push(i);
    }
    return sol;
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

    head = head->next;
    vector<int> sol = nextGreat(head);

    for(int i: sol)
        cout<<i<<" ";
    cout<<endl;
}

