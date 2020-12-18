#include<iostream>
#include<vector>
using namespace std;
int pairing(vector<int> vec)
{
    int ans = 0;
    for(int i=0;i<vec.size();i++)
        ans = ans^vec[i];
    
    return ans;
}
int main()
{
    vector<int> vec = {7,6,56,76,6,7,76};
    cout<<pairing(vec)<<endl;
}
