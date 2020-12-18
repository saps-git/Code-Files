#include<bits/stdc++.h>
using namespace std;
bool compare(pair<char,int>& m1, pair<char,int>& m2)
{
    return m2.second < m1.second;
}
int main()
{
    string s = "tree";

    if(s[0] == '\0')
    {
        cout<<"w";
        return 0;
    }

    map<char,int> m;
    for(char i: s)
        m[i]++;

    vector<pair<char, int> > vec;
    for(auto i: m)
        vec.push_back(make_pair(i.first, i.second));
    
    sort(vec.begin(), vec.end(), compare);

    string ans;
    
    int x = 0;
    while(x<vec.size())
    {
        for(int i=0;i<vec[x].second;i++)
            ans.push_back(vec[x].first);

        x++;
    }

    cout<<ans<<endl;
    
}