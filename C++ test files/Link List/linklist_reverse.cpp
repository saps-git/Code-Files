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

node* reverseList(node* &head){
    node* curr = head;
    node* prev = NULL;

    while(curr){
        node*  save = curr->next;
        curr->next = prev;
        prev = curr;
        curr = save;
    }

    head = prev;
    return head;
}


int main()
{
    node* head = new node;
        head->data = 0;
        head->next = createNode(1);
        head->next->next = createNode(2);
        head->next->next->next = createNode(3);
        head->next->next->next->next = createNode(4);
        head->next->next->next->next->next = createNode(5);

    head = head->next;
    reverseList(head);
    printNode(head);
}