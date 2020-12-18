#include<bits/stdc++.h>
using namespace std;
//printing the string

//same as printing the LCS, with minor changes
/*
This problem is closely related to longest common subsequence problem. Below are steps.

1) Find Longest Common Subsequence (lcs) of two given strings. For example, lcs of “geek” and “eke” is “ek”.
2) Insert non-lcs characters (in their original order in strings) to the lcs found above, and return the result. 
So “ek” becomes “geeke” which is shortest common supersequence.

Let us consider another example, str1 = “AGGTAB” and str2 = “GXTXAYB”. LCS of str1 and str2 is “GTAB”. 
Once we find LCS, we insert characters of both strings in order and we get “AGXGTXAYB”
*/
string short_super(string str1, string str2, int len1, int len2){
    int dp[len1+1][len2+1];
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0||j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans;
    int i = len1;
    int j = len2;

    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            ans.push_back(str1[i-1]);
            i--;
            j--;
        }
        //just push the max of the two adjacent cells to the op string
        else if(dp[i][j-1] > dp[i-1][j]){
            ans.push_back(str2[j-1]);  
            j--;
        }
        else
        {
            ans.push_back(str1[i-1]);
            i--;
        }
    }

    //then push the remaining of i or j to the string
    while(i>0){ 
        ans.push_back(str1[i-1]);
        i--;
    }

    while(j>0){
        ans.push_back(str2[j-1]);
        j--;
    }

    reverse(ans.begin(), ans.end()); //reverse to get the output
    return ans;
}
//printing the size  
/*
int short_super(string str1, string str2, int len1, int len2){
    int dp[len1+1][len2+1];

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }    
    }

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){    
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    int size = str1.size() + str2.size() - dp[len1][len2];
    return size;
}
*/
int main()
{
    string str1 = "AGGTAB", str2 = "GXTXAYB";
    int len1 = str1.size(), len2 = str2.size();
    cout<<short_super(str1, str2, len1, len2)<<endl;
}