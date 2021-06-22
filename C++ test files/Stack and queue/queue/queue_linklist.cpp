#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *front=NULL;
node *rear=NULL;

bool isempty()
{
    if(front==NULL && rear==NULL)
        return true;
    return false;
}
void enqueue(int x)
{
    node *p= new node();
    p->data=x;
    p->next=NULL;
    if(front==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}
void dequeue()
{
    if(isempty())
        cout<<"\nQueue empty ";
    else if(front==rear)
    {
        free(front);
        front=rear=NULL;
    }
    else
    {
        node *p=front;
        front=front->next;
        free(p);
    }
}
void peek()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    cout<<"\n"<<front->data;
}
void print()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    while(front!=NULL)
    {
         cout<<front->data<<" ";
         front=front->next;
    }
}
int main()
{
     int x,n;
     do
     {
        cout<<"\nenter \n 1. Enqueue \n 2. Dequeue \n 3. Front \n 4. Print Elements \n";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"\nenter the element to be inserted ";
                cin>>x;
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                print();
                break;
            default:
                cout<<"\ninvalid ";
        }
   }while(n!=4);
    return 0;
}
