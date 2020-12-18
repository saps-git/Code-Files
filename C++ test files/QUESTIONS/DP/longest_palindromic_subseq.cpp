#include<bits/stdc++.h>
using namespace std;

// Longest Palindromic Subsequence of string a = Longest Common Subsequence of string a , and its reverse (reverse of string a)

int helper(string s, int len){
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
    
    return dp[len][len];
}
int main()
{
    string s = "agbcba";
    int len = s.size();
    cout<<helper(s, len)<<endl;
}