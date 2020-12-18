#include<bits/stdc++.h>
using namespace std;
int findNumbers(vector<int>& nums) 
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        if (((int)floor(log10(nums[i]))+1) % 2 == 0)
            sum=sum+1;
    }
    return sum;
}
int main()
{
	vector<int> nums = {12,345,2,6,7896};
	cout<<findNumbers(nums)<<endl;
}
