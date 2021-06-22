#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool parenthesis(string s)
{
    stack<char>st;
    char x;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
        if(s.empty())
            return false;
        switch(s[i])
        {
            case ')':
                x=st.top();
                st.pop();
                if(x=='{' || x=='[')
                    return false;
                break;
            case '}':
                x=st.top();
                st.pop();
                if(x=='(' || x=='[')
                    return false;
                break;
            case ']':
                x=st.top();
                st.pop();
                if(x=='(' || x=='{')
                    return false;
                break;

        }
    }
    return true;
    //return(st.empty());
}
int main()
{
    string s="{()}[{}]";
    if(parenthesis(s))
        cout<<"balanced";
    else
        cout<<"not balanced";
    return 0;
}
