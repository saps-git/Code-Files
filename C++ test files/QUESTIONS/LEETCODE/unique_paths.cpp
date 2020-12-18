#include<bits/stdc++.h>
using namespace std;
int ways(int m, int n){
    int ans[m][n];
    for(int i=0;i<m;i++)
        ans[i][0] = 1; //filling the row[0] with 1, as there is only way to reach there (right from previous)
    for(int i=0;i<n;i++)
        ans[0][i] = 1; //filling the col[0] with 1, as there is only way to reach there (down from previous)

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            ans[i][j] = ans[i-1][j] + ans[i][j-1]; //now for every cell, add the two ways you can reach there
        }
    }

    return ans[m-1][n-1]; //return the last element 
}
int main()
{
    int m=3, n=3;
    cout<<ways(m,n)<<endl;
}