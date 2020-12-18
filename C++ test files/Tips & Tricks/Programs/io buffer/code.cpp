#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //since there is no input.txt or output.txt file in the server, as they have their own input and output, hence we use this
    #ifndef ONLINE_JUDGE //macro ONLINE_JUDGE will see if there is an input.txt file on the server, if no , then will not the run the following commands
        freopen("input.txt","r",stdin); //will read from the input file
        freopen("output.txt","w",stdout); //will write to the output file
    #endif
    int x,a,b;
    cin>>x;
    for(int i=0; i<=2; i++)
    {
        cin>>a>>b;
        cout<<a-b<<'\n';
    }
}