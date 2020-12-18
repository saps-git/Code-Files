#include<bits/stdc++.h>
using namespace std;
//bottom up
int substring(string text1, string text2,  int len1, int len2){
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
                dp[i][j] = 0; //since we need to find substring, hence whenever strings don't match, make it zero
        }
    }

    int ans = 0;
    for(int i=0;i<len1;i++){ //since the longest substring can be present anywhere in the 2d array 
        for(int j=0;j<len2;j++){
            if(dp[i][j] > ans)
                ans = dp[i][j];
        }
    }

    return ans+1;
}
int main()
{
    string text1 = "abcdehggjiotamk";
    string text2 = "oxlcdeiota";
    int len1 = text1.size();
    int len2 = text2.size();

    int len = 0;
    cout<<substring(text1, text2, len1, len2)<<endl;
}