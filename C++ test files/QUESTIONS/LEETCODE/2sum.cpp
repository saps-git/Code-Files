#include<bits/stdc++.h>
using namespace std;

void twoSum(vector<int>& nums, int target) 
{
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
    {
        int sum = target-nums[i];
        if(mp.find(sum)!=mp.end())
            cout<<sum<<" "<<nums[i]<<endl;

        mp.insert(make_pair(nums[i], i));
    }
}

int main()
{
    vector<int> nums = {2,15,11,7};
    int target = 9;
    twoSum(nums, target);
}