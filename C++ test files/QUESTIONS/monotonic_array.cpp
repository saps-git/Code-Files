#include<bits/stdc++.h>
using namespace std;
bool breakDir(int diff, int first, int second){
    int direction = first - second;
    if(diff > 0)
        return direction < 0;
    else
        return direction > 0;
}

bool monotonic(vector<int>& vec){
    int diff = vec[0]-vec[1];
    for(int i=1;i<vec.size()-1;i++){
        if(diff == 0){
            diff = vec[i]-vec[i+1];
            continue;
        }
        if(breakDir(diff, vec[i], vec[i+1]))
            return false;
    }
    
    return true;
}

int main()
{
    vector<int> vec = {5,2,-10,-1100,-1100,-1101,-1102,-9001};
    
    if(monotonic(vec))
        cout<<"monotonic"<<endl; 
    else
        cout<<"non-monotonic"<<endl;
}