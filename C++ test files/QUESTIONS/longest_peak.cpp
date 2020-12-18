#include<bits/stdc++.h>
using namespace std;
//O(n)
int longestPeak(vector<int> vec){
    int long_peak = 0;
    int new_peak = 0;
    for(int i=1;i<vec.size();i++){
        if(vec[i] > vec[i-1] && vec[i] > vec[i+1]){
            while(vec[i]>vec[i+1]){
                new_peak += 1;
                i++;
            }
            if(long_peak < new_peak)
                long_peak = new_peak;
            new_peak = 0;
        }
        else if(vec[i] > vec[i-1]){
            new_peak +=1;
        }

    }
    return long_peak+2; //since it won't count the starting and the ending element, therefore +2
}
int main()
{
    vector<int> vec = {1,2,3,3,4,1,10,6,5,-1,-3,2,3};
    cout<<longestPeak(vec)<<endl;
}