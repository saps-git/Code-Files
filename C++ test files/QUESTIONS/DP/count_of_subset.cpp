#include<bits/stdc++.h>
using namespace std;
//Bottom UP
int ways(vector<int> vec, int sum, int n){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1;i<=sum;i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(vec[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-vec[i-1]]; // here we will do '+' as, we need to find total subsets
        }
    }
    return dp[n][sum];
}

/*
int ways(vector<int> vec, int sum, int n){
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;

    if(vec[n-1] > sum)
        return ways(vec, sum, n-1);
        
    return ways(vec, sum-vec[n-1], n-1) + ways(vec, sum, n-1);
}
*/
int main()
{
    vector<int> vec = {2,3,5,6,8,10};
    int sum = 10;
    int n = vec.size();
    cout<<ways(vec, sum, n)<<endl;
}