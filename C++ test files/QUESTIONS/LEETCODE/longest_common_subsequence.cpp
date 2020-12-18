#include<bits/stdc++.h>
using namespace std;
int longest(string text1, string text2, int len1, int len2){
    int dp[len1+1][len2+1];
    
    for(int i=0;i<=len1;i++){ //filling the first row and col with 0
        for(int j=0;j<=len2;j++){
            if(i == 0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[len1][len2];
}
int main()
{
    string text1 = "abcde", text2 = "ace";
    int len1 = text1.size();
    int len2 = text2.size();

    cout<<longest(text1, text2, len1, len2)<<endl;    

}