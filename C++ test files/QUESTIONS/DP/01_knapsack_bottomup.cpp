#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> val, vector<int> wt, int W, int n){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[i] <= j)
                dp[i][j] = max(val[i]+dp[i-1][j-wt[i]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main(){
    vector<int> val = { 4, 5, 3, 7, 1 };
    vector<int> wt =  { 2, 3, 1, 4, 5 };
    int n = val.size()-1; // last element of the array
    int W = 5;
    cout<<knapsack(val, wt, W, n)<<endl;
}