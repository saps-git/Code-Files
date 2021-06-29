/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) 
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and 
moved to the sorted subarray. 

In Place : Yes
Stable : No
Time: O(n)

*/

#include<bits/stdc++.h>
using namespace std;
void swapHelp(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
vector<int> selectionSort(vector<int>& vec){
    int n = vec.size();
    for(int i=0;i<n-1;i++){
        int low = i;
        for(int j=i+1;j<n;j++){
            if(vec[low] > vec[j])
                low = j;
        }
        swapHelp(vec[i], vec[low]);
    }
    return vec;
}
int main()
{
    vector<int> vec ={13,45,2,6,78,10};
    vector<int> ans = selectionSort(vec);
    for(auto i: ans)
        cout<<i<<"\t";
    cout<<endl;
}