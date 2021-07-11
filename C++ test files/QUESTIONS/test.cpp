#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec = {1,5,3,4,3,5,6};
    map<int, int> mp;

    for(int i: vec){
        if(mp.find(i) != mp.end())
            mp[i]++;
        else
            mp.insert({i, 1});
    }

    for(int i=0;i<vec.size();i++){
        if(mp[vec[i]] > 1){
            cout<<i+1<<endl;
            break;
        }
    }
}