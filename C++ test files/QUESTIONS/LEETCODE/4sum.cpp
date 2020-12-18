#include<bits/stdc++.h>
using namespace std;

void fourSum(vector<int>& nums, int target) 
{
    if(nums.size() <= 3)
        cout<<"[]";
    
    vector<vector<int>> vec;
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size()-3;i++)
    {
        if(i==0 || (i>0 && nums[i] != nums[i-1]))
        {
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j==i+1 || (j>i+1 && nums[j] != nums[j-1]))
                {
                    int low = j+1;
                    int high = nums.size()-1;
                    while(low<high)
                    {
                        if(nums[i]+nums[j]+nums[low]+nums[high] == target)
                        {
                            vec.push_back({nums[i], nums[j], nums[low], nums[high]});
                            while(low<high && nums[low] == nums[low+1])
                                low++;
                            while(low<high && nums[high] == nums[high-1])
                                high--;
                            low++;
                            high--;
                        }
                        else if(nums[i]+nums[j]+nums[low]+nums[high] > target)
                            high--;
                        else if(nums[i]+nums[j]+nums[low]+nums[high] < target)
                            low++;
                    }
                }
            }
        }
    }
    for(int i=0;i<vec.size();i++)
    {
        cout<<"[ ";
        for(int j=0;j<vec[0].size();j++)
            cout<<vec[i][j]<<", ";
        cout<<"]"<<endl;
    }
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    fourSum(nums, target);
}