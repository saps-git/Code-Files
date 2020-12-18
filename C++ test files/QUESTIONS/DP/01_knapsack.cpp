#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(10, vector<int> (10, -1)); // global 2D vector for memoization

int knapsack(vector<int> val, vector<int> wt, int W, int n){
    if(n == 0  || W == 0) // if any of weight or size of array is 0 return 0
        return 0;

    if(dp[W][n] != -1) // check if that element is present in the vector, then return directly that element
        return dp[W][n]; 

    else if(wt[n] <= W) // if it is not present and the curr element weight, is less than the total weight then,
        return dp[W][n] = max(val[n] + knapsack(val, wt, W-wt[n], n-1), knapsack(val, wt, W, n-1)); // take tha max of, if we add the element or if we don't add the element, and save it in the 2D array for future ref

    else // if curr element weight, is more than the total weight then
        return dp[W][n] =  knapsack(val,wt, W, n-1);  // just call for the next element, without adding this element

}

//Recursive method, this has many repetetive test cases, hence we make a memoized solution, using a 2D array
/*
int knapsack(vector<int> val, vector<int> wt, int W, int n){
    if(W == 0 || n == 0)
        return 0;

    else if(wt[n] <= W)
        return max(val[n]+knapsack(val, wt, W-wt[n], n-1), knapsack(val, wt, W, n-1));

    else
        return knapsack(val, wt, W, n-1);
}
*/

int main()
{
    vector<int> val = { 4, 5, 3, 7, 1 };
    vector<int> wt =  { 2, 3, 1, 4, 5 };
    int n = val.size()-1; // last element of the array
    int W = 5;
    cout<<knapsack(val, wt, W, n)<<endl;
}