#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> val = { 4, 5, 3, 7, 1 };
    vector<int> wt =  { 2, 3, 1, 4, 5 };
    int n = val.size()-1; // last element of the array
    int W = 5;
    cout<<endl<<knapsack(val, wt, W, n)<<endl;
}