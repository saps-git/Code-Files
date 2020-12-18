#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> &nums)
{
    stack<int> st;
    vector<int> vec(nums.size(),-1); //intializing the solution vector

    st.push(0); //pushing the first element into stack

    for(int i=1;i<nums.size();i++)
    {
        while(!st.empty() && nums[st.top()] < nums[i]) //while the current element of the vector is greater than at the element at the pos of st.top of the vector, add it to the solution vector at the position of the the stack top
        {
            vec[st.top()] = nums[i];
            st.pop();
        }
        
        st.push(i); // if element less than the top of stack, add the position of the element to the stack
    }
    return vec;
}
int main()
{
    vector<int> nums = {11,13,21,1};
    vector<int> v = nge(nums);
    for(int i: v)
        cout<<i<<" ";
    cout<<endl;
}