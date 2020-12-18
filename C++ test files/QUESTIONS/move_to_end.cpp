#include<bits/stdc++.h>
using namespace std;

//O(n)
void swapElement(int& i, int& j){
    int temp = i;
    i = j;
    j = temp;
}

void elementEnd(vector<int>& vec, int ele){
    int i=0;
    int j=vec.size()-1;
    while(i<j){
        if(ele == vec[i]){
            if(ele == vec[j])
                j--;
            else{ 
                swapElement(vec[i], vec[j]);
                j--;
            }
        }
        else
            i++;
    }

    for(auto i: vec)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    vector<int> vec = {2,1,2,2,2,3,4,2};
    int ele = 2;
    elementEnd(vec, ele);
}