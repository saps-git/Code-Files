#include<bits/stdc++.h>
using namespace std;
string longest(string str1, string str2, int l1, int l2){
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
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // till here same as normal lcs

    string ans; //output string
    int i = l1, j = l2; //intializing start

    while(i>0 && j>0){ //doing tha same as used to fill the matrix, only in reverse
        if(str1[i-1] == str2[j-1]){ //if vars match, add to op string
            ans.push_back(str1[i-1]);
            i--; //go to the diagonal cell
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) //else see, the max of upper and left cell and move towards it
            i--;
        else
            j--;  
    } 
    
    reverse(ans.begin(), ans.end()); //finally reverse the string
    return ans;

    //return dp[l1][l2];
}
int main(){
    string str1 = "oabcdefb", str2 = "aoxcdebrb";
    int l1 = str1.size(), l2 = str2.size();
    cout<<longest(str1, str2, l1, l2)<<endl;
}