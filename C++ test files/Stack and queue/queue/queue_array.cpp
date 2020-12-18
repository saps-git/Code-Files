#include<iostream>
using namespace std;
#define SIZE 10
int a[SIZE];
int front=-1;
int rear=-1;
bool isempty()
{
    if(front==-1 && rear==-1)
        return true;
    return false;
}
void enqueue(int x)
{
    if(rear==SIZE-1)
        cout<<"\nQueue is full ";
    else
    {
        if(front=-1)
            front+=1;
        a[++rear]=x;
    }

}
void dequeue()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    else if(front==rear)
        front=rear=-1;
    else
        front++;
}
void peek()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    cout<<"\n"<<a[front];
}
void print()
{
    if(isempty())
        cout<<"\nQueue is empty ";
    for(int i=front;i<=rear;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int x,n;
    do
    {
        cout<<"enter \n 1. Enqueue \n 2. Dequeue \n 3. Front \n 4. Print Elements \n";
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
