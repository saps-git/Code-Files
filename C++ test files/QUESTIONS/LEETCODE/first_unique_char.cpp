#include<bits/stdc++.h>
using namespace std;
int main()
{

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "abcabad";

    vector<int> vec(26,0);

    for(int i=0;s[i]!='\0';i++)
        vec[s[i]-'a'] += 1;

    for(int i=0;s[i]!='\0';i++)
        if(vec[s[i]-'a'] ==  1)
        {
            cout<<s[i]<<endl;
            break;
        }
    
    return 0;
}