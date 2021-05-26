/*

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes 
with even indices, and return the reordered list.

*/

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
//Approach 1
/*
node* segregateList(node* ptr)
{
    int cntr = 1; //initializing counter
    node* end = ptr;
    while(end->next != NULL)
    {
        end = end->next;
        cntr ++; //counting total elements
    }
    
    cntr = cntr & 1 ? (cntr/2)+1 : cntr/2; // number of operations to be performed for odd or even link list
    node* start = ptr;
    while(cntr--)
    {
        end->next = start->next;    // breaking and linking accordingly
        start->next = start->next->next;
        end->next->next = NULL;
        start = start->next;
        end = end->next;
    }
    return ptr;
}
*/

node* segregateList(node* ptr)
{
    node* odd = ptr; // odd linklist start from head
    node* even = ptr->next; // even linklist start from head->next
    node* even_head = ptr->next; //storing head of even linklist for later

    while(even && even->next)
    {
        odd->next = odd->next->next; //splitting the link list into an odd only and even only part
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = even_head; // linking the tail of odd link list to head of even linklist
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


int main()
{
    node* head = new node;
    head->data = 0;
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    head = head->next;
    segregateList(head);
    printNode(head);
}

