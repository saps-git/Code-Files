#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>& v1, vector<int>& v2)
{
    if(v1[1]==v2[1])
        return v1[0]<v2[0];
    return v1[1]>v2[1];
}

void groupSort(vector<int> arr) 
{
    vector<vector<int> > vec;
    unordered_map<int, int> mp;
    int n = arr[0];
    for(int i=1;i<=n;i++)
    {
        if(mp.find(arr[i]) != mp.end())
            mp[arr[i]]++;
        else
            mp.insert(make_pair(arr[i], 1));
    }
   for(auto i: mp)
    {
        vec.push_back({i.first, i.second});
    }
    sort(vec.begin(), vec.end(), comp);
    
    for(int i=0; i<vec.size(); i++)
    {
        cout<<"[ ";
        for(int j=0;j<vec[0].size();j++)
            cout<<vec[i][j]<<", ";
        cout<<"]"<<endl;
    }


}
int main()
{
    vector<int> vec = {4,2,1,2,2};
    groupSort(vec);

}