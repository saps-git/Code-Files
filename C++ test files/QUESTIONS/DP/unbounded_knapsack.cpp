#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(10, vector<int> (10, -1)); // global 2D vector for memoization

int un_knapsack(vector<int> val, vector<int> wt, int W, int n){
    if(n == 0  || W == 0) // if any of weight or size of array is 0 return 0
        return 0;

    if(dp[W][n] != -1) // check if that element is present in the vector, then return directly that element
        return dp[W][n]; 

    else if(wt[n] <= W) // if it is not present and the curr element weight, is less than the total weight then,
        return dp[W][n] = max(val[n] + un_knapsack(val, wt, W-wt[n], n), un_knapsack(val, wt, W, n-1)); // take tha max of, if we add(but keep n same, as we will check for it again) the element or if we don't add the element, and save it in the 2D array for future ref

    else // if curr element weight, is more than the total weight then
        return dp[W][n] =  un_knapsack(val,wt, W, n-1);  // just call for the next element, without adding this element
}

//bottom up 
/*
int un_un_knapsack(vector<int> val, vector<int> wt, int W, int n){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[i] <= j)
                dp[i][j] = max(val[i]+dp[i][j-wt[i]], dp[i-1][j]);  //same as above method
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
*/
int main(){
    vector<int> val = { 4, 5, 3, 7, 1 };
    vector<int> wt =  { 2, 3, 1, 4, 5 };
    int n = val.size()-1; // last element of the array
    int W = 5;
    cout<<un_knapsack(val, wt, W, n)<<endl;
}