#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1234;
    int ans = 0;
    while(n > 0){
        ans = 10*ans + (n%10);
        n = n/10;
    }

    cout<<ans<<endl;
}