#include<bits/stdc++.h>
using namespace std;
int main()
{
    int fac[] = {2,3,5};
    int k=0;
    int num = 15;
    while(k<3)
    {
        if(num%fac[k] == 0)
        {
            num /= fac[k];
            cout<<num<<"\n";
        }
        else
            k++;
    }
    if(num==1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

}