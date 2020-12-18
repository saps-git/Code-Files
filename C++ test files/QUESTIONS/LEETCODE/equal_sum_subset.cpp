#include<bits/stdc++.h>
using namespace std;

bool helperFunc(vector<int> vec, int sum, int n){
    bool dp[n][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(vec[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-vec[i-1]];
        }
    }
    return dp[n][sum];
}

bool equalSum(vector<int> vec){
    int sum = 0;
    for(int i: vec) 
        sum += i;
    if(sum%2 != 0)
        return false; // if sum of all elements in the array is odd, then it cannot be divided into 2 parts

    int n = vec.size();
    return helperFunc(vec, sum/2, n); // then make a function like subset sum, and find if any subset if the current array is present for half of the total sum, then it will be present for another half
}

int main()
{
    vector<int> vec = {1,5,11,5,8};
    if(equalSum(vec) == true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}