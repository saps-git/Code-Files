/*

A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same.
For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic:

1, 1, 2, 5, 7

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec = {10, 7, 4, 6, 8, 10, 11};
    int diff = vec[1]-vec[0]; //initial diff b/w first 2 elements
    int ans = 2; //minimum length of the subarray would be 2 elements 
    int curr_len = 2; //same for curr subarray length(on which we'd check)
    for(int i=2; i<vec.size(); i++){
        if(diff == (vec[i] - vec[i-1]))
            curr_len++;

        else{
            diff = vec[i] - vec[i-1];
            curr_len = 2;
        }
        ans = max(curr_len, ans);
    }

    cout<<ans<<endl;
}