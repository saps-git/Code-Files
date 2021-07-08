/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) 
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and 
moved to the sorted subarray. 

In Place : Yes
Stable : No
Time: O(n**2)

*/

#include<bits/stdc++.h>
using namespace std;
void swapHelp(vector<int>& ans, int i, int j){
    int temp = ans[i];
    ans[i] = ans[j];
    ans[j] = temp;
}

void selectionSort(vector<int>& ans){
    for(int i=0;i<ans.size()-1;i++){
        for(int j=i+1;j<ans.size();j++){
            if(ans[j] < ans[i])
                swapHelp(ans, i, j);
        }
    }
}

int main()
{
    vector<int> vec ={13,45,2,6,78,10};
    selectionSort(vec);
    for(auto i: vec)
        cout<<i<<"\t";
    cout<<endl;
}