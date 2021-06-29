/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
By seting the last element in sorted order after each round

Sorting In Place: Yes
Stable: Yes
Time: O(n)

*/
#include<bits/stdc++.h>
using namespace std;
void swapHelp(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
vector<int> bubbleSort(vector<int>& vec){
    int n = vec.size();
    for(int i=0;i<n;i++){
        for(int j = 0;j<n-i;j++){
            if(vec[j] > vec[j+1])
                swapHelp(vec[j], vec[j+1]);
        }
    }

    return vec;
}
int main()
{
    vector<int> vec ={13,45,2,6,78,10};
    vector<int> ans = bubbleSort(vec);
    for(auto i: ans)
        cout<<i<<"\t";
    cout<<endl;
}