#include<bits/stdc++.h>
using namespace std;

// O(n.logn)
vector<int> smallestDiff(vector<int>& vec1, vector<int>& vec2){
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    vector<int> ans;
    int i = 0;
    int j = 0;
    int diff = INT_MAX; 
    int count = INT_MAX;

    while(i < vec1.size() && j < vec2.size()){
        int first = vec1[i];
        int second = vec2[j];

        if(first > second){
            count = first - second;
            j++;
        }

        else if(second > first){
            count = second - first;
            i++;
        }

        else{
            ans = {first, second};
            return ans;
        }

        if(count < diff){
            diff = count;
            ans = {first, second};
        }

    } 

    return ans;
}

int main()
{
    vector<int> vec1 = {-1,5,10,20,28,3};
    vector<int> vec2 = {26,134,135,15,17};

    vector<int> ans = smallestDiff(vec1, vec2);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
}