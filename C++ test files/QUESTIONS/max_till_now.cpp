// Max element encountered till i

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec = {1,0,5,-9,6,8};
    int max = INT_MIN;
    for(int i=0;i<vec.size();i++){
        if(vec[i] > max)
            max = vec[i];

        cout<<max<<" ";
    }
    cout<<endl;
}