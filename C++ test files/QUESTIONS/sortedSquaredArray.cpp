#include<bits/stdc++.h>
using namespace std;
// O(n*logn) time , no extra space
/*
void sortedSqr(int arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i] *= arr[i];

    sort(arr, arr+n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
*/
// O(n) time, O(n) space

void sortedSqr(int arr[], int n)
{
    int l = 0;
    int r = n-1;
    int sol[n];
    for(int i=n-1;i>=0;i--)
    {
        if(l>r)
            break;
        if(abs(arr[l])>abs(arr[r]))
        {
            sol[i] = arr[l];    
            l++;
        }
        else if(abs(arr[l])<abs(arr[r]))
        {
            sol[i] = arr[r];
            r--;
        }
        else if(abs(arr[l]) == abs(arr[r]))
        {
            sol[i] = arr[l];
            l++;
            r--;
        }       
    }
    for(int i=0;i<n;i++)
    {
        cout<<sol[i]*sol[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int arr[] = {-6,-4,1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortedSqr(arr,n);
}