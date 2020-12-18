#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    unordered_map<int, int> mp;
    stack<int> s;
    for(int i=0;i<nums2.size();i++)
    {
        while(!s.empty() && nums2[s.top()] < nums2[i])
        {
            mp.insert(make_pair(nums2[s.top()],nums2[i])); 
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        mp.insert(make_pair(nums2[s.top()],-1));
        s.pop();
    }
    
    vector<int> sol;
    for(int i=0;i<nums1.size();i++)
    {
        auto it = mp.find(nums1[i]);
        sol.push_back(it->second);
    }

    return sol;
    
}

int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> sol = nextGreaterElement(nums1, nums2);
    for(int i: sol)
        cout<<i<<" ";
    cout<<endl;
}