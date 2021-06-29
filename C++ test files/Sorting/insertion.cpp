/*
Algorithm

1: Iterate from arr[1] to arr[n] over the array.
2: Compare the current element (key) to its predecessor.
3: If the key element is smaller than its predecessor, compare it to the elements before. 
Move the greater elements one position up to make space for the swapped element.

Sorting In Place: Yes
Stable: Yes
Time: O(n)

*/

#include<iostream>
#include<vector>
using namespace std;

void swapHelp(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

vector<int> insertionSort(vector<int>& vec){
    int n = vec.size();
    for(int i=1;i<n;i++){
        int j = i;
        while(j>=0 && vec[j-1] > vec[j]){
            swapHelp(vec[j], vec[j-1]);
            j--;
        }
    }

    return vec;
}
int main()
{
    vector<int> vec ={13,45,2,6,78,10};
    vector<int> ans = insertionSort(vec);
    for(auto i: ans)
        cout<<i<<"\t";
    cout<<endl;
}
