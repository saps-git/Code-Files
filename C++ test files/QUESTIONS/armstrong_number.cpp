#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num = 153;
    int ans = 0;
    int originalNum = num;
    while(num > 0){
        int temp = num%10;
        ans = ans + pow(temp, 3);
        num = num/10;
    }

    if(originalNum == ans)
        cout<<"Armstrong number"<<endl;
    else
        cout<<"Not an Armstrong number"<<endl;

}