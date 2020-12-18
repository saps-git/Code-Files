#include<bits/stdc++.h>
using namespace std;
int findPeak(vector<int> vec){
    int peak = 0;
    for(int i=1;i<vec.size();i++){
        if(i == vec.size()-1){
            if(vec[i] > vec[i-1])
            peak = i;
        }
        else
        {
            if(vec[i] > vec[i-1] && vec[i] > vec[i+1])
            peak = i;
        }
        
    }
    return peak;
}
int main()
{
    vector<int> vec = {1,2,3,3,4,2};
    cout<<findPeak(vec)<<endl;
}