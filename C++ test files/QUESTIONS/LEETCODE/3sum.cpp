#include<bits/stdc++.h>
using namespace std;
void threeSum(vector<int>& nums)
{
    if(nums.size() <= 2)
        cout<<"[]";  // if size less than 2 return, as we need to find triplet
    
    vector<vector<int>> res;
    sort(nums.begin(), nums.end()); 

    for(int i=0;i<nums.size()-2;i++) // nums.size()-2 because we need to check the next two elements of every element
    {
        if(i==0 || (i>0 && nums[i] != nums[i-1]) ) // if 'i' is same is as 'i+1' that is same as next, then duplicate will arise, hence avoid
        {
            // setting two pointers
            int low = i+1;  // first = next element
            int high = nums.size()-1; //second = last element

            // remaining sum that needs to be found
            int sum = 0 - nums[i];
            
            while(low<high)
            {
                if(nums[low] + nums[high] == sum)
                {
                    res.push_back( {nums[i], nums[low], nums[high]} ); // if found, adding to the o/p matrix
                    while(low<high && nums[low]==nums[low+1]) // if any duplicates found, they are passed, so they don't come up again
                        low++;
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    
                    // as vec[i] might still have other triplet contenders so,
                    low++; //finally going to the real next element, that is no duplicate
                    high--;
                }

                else if(nums[low] + nums[high] > sum)
                    high--;

                else
                    low++;
            }
        }
    }


    for(int i=0; i<res.size(); i++)
    {
        cout<<"[ ";
        for(int j=0;j<res[0].size();j++)
            cout<<res[i][j]<<", ";
        cout<<"]"<<endl;
    }

}
int main()
{
    vector<int> nums = {-1,0,1,2,-1,4};
    threeSum(nums); 
}