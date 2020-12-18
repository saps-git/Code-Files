#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& vec)
{
    int row = vec.size();
    if(row == 0)
        return 0;
    int col = vec[0].size();

    vector<vector<int>> dp(row, vector<int>(col,0));
    dp[0][0] = vec[0][0]; //1st element is starting point

     //Fill 1st row
    for(int i=1;i<col;i++)
        dp[0][i] = vec[0][i] + dp[0][i-1];

    //Fill 1st Col
    for(int i=1;i<row;i++)
        dp[i][0] = vec[i][0] + dp[i-1][0];

    //Now fill the rest of the cell
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            dp[i][j] = vec[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[row-1][col-1]; //last element in the matrix
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> vec = {{1,3,5},{2,1,2},{4,3,1}};
    int x = minPathSum(vec);
    cout<<x<<endl;
}