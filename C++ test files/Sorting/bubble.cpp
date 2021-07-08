/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
By seting the last element in sorted order after each round

Sorting In Place: Yes
Stable: Yes
Time: O(n**2)

*/
#include<bits/stdc++.h>
using namespace std;
void swapHelp(vector<int>& vec, int i, int j){
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}
void bubbleSort(vector<int>& vec){
    for(int i=0;i<vec.size();i++){
        for(int j=1;j<vec.size()-i;j++){
            if(vec[j-1] > vec[j])
                 swapHelp(vec, j, j-1);
        }
    }
}
int main()
{
    vector<int> vec ={13,45,2,6,78,10};
    bubbleSort(vec);
    for(auto i: vec)
        cout<<i<<"\t";
    cout<<endl;
}