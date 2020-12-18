#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec = {0,1,2,0,1,2};
    int l = vec[0];
    int m = vec[0];
    int h = vec.size()-1;

    while(m<=h)
    {
        if(vec[m]==0)
        {
            swap(vec[l],vec[m]);
            l++;
            m++;
        }
        else if(vec[m]==1)
        {
            m++;
        }
        else if(vec[m]==2)
        {
            swap(vec[m],vec[h]);
            h--;
        }
    }

    for(int i: vec)
        cout<<i<<" ";
    cout<<endl;
}