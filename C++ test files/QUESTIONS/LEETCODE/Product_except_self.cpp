#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>output;
        output.insert(output.begin(),1);
        for(int i=1;i<n;i++)
            output.push_back(output[i-1] * nums[i-1]);
        int x= 1;
        for(int i=n-1;i>=0;i--)
        {
            output[i]= output[i] * x;
            x= x * nums[i];
        }
        return output;
    }

int main()
{
	vector<int> nums = {1,2,3,4};
	vector<int> vec = productExceptSelf(nums);
    for(int i: vec)
        cout<<i<<" ";
    cout<<endl;
}
