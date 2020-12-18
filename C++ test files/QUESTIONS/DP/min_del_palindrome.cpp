#include<bits/stdc++.h>
using namespace std;
/*
for the minimum number of deletions to covert a string into palindrom - 
subtract the length of its longest palindromic subseqn(refer to longest palindromic subseqn code) with the strings length.
*/
int mindel(string s, int len){
    string t;
    int i = len;
    while(i>0){ //reverse the given string
        t.push_back(s[i-1]);
        i--;
    }

    //LCS
    int dp[len+1][len+1];
    for(int i=0;i<=len;i++){
        for(int j=0;j<=len;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return len - dp[len][len];  // subtract the length of its longest palindromic subseqn with the string's length.
}
int main()
{
    string str = "zzazz";
    int len = str.size();
    cout<<mindel(str, len)<<endl;
}