#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"stack or queue ";
    cin>>s;
    if(s=="queue")
    {
        queue<int>q;
        int n,val;
        cout<<"no of elements ";
        cin>>n;
        cout<<"enter elements ";
        for(int i=0;i<n;i++)
        {
            cin>>val;
            q.push(val);
        }
        while(!q.empty())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
    }
    else if(s=="stack")
    {
       stack<int>s;
       int n,val;
       cout<<"enter the number of elements ";
       cin>>n;
       cout<<"enter the elements ";
       for(int i=0;i<n;i++)
       {
           cin>>val;
           s.push(val);
       }
       while(!s.empty())
       {
           cout<<s.top()<<" ";
           s.pop();
       }
    }
    else
        cout<<"invalid";
        return 0;
}
