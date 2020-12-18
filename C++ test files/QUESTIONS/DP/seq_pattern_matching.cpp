#include<bits/stdc++.h>
using namespace std;
/*
size of lcs should be same as of the smaller string
*/
bool pattern_mat(string str1, string str2){
    int l1 = str1.size();
    int l2 = str2.size();
    int dp[l1+1][l2+1];

    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    if(dp[l1][l2] == l1)
        return true;
    return false;
}
int main()
{
    string str1 = "AXY", str2 = "AOXCPY";
    cout<<pattern_mat(str1, str2)<<endl;
}