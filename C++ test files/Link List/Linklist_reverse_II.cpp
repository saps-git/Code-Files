/*

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

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

void printNode(node* ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
        
    }
    cout<<endl;
}

node* reverseList(node* ptr, int x, int y)
{
    if(ptr == NULL)
        return NULL;
    
    node* prev = NULL;
    node* curr = ptr;

    while(x>1)
    {
        prev = curr; //moving the first pointer to the starting point where to be flipped
        curr = curr->next;
        x--; // decrementing the counter for both as pointer moving to that particular element
        y--;
    }

    node* conn = prev; // initializing pointers to later connect to the reversed part
    node* tail = curr;

    while(y>0) //going to zero, because, while connecting the tail, curr will be y+1th element, so easy to point
    {
        node* save = curr->next; // reversing the part
        curr->next = prev;
        prev = curr;
        curr = save;
        y--;
    }

    if(conn != NULL) // if more than 1 element, then connecting to starting of the reversed part
        conn->next = prev;
    else //if only one element then ending reverse as normal
        ptr = prev;
        
    tail->next = curr; //connecting to ending of the reversed part
    return ptr;
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
    reverseList(head, 2, 4);
    printNode(head);
}

