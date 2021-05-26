/*

Given the head of a linked list and a value x, partition it such that all nodes less than x come before 
nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

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

void printNode(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
        
    }
    cout<<endl;
}
node* partition(node* head, int x)
{
    node* less = new node;
    node* less_head = less;
    node* more = new node;
    node* more_head = more;

    while(head != NULL)
    {
        if(head->data < x)
        {
            less->next = head;
            less = less->next;
        }
        else
        {
            more->next = head;
            more = more->next;
        }

        head = head->next;
    }

    more->next = NULL; //end of linklist
    less->next = more_head->next; //connecting end of less to more, we point to more_head->next as more_head is 0
    return less_head->next; //returning less_head->next as less_head is 0
}

int main()
{
    node* head = new node;
    head->data = 0;
    head->next = createNode(1);
    head->next->next = createNode(4);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(2);

    head = head->next;
    partition(head, 3);
    printNode(head);
}

