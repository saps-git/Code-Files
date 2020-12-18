#include<bits/stdc++.h>
using namespace std;
void Reverse(string s)
{
    if (s.empty())
        return;
    
    int i=0;
    int j=s.length()-1;

    while(i<j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    cout<<s<<endl;
}
int main()
{
    string s= "hello iam saptarshi";
    Reverse(s);
}