#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec = {7,1,5,3,6,4};
    int buy = vec[0];
    int profit = 0;
    for(int i=1;i<vec.size();i++){
        profit = max(vec[i] - buy, profit);
        buy = min(buy, vec[i]);
    }
    cout<<profit<<endl;
}