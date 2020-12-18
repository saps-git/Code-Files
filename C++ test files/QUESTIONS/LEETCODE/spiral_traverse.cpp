#include<bits/stdc++.h>
using namespace std;

// Iterative Soln O(n)
/*
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size())
            return {};

        int startCol = 0, endCol = matrix[0].size()-1;
        int startRow = 0, endRow = matrix.size()-1;
        vector<int> ans;

        while(startCol <= endCol && startRow <= endRow){
            for(int col = startCol;col <= endCol;col++)
                ans.push_back(matrix[startRow][col]);
            
            for(int row = startRow+1;row <= endRow;row++)
                ans.push_back(matrix[row][endCol]);

            for(int col = endCol-1;col >= startCol;col--){
                if(startRow == endRow)
                    break;

                ans.push_back(matrix[endRow][col]);
            }

            for(int row = endRow-1;row > startRow;row--){
                if(startCol == endCol)
                    break;

                ans.push_back(matrix[row][startCol]);
            }

            startCol++;
            endCol--;
            startRow++;
            endRow--;
        }

        return ans;
}
*/


/* FOR BETTER UNDERSTANDING LOOK AT THE ITERATIVE APPROACH FIRST*/



// Recursive Soln O(n)

//helper recursive function declaretion 
void spiralFill(vector<vector<int>>& matrix, int startCol, int endCol, int startRow, int endRow, vector<int>& ans);

//main function
vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> ans = {};
    spiralFill(matrix, 0, matrix[0].size()-1, 0, matrix.size()-1, ans);
    return ans;
}

//helper recursive function defination
void spiralFill(vector<vector<int>>& matrix, int startCol, int endCol, int startRow, int endRow, vector<int>& ans){
    if(startCol > endCol || startRow > endRow)
        return;
    
    //going on all 4 directions in spiral way
    for(int col = startCol;col <= endCol;col++)
        ans.push_back(matrix[startRow][col]);
    
    for(int row = startRow+1;row <= endRow;row++)
        ans.push_back(matrix[row][endCol]);

    for(int col = endCol-1;col >= startCol;col--){
        if(startRow == endRow)
            break;

        ans.push_back(matrix[endRow][col]);
    }

    for(int row = endRow-1;row > startRow;row--){
        if(startCol == endCol)
            break;

        ans.push_back(matrix[row][startCol]);
    }

    spiralFill(matrix, startCol+1, endCol-1, startRow+1, endRow-1, ans); // incrementing and decrementing as to be done
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = spiralOrder(matrix);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
}