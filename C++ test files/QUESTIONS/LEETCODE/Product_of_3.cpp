#include<bits/stdc++.h>
using namespace std;
int maximumProduct(vector<int>& nums)
{
    int n = nums.size();
    sort(nums.begin(),nums.end());

    int max1 = nums[n-1] * nums[n-2] * nums[n-3];
    int max2 = nums[0] * nums[1] * nums[n-1];

    return max(max1, max2);
    
    
}
int main()
{
    vector<int> nums = {1,2,5,3,4};
    int i = maximumProduct(nums);
    cout<<i<<endl;


}