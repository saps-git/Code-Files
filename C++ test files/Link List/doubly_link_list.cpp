#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
void traverse(node *n)
{
    while(n->next!=NULL)
    {
        n=n->next;
        cout<<n->data<<" ";
    }
}
void insert_end(node *n,int x)
{
    while(n->next!=NULL)
        n=n->next;
    node *t=new node;
    t->data=x;
    t->next=NULL;
    n->next=t;
    t->prev=n;
}
void insert_begin(node *n,int x)
{
    node *t=new node;
    t->data=x;
    t->prev=n;
    t->next=n->next;
    n->next=t;
}
void delete_end(node *n)
{
    while(n->next->next!=NULL)
        n=n->next;
    n->next=NULL;
}
void delete_begin(node *n)
{
    n->next=n->next->next;
}
void insert_n(node *n,int p,int e)
{
    node *t=new node;
    t->data=e;
    for(int i=0;i<p-1;i++)
        n=n->next;
    t->next=n->next;
    n->next->prev=t;
    n->next=t;
    t->prev=n;
}
void delete_n(node *n,int p)
{
    for(int i=0;i<p-1;i++)
        n=n->next;
    n->next=n->next->next;
    n->next->prev=n;
}
int main()
{
    int a,b,c,d,e,p,n,x;
    node *head=new node;
    head->data=NULL;
    head->prev=NULL;
    head->next=NULL;
    cout<<"enter the number of elements ";
    cin>>n;
    cout<<"enter elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert_end(head,x);
    }
    do
    {
        cout<<"\n1. Traverse \n2. Insert at end \n3. Insert at beginning \n4. Insert at nth pos \n5. Delete at last \n6. Delete at first \n7. Delete at nth pos \n";
        cin>>b;
        switch(b)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            cout<<"element to be inserted ";
            cin>>a;
            insert_end(head,a);
            break;
        case 3:
            cout<<"element to be inserted ";
            cin>>c;
            insert_begin(head,c);
            break;
        case 4:
            cout<<"pos of the element ";
            cin>>p;
            cout<<"element to be inserted ";
            cin>>e;
            insert_n(head,p,e);
            break;
        case 5:
            delete_end(head);
            break;
        case 6:
            delete_begin(head);
            break;
        case 7:
            cout<<"pos of the element to be deleted ";
            cin>>d;
            delete_n(head,d);
            break;
        }
    }while(b<8);
}
