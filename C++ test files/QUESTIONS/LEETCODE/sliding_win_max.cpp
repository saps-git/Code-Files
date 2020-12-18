#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    vector<int> ans;
    if(k > nums.size()){ //if k is more than the size of the vector, return just the single max element
        ans.push_back(*max_element(nums.begin(),nums.end()));
        return ans;
    }

    deque<int> sol; //deque(insert, delete from end), to keep a list of the current highest value
    int i=0, j=0;

    while(j < nums.size()){
        while(sol.size() > 0 && sol.back() <= nums[j]) //if the last value in the deque is less than the j, then remove all the elements in the deque, as the first element in the deque is the max value currently  
            sol.pop_back();

        sol.push_back(nums[j]); // push the val

        if(j-i+1 == k){ // if reach the window size
            ans.push_back(sol.front()); //push the front of deque as it is the current largest number

            if(nums[i] == sol.front()) //if i is equal to front of deque, it means it is past the starting of the window, then remove from the deque, else we didn't add it to the deque as it was less value
                sol.pop_front();

            i++; //move starting of the the window forward (when window size is reached)
        }

        j++; // move end of the window anyways
    }

    return ans;    
}
int main()
{
    vector<int> nums = {9,11,2,3};
    int k = 2;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
}