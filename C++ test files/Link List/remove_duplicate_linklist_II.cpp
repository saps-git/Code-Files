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

/*
Sentinel Head + Predecessor

The standard way to handle this use case is to use the so-called Sentinel Node. Sentinel nodes are widely used for trees 
and linked lists as pseudo-heads, pseudo-tails, etc. They are purely functional and usually don't hold any data. 
Their primary purpose is to standardize the situation to avoid edge case handling.

For example, let's use here pseudo-head with zero value to ensure that the situation "delete the list head" could never happen, 
and all nodes to delete are "inside" the list.

*/


node* removeDupList(node* head){
    node* dummy = new node; //sentinal node
    dummy->next = head;

    // prev = the last node 
    // before the sublist of duplicates
    node* prev = dummy;

    while(head){
        // if it's a beginning of duplicates sublist 
        // skip all duplicates
        if(head->next && head->data == head->next->data){ 
            while(head->next && head->data == head->next->data){ // move till the end of duplicates sublist
                head = head->next;
            }
            prev->next = head->next; // skip all duplicates
        }
        else
            prev = prev->next; // otherwise, move predecessor

        head = head->next; // move forward
    }

    return dummy->next;
}


int main()
{
    node* head = new node;
        head->data = 0;
        head->next = createNode(1);
        head->next->next = createNode(2);
        head->next->next->next = createNode(3);
        head->next->next->next->next = createNode(3);
        head->next->next->next->next->next = createNode(4);
        head->next->next->next->next->next->next = createNode(4);
        head->next->next->next->next->next->next->next = createNode(5);

    head = head->next;
    node* ans = removeDupList(head);
    printNode(ans);
}