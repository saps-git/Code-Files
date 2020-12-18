//perform delete, insert, or change operation on word1 to convert it into word2
#include<bits/stdc++.h>
using namespace std;
/*
same as lcs with minor changes
*/
int minDistance(string word1, string word2, int len1, int len2){
    int dp[len1+1][len2+1];
        
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(j==0) //filling 0th row and col with i & j so as, if either string is empty, it will take that number of operations to make it equal
                dp[i][j] = i; 
            else if(i==0)
                dp[i][j] = j;
        }
    }
    
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1]; //if char is same then then no operation is required, hence the previos same value
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])); //else one operation will be done, with the min of 3 adjacent cells
        }
    }
    
    return dp[len1][len2];
}
int main()
{
    string word1 = "horse", word2 = "ros";
    int len1 = word1.size();
    int len2 = word2.size();
    cout<<minDistance(word1, word2, len1, len2)<<endl;
}