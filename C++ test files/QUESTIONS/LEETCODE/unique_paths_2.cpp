//No of paths from starting to ending, given there are obstacle( denoted by 1) in the way of a matrix of zeros
//Refer to Unique paths for more clarification
#include<bits/stdc++.h>
using namespace std;
int ways(vector<vector<int>>& ans){
    int m = ans.size();
    int n = ans[0].size();

    if(ans[0][0] == 1) //if the first is 1(obstacle), means no path
        return 0;

    ans[0][0] = 1; //else make the origin 1, no of paths at that point

    for(int i=1;i<m;i++){ // fill the first col
        if(ans[i][0] == 1) // if obstacle found, 
            ans[i][0] = 0; // make it 0
        else
            ans[i][0] = ans[i-1][0]; // else, make it same as above
    }

    for(int i=1;i<n;i++){ // fill the first row
        if(ans[0][i] == 1) // if obstacle found,
            ans[0][i] = 0;  // make it 0
        else 
            ans[0][i] = ans[0][i-1]; // else, make it same as left
    }

    for(int i=1;i<m;i++){ //for all other cells
        for(int j=1;j<n;j++){
            if(ans[i][j] == 1) // if there obstacle(1)
                ans[i][j] = 0; // make it zero
            else
                ans[i][j] = ans[i-1][j] + ans[i][j-1];  // else, add values in above and left
                
        }
    }
    
    return ans[m-1][n-1]; //return the last element 
}
int main()
{
    vector<vector<int>> ans = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<ways(ans)<<endl;
}