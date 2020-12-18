#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "olaww hfsjll";
    int a[26]= {0};
    for(int i=0;i<str.length();i++)
        a[str[i]-'a']++;
    
    for(int i=0;i<26;i++)
        if(a[i]>1)
            cout<<a[i]<<" times "<<char(i+'a')<<"\n";
}