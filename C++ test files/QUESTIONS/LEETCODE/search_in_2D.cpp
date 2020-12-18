#include<bits/stdc++.h>
using namespace std;

//O(n)
bool searchMatrix(vector<vector<int>> matrix, int target){
    if (!matrix.size())
        return false;
    
    int i = 0;
    int j = matrix[0].size()-1;
    while(i < matrix.size() && j >= 0){
        if(target == matrix[i][j])
            return true;
        else if(target < matrix[i][j])
            j--;
        else if(target > matrix[i][j])
            i++; 
    }
    return false;
}
int main()
{
    vector<vector<int>> vec = {
                                {1,   3,  5,  7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50}
                              };
    int target = 34;
    if(searchMatrix(vec, target))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;                              
}