#include<bits/stdc++.h>
using namespace std;
int jump(int curr, vector<int> vec){
    int jump = vec[curr];
    int next = (curr + jump) % (int)vec.size();
    return next >= 0 ? next : next+vec.size();
}
bool single_cycle(vector<int> vec, int n){
    int visited = 0;
    int curr = 0;
    
    while(visited < n){
        if(visited > 0 && curr == 0)
            return false;
        
        visited++;
        curr = jump(curr, vec);
    }

    return curr == 0;
}
int main()
{
    vector<int> vec = {2,3,1,-4,-4,2};
    int n = vec.size();
    cout<<single_cycle(vec, n)<<endl;
}