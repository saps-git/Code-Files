#include<bits/stdc++.h>
using namespace std;
bool sumSubset(vector<int> vec, int sum, int n){
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(vec[n-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-vec[i-1]] || dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    vector<int> vec{3, 34, 4, 12, 5, 2};
    int n = vec.size();
    int sum = 21;
    if(sumSubset(vec, sum, n) == true)
        cout<<"true";
    else
        cout<<"false";
    cout<<endl;
}