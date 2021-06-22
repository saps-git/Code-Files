#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *top=NULL;

bool isempty()
{
    if(top==NULL)
        return true;
    return false;
}
void push(int x)
{
   node *p=new node();
   p->data=x;
   p->next=top;
   top=p;
}
void pop()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    else
    {
        node *p=top;
        top=top->next;
        free(p);
    }
}
void Top()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    cout<<"\n"<<top->data;
}
void print()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        top=top->next;
    }
}
int main()
{
     int x,n;
     do
     {
        cout<<"\nenter \n 1. Push \n 2. Pop \n 3. Top \n 4. Print Elements \n";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"\nenter the element to be inserted ";
                cin>>x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                Top();
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
