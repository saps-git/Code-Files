#include<bits/stdc++.h>
using namespace std;

// O(n) time O(n) space

vector<vector<int>> twoSum(vector<int> vec, int target)
{
    unordered_set<int> nums;
    vector<vector<int>> ans;
    for(int i: vec)
    {
        int req = target - i;
        if(nums.find(req) != nums.end())
            ans.push_back(vector<int> {req, i});
        else
            nums.insert(i);
    }
    return ans;
}

int main()
{
    vector<int> vec = {3,2,5,4,8,11,1,-1,6};
    int target = 10;
    vector<vector<int>> ans = twoSum(vec, target);
    for(auto i: ans){
        for(auto j: i)
            cout<<j<<"\t";
        cout<<endl;
    }
    
}