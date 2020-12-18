#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> sol(n, -1);
    stack<int> s;
    for(int i=0;i<n*2;i++) // extending(doubling) the array of itself like 1,2,1,1,2,1 ; so that we can traverse like a circular array
    {
        while(!s.empty() && nums[s.top()] < nums[i%n]) // to wrap around the circular array
        {
            sol[s.top()] = nums[i%n];
            s.pop();
        }
        if(i<n) //to store only the indexes of the elements of the initial size only, not the extended array
            s.push(i);
    }   
    return sol;     
}

int main()
{
    vector<int> nums = {1,2,1};
    vector<int> sol = nextGreaterElements(nums);
    for(int i: sol)
        cout<<i<<" ";
    cout<<endl;
}