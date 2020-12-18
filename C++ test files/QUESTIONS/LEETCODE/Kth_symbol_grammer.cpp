#include<bits/stdc++.h>
using namespace std;

/*

0
0 1
0 1 1 0
0 1 1 0 1 0 0 1

*/

/*
in the above grammer we can see that, half(till mid) of the element in every row is same as above
and the other half is just the complement of it.
*/

int kthGrammar(int N, int K){
    if(N==1 && K==1)
        return 0;

    int mid = (pow(2, N-1))/2; //finding the mid

    if(K <= mid) // if col no. is less than mid
        return kthGrammar(N-1, K); // same as above
    else // if col no. is greater than mid
        return !kthGrammar(N-1, K-mid); // complement of above row
}
int main()
{
    int N = 2, K = 1;
    cout<<kthGrammar(N, K)<<endl;
}

 