#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void traversing(node *n)
{
    while(n->next!=NULL)
    {
        n=n->next;
        cout<<n->data<<" ";
    }
}
void insert_last(node *n,int x)
{
    node *temp=new node;
    temp->data=x;
    temp->next=NULL;
    node *l=n;
    while(l->next!=NULL)
        l=l->next;
    l->next=temp;
    cout<<"inserted "<<x<<"\n";
}
void insert_begin(node *n,int x)
{
    node *temp=new node;
    temp->data=x;
    temp->next=n->next;
    n->next=temp;
}
void delete_last(node *n)
{
    while(n->next->next!=NULL)
        n=n->next;
    n->next=NULL;
}
void delete_first(node *n)
{
    n->next=n->next->next;
}
void insert_n(node *n,int p,int e)
{
    node *t=new node;
    t->data=e;
    node *l=n;
    for(int i=0;i<p-1;i++)
        l=l->next;
    t->next=l->next;
    l->next=t;
}
void delete_n(node *n,int d)
{
    node *l=n;
    for(int i=0;i<d-1;i++)
        l=l->next;
    l->next=l->next->next;
}
int main()
{
    node *head= new node;
    head->data=0;
    int a,x,b,c,f,p,e,d;
    cout<<"enter the number of elements ";
    cin>>x;
    cout<<"enter the elements ";
    for(int i=0;i<x;i++)
    {
        cin>>a;
        insert_last(head,a);
    }
    do
    {
        cout<<"\n1. Traverse \n2. Insert at beginning \n3. Insert at end \n4. Insert at nth pos \n5. Delete at last \n6. Delete at first \n7. Delete at nth pos \n";
        cin>>b;
        switch(b)
        {
            case 1:
                traversing(head);
                break;
            case 2:
                cout<<"enter the element ";
                cin>>f;
                insert_begin(head,f);
                break;
            case 3:
                cout<<"enter the element ";
                cin>>c;
                insert_last(head,c);
                break;
            case 4:
                cout<<"enter the position ";
                cin>>p;
                cout<<"enter the element ";
                cin>>e;
                insert_n(head,p,e);
                break;
            case 5:
                delete_last(head);
                break;
            case 6:
                delete_first(head);
                break;
            case 7:
                cout<<"the position ";
                cin>>d;
                delete_n(head,d);
                break;
        }
    }
    while(b<8);
    cout<<"\nend";
}
