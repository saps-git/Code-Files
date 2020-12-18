#include<bits/stdc++.h>
using namespace std;

// O(n) time with O(2n) space
void Trap(vector<int>& v)
{
    int n = v.size();
    int sum = 0;

    vector<int> left(n,0);
    vector<int> right(n,0);

    left[0] = v[0];
    for(int i=1;i<n;i++)
        left[i] = max(left[i-1], v[i]);
    
    right[n-1] = v[n-1];
    for(int i=(n-2);i>=0;i--)
        right[i] = max(right[i+1], v[i]);

    for(int i=1;i<n-1;i++)
        sum += (min(left[i], right[i]) - v[i]);

    cout<<sum<<endl;
}

// O(n2) time complexity
/*
int Helper(int n);

void Trap(int *v, int n)
{
    int sum =0 ;

    for(int i=0;i<n-1;i++)
    {
        int *r, *l;
        int m;

        r = max_element(v, v+i); // max on right of each element
        l = max_element(v+(i+1),v+n); // max on the left of each elenent

        (*r)<(*l)? m = *r : m = *l; // minimum of both of the above
        sum = sum + Helper(m-v[i]); // subtracting the above with the hight of building for amount of water that can be tapped and adding the same for every element  
    }
 
    cout<<sum<<endl;
}
//helper function to handle negative number
int Helper(int n)
{
    if(n<0)
        return 0;
    return n;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    
    /*
    int v[] = {0,2,1,3,0,1,2,1,2,1};
    int n = sizeof(v)/sizeof(v[0]);
    Trap(v, n);
    */

    vector<int> v = {0,2,1,3,0,1,2,1,2,1};
    Trap(v);
}
