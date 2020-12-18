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

node* reverse_half(node* ptr) //helper function to reverse, from the half to the end
{
    node* prev = NULL;
    while(ptr)
    {
        node* save = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = save;
    }
    return prev;
}

bool palindrome(node* head)
{
    node* slow = head;
    node* fast = head;
    
    while(fast && fast->next)
    {
        fast = fast->next;
        if(fast->next)
            fast = fast->next;
        slow = slow->next;
    } // finding the mid point
    
    slow  = reverse_half(slow); //now reversing the second half
    fast = head; // and setting fast at the head 

    while(slow)
    {
        if(slow->data != fast->data) //and comparing both of them 
        {
            return 0;
            break;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return 1;
}

int main()
{
    node* head = new node;
    head->data = 0;
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next = createNode(1);

    head = head->next;
    if(palindrome(head))
        cout<<"PALINDROME"<<endl;
    else
        cout<<"NOT PALINDROME"<<endl;
    //printNode(head);
}

 