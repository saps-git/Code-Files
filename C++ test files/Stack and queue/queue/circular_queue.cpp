#include<iostream>
using namespace std;
#define size 5
int a[size];
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
    if((rear+1)%size==front)
        cout<<"\nQueue is full ";
    else
    {
        if(front==-1)
            front++;
        rear=(rear+1)%size;
        a[rear]=x;
    }
}
void dequeue()
{
    if(isempty())
        cout<<"\nQueue is full ";
    else if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%size;
}
void peek()
{
    if(isempty())
        cout<<"\nQueue is full ";
    cout<<"\n"<<a[front];
}
void print()
{
    if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
            cout<<a[i]<<" ";
    }
    else
    {
        int i;
        i=front;
        while(i<size)
        {
            cout<<a[i]<<" ";
            i++;
        }
        i=0;
        while(i<=rear)
        {
            cout<<a[i]<<" ";
            i++;
        }
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

