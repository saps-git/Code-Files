#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
    int j = 0;
    for(int i=0;i<t.length();i++){
        if(s[j] == t[i])
            j++;
    }
    return (j == s.length());
}
int main()
{
    string s = "axc";
    string t = "ahbgdc";
    if(isSubsequence(s, t)) 
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}