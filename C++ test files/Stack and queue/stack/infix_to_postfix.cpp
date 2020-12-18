#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}
int postfix(string s)
{
    stack<char>st;
    string ns;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z')
            ns+=s[i];
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                char c=st.top();
                st.pop();
                ns+=c;
            }
            if(st.top()=='(')
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && (prec(s[i])<=prec(st.top())))
            {
                char c=st.top();
                st.pop();
                ns+=c;
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        char c=st.top();
        st.pop();
        ns+=c;
    }
    cout<<ns;
}
int main()
{
    string s="a+b*(c^d-e)^(f+g*h)-i";
    postfix(s);
}
