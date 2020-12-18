#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> vec, int k, int index)
{
    if(vec.size() == 1){ // when size becomes 1, that is only the final element is left
        return vec[0]; // return it
    }
    
    index = (index + k) % vec.size(); // the index to be removed, (curr index that holds sword + skip value) % size, as it has to be round
    vec.erase(vec.begin()+index); // erasing that element
    
    return solve(vec, k, index); // again calling the function
}
int main()
{
    vector<int> vec = {1,2,3,4,5};
    int k = 2; // skip value
    int index = 0; // starting index which will hold the first sword
    cout<<solve(vec, k-1, index)<<endl; // k-1 is passed so as to eliminate kth  index only
}
