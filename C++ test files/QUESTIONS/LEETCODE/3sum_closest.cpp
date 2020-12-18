#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) 
{
    if(nums.size() <= 2)
        return {};
    
    int res = nums[0]+nums[1]+nums[nums.size()-1];
    
    sort(nums.begin(), nums.end());           
    for(int i=0;i<nums.size()-2;i++)
    {
        int low = i+1;
        int high = nums.size()-1;
        
        while(low<high)
        {
            int curr = nums[i]+nums[low]+nums[high];
            if (curr > target)
                high--;
            else
                low++;
            
            if(abs(curr-target) < abs(res-target))
                res = curr;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout<<threeSumClosest(nums, target)<<endl;
}