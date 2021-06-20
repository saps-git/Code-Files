#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
}*head;

node* createNode(int n)
{
    node* ptr = new node;
    ptr->data = n;
    ptr->next = NULL;
    return ptr;
}

node* juncNode(node* ptr)
{
    node *sptr, *fptr;
    sptr = fptr = ptr;

    while(fptr && fptr->next)
    {
        sptr = sptr->next;
        fptr = fptr->next->next;

        if(sptr == fptr)
        {
            sptr = ptr;
            while(sptr != fptr)
            {
                sptr = sptr->next;
                fptr = fptr->next;
            }
            return sptr;
        }
    }

    return NULL;
}

void printCycle(node* ptr)
{
    node *temp = ptr;
    do
    {
       cout<<temp->data<<" ";
        temp = temp->next; 

    }while (temp != ptr);
    cout<<endl;
}

int main()
{
    head = NULL;
    head = createNode(1);
    head = head;
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = head->next->next;

    node *start = juncNode(head);

    if(!start)
        cout<<"no cycle"<<endl;
    else
    {
        printCycle(start);
    }
}