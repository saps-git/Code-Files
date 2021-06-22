#include<iostream>
#include<stack>
using namespace std;
int evaluation(char *a)
{
    stack<char> s;
    for(int i=0;a[i];i++)
    {
        if(isdigit(a[i]))
        {
            s.push(a[i]-'0');
        }
        else
        {
            int v2=s.top();
            s.pop();
            int v1=s.top();
            s.pop();
            switch(a[i])
            {
                case '+':
                    s.push(v1+v2);break;
                case '-':
                    s.push(v1-v2);break;
                case '*':
                    s.push(v1*v2);break;
                case '/':
                    s.push(v1/v2);break;
            }

        }
    }
    return s.top();
}
int main()
{
    char a[]="231*+9-";
    cout<<evaluation(a);
}
