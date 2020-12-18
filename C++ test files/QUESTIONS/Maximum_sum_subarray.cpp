#include<bits/stdc++.h>
using namespace std;
// O(1) or constant space
int maxSum(vector<int>& nums)
{
    int maxEndingHere=0, maxSoFar= INT_MIN;
    for(int i: nums)
    {
        maxEndingHere = max(maxEndingHere + i, i);
        maxSoFar = max(maxSoFar,maxEndingHere);
    }
    return maxSoFar;
}
// O(n) space
/*
int maxSum(vector<int>& nums) 
{
    int n= nums.size();
    vector<int> sol;
    int maxEndingHere= nums[0];
    for(int i=1;i<n;i++)
    {
        maxEndingHere = max(maxEndingHere + nums[i],nums[i]);
        sol.push_back(maxEndingHere);
    }
    int maxSoFar = *max_element(sol.begin(), sol.end());
    return maxSoFar;
}
*/
int main()
{
    vector<int> nums = {2,3,-2,4};
    int i = maxSum(nums);
    cout<<i<<endl;
}