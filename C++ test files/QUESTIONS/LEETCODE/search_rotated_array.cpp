#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size()-1;
    
    while (left<right)
    {
        int mid = (left+right)/2;
        if(nums[mid]>nums[right])
            left = mid+1;
        else
            right = mid;
    }

    int start = left;
    left = 0;
    right = nums.size()-1;
    

    if(target >= nums[start] && target <= nums[right])
        left = start;
    else
        right = start;
    

    while(left<=right)
    {
        int mid = (left+right)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid]>target)
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
    
    
    
}
int main()
{
    vector<int> nums = {1,3};
    int target = 3;
    cout<<search(nums, target)<<endl;
    return 0;
}