#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int> vec){
    if(vec.size() == 0)
        return 0;
    else if(vec.size() == 1)
        return vec[1];

    int first = vec[0];
    int second = max(vec[0], vec[1]);
    for(int i=2;i<vec.size();i++){
        int curr = max(second, first+vec[i]);
        first = second;
        second = curr;
    }

    return second;
}
int main()
{
    vector<int> vec = {7,10,12,7,9,14};
    cout<<maxSum(vec)<<endl;
}