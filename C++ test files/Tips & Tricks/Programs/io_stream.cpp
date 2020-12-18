#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); // including this line will turn off the sync b/w c standard stream(printf) and c++ stream(cout), 
    //hence making your program fast, **but, you can use only cout then  
    cin.tie(NULL); // will stop flushing the o/p buffer before every i/p, as it is not required in competitive. It is reqd in active 
    //console programs
    for(int i=0; i<10; i++)
    {
        cout<<" hello cout"<<'\n';
        printf("hello printf \n");
    }
}