#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition (int arr[],int l,int h)
{
    int pivot = arr[h];
    int i=(l-1);
    for(int j=l;j<=h-1;j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return (i+1);
}
void quickSort(int arr[],int l,int h)
{
    if (l<h)
    {
        int pi = partition(arr,l,h);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,h);
    }
}
int main()
{
	int n,i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	int A[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>A[i];
	}
	quickSort(A,0,n-1);
	cout<<"\nSorted Data ";
	for (i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
