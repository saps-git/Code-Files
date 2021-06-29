#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "olaww hfsjll";
    vector<int> ans(26, 0);

    for(int i=0;i<str.length();i++)
        ans[str[i]-'a']++;

    for(int i=0;i<26;i++){
        if(ans[i] > 1)
            cout<<ans[i]<<" times "<<char(i+'a')<<"\n";
    }
}
