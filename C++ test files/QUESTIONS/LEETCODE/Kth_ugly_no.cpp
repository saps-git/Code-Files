#include<bits/stdc++.h>
using namespace std;
int nthUglyNumber(int n)
{
    unsigned ugly[n-1];
    unsigned i2 = 0, i3 = 0, i5=0;
    unsigned nm2 = 2;
    unsigned nm3 = 3;
    unsigned nm5 = 5;

    ugly[0] = 1;
    int mn;
    for(int i=1;i<n;i++)
    {
        mn = min(nm2, min(nm3, nm5));
        ugly[i] = mn;

        if(mn == nm2)
        {
            i2++;
            nm2 = ugly[i2] * 2;
        }
        if(mn == nm3)
        {
            i3++;
            nm3 = ugly[i3] * 3;
        }
        if(mn == nm5)
        {            
            i5++;
            nm5 = ugly[i5] * 5;
        }
    }
    return mn;
}
int main()
{
    int num = 8;
    cout<<nthUglyNumber(num)<<endl;

}