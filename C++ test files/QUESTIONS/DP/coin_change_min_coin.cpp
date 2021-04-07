//varient of unbounded knapsack
#include<bits/stdc++.h>
using namespace std;
//BottomUP
int coinChange(vector<int> vec, int amt, int n){
    int dp[n+1][amt+1];
    for(int i=0;i<=amt;i++)
        dp[0][i] = INT_MAX-1;
    for(int i=1;i<=n;i++)
        dp[i][0] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amt;j++){
            if(vec[i-1] <= j)
                dp[i][j] = min(dp[i][j-vec[i-1]]+1, dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][amt];
}
//recursive
/*
int coinChange(vector<int> vec, int amt, int n){
    if(amt == 0)
        return 0;
    if(n == 0)
        return INT_MAX-1; //if array becomes empty, return max, as we have to find the min number of coins

    if(vec[n-1] <= amt)
        return min(coinChange(vec, amt-vec[n-1], n)+1, coinChange(vec, amt, n-1)); //in first case where we select the coin, we add +1 as the number of coin increases by 1
    else
        return coinChange(vec, amt, n-1);
}
*/
int main()
{
    vector<int> vec = {1,5,10,15};
    int amt = 8;
    int n = vec.size();
    cout<<coinChange(vec, amt, n)<<endl;
}