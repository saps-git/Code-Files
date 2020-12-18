// If we have a subset with the given sum

#include<bits/stdc++.h>
using namespace std;
bool sumSubset(vector<int> vec, int sum, int n){
    if(sum == 0)
        return true; // if sum becomes 0, then we have a subset
    if(n == 0) 
        return false;  // if elements end before a subset is found, then false     

    // similar to knapsack
    if(vec[n-1] > sum)
        return sumSubset(vec, sum, n-1); 

    return sumSubset(vec, sum-vec[n-1], n-1) || sumSubset(vec, sum, n-1);
    
}
int main()
{
    vector<int> vec = {3, 34, 4, 12, 5, 2};
    int n = vec.size();
    int sum = 11;
    if(sumSubset(vec, sum, n) == true)
        cout<<"true";
    else
        cout<<"false";
    cout<<endl;
}