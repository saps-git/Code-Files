#include<bits/stdc++.h>
using namespace std;
/*

'1' - for land, '0' - for water, we need to find consecutive connected 1's (up, down, left, right)
when we concur '1', we turn it to '2', so that when we come back to it, we know that it has been checked
and then call recursively for all the adjacent cells and increment ans when we complete one complete recursion, 
then continue for remainig 1's (that haven't been changed to '2')

*/
void helper(vector<vector<char>>& grid, int i, int j, int row, int col){
    if(i<0 || i >= row || j<0 || j >= col || grid[i][j] != '1') //edge cases
        return;
    
    grid[i][j] = '2'; //make it 2, so that when we come back, we know it is already visited
    
    //calling recursively for adjacent cells
    helper(grid, i+1, j, row, col);
    helper(grid, i, j+1, row, col);
    helper(grid, i-1, j, row, col);
    helper(grid, i, j-1, row, col);
}
int numIslands(vector<vector<char>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row = grid.size();
    if(row == 0)
        return 0;
    int col = grid[0].size();
    
    int ans = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j] == '1'){ //if found any cell with 1, call the helper function, with proper cordinates
                helper(grid, i, j, row, col);
                ans += 1; //incrementing the count
            }
        }
    }
    
    return ans;
}
int main()
{
    vector<vector<char>> grid = {
                                    {'1','1','1','1','0'}, 
                                    {'1','1','0','1','0'}, 
                                    {'1','1','0','0','0'}, 
                                    {'0','0','0','0','0'}
                                };
    cout<<numIslands(grid)<<endl;
}