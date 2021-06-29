#include<bits/stdc++.h>
using namespace std;
void swap(vector<int>& vec, int i, int j){
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

int partition(vector<int>& vec, int l, int r){
    int pivot = vec[r];
    int i = l-1;

    for(int j=1;j<r;j++){
        if(vec[j] < pivot){
            i++;
            swap(vec, i, j);
        }
    }

    swap(vec, i+1, r);
    return i+1;
}

void quickSort(vector<int>& vec, int l, int r){
    if(l < r){
        int pi = partition(vec, l, r);
        quickSort(vec, l, pi-1);
        quickSort(vec, pi+1, r);
    }
}

int main(){
    vector<int> vec = {5,4,3,2,1};
    quickSort(vec,0,vec.size()-1);
    for(int i: vec)
        cout<<i<<" ";
    cout<<endl;

}

