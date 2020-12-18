#include<iostream>
using namespace std;
#define MAX_SIZE 101
int a[MAX_SIZE];
int top=-1;
void push(int x)
{
    if(top==MAX_SIZE-1)
        {
            cout<<"overflow\n";
            return;
        }
    a[++top]=x;
    cout<<"element pushed\n";
}
void pop()
{
    if(top==-1)
    {
        cout<<"underflow\n";
        return;
    }
    top--;
    cout<<"element popped\n";
}
void Top()
{
    cout<<a[top]<<"\n";
}
void print()
{
    for(int i=0;i<=top;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int n,x;
    do
    {
        cout<<"enter \n 1. Push \n 2. Pop \n 3. Top \n 4. Print Elements \n";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"enter the element to be pushed\n";
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
                cout<<"invalid\n";
        }
	}while(n!=4);
    return 0;

}
