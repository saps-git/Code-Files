//Refer to unbounded knapsack problem for any doubts
#include<bits/stdc++.h>
using namespace std;
//BottomUp
int coinChange(vector<int>vec, int amt, int n){
    int dp[n+1][amt+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1;i<=amt;i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=amt;j++){
            if(vec[i-1] <= j)
                dp[i][j] = dp[i][j-vec[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][amt];
}
//Recursive
/*
int coinChange(vector<int> vec, int amt, int n){
    if(amt == 0)
        return 1;
    if(n == 0)
        return 0;

    else if(vec[n-1] <= amt)
        return coinChange(vec, amt-vec[n-1], n) + coinChange(vec, amt, n-1); //adding, since we have to return total number of ways. 

    else
        return coinChange(vec, amt, n-1);
}
*/
int main()
{
    vector<int> vec = {1,5,10,15};
    int amt = 10;
    int n = vec.size();
    cout<<coinChange(vec, amt, n)<<endl;
}