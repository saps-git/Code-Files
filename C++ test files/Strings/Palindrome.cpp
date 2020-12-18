#include<bits/stdc++.h>
using namespace std;
int palindrome(string& s)
{
    int i = 0;
    int j= s.length()-1;
    while(i<j)
    {
        if(s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int main()
{
    string str = "malayialam";
    int i = palindrome(str);
    i==1 ? cout<<"palindrome":cout<<"not a palindrome";
}