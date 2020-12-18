#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums)
{
    int prev_min = 1;
    int prev_max = 1;
    int cur_min, cur_max;
    int product=1;
    for(int i=0;i<nums.size();i++)
    {
        cur_min = min(min(prev_max * nums[i], prev_min * nums[i]), nums[i]);
        cur_max = max(max(prev_max * nums[i], prev_min * nums[i]), nums[i]);
        product = max(product, cur_max);
        
        prev_min = cur_min;
        prev_max = cur_max;
    }
    return product;
}
int main()
{
    vector<int> nums = {2,3,-2,4};
    int i = maxProduct(nums);
    cout<<i<<endl;
}