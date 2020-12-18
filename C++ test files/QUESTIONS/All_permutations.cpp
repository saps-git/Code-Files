#include<bits/stdc++.h>
using namespace std;
void Permute(string& str, int left, int right)
{
    if(left==right)
        cout<<str<<"\n";
    else
    {
        for(int i=left;i<=right;i++)
        {
            swap(str[left], str[i]);
            Permute(str, left+1, right);
            swap(str[left], str[i]);
        }
    }
    
}
int main()
{
    string str= "boat";
    int n= str.length();
    Permute(str, 0, n-1);
}