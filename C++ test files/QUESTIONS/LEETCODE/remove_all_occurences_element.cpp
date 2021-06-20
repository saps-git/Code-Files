//Remove all occurence of an element

#include<bits/stdc++.h>
using namespace std;
void removeElement(vector<int>& nums, int val){
    int n = nums.size();
    int i = 0;
    while(i < n){
        if(nums[i] == val){
            nums.erase(nums.begin()+i);
            n--;
        }
        else
            i++;
    }
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    removeElement(nums, val);
    for(int i: nums)
        cout<<i<<" ";
    cout<<endl;
}