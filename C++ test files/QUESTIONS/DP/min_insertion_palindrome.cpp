//same as min number of deletion 
#include<bits/stdc++.h>
using namespace std;

int minInsertions(string s, int n){
    string t;
    int i = n;
    while(i>0){ //reverse the given string
        t.push_back(s[i-1]);
        i--;
    }
    
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return n-dp[n][n];
}

int main(){
    string s = "leetcode";
    int n = s.size();
    
    cout<<minInsertions(s, n)<<endl;
}