#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& vec, int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;

    vector<int> a(n1);
    vector<int> b(n2);

    for(int i=0;i<n1;i++){
        a[i] = vec[l+i];
    }

    for(int i=0;i<n1;i++){
        b[i] = vec[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            vec[k] = a[i];
            i++;
            k++;
        }
        else{
            vec[k] = b[j];
            j++;
            k++;
        }
    }

    while(i < n1){
        vec[k] = a[i];
        i++;
        k++;
    }

    while(j < n2){
        vec[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& vec, int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(vec, l, mid);
        mergeSort(vec, mid+1, r);

        merge(vec, l, mid, r);
    }
}
int main(){
    vector<int> vec = {5,4,3,2,1};
    mergeSort(vec, 0, vec.size()-1);
    for(int i: vec)
        cout<<i<<" ";
    cout<<endl;
}