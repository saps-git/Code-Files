#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    string st;
    cout<<"enter the name"<<endl;
    cin>>st;
    bool isPallindrome= true;
    stack<char>s;
    queue<char>q;
    for(int i=0;i<st.length();i++)
    {
        s.push(st[i]);
        q.push(st[i]);
    }
    for(int i=0;i<st.length();i++)
    {
        if(s.top()==q.front())
        {
            s.pop();
            q.pop();
        }
        else
        {
            isPallindrome=false;
            break;
        }
    }
    if(isPallindrome)
        cout<<"it is a pallindrome";
    else
        cout<<"not a pallindrome";
}
