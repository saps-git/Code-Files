#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s)
{
    int start = 0;
    int maxlen = 1;

    int low, high;

    for(int i=0;i<s.length();i++)
    {
        low = i;
        high = i;
        while(low>=0 && high<s.length() && s[low]==s[high])
        {
            if(maxlen < high - low + 1)
            {
                start = low;
                maxlen = high - low + 1;
            }
            low--;
            high++;
        }

        low = i-1;
        high = i;
        while(low>=0 && high<s.length() && s[low]==s[high])
        {
            if(maxlen < high - low + 1)
            {
                start = low;
                maxlen = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return s.substr(start, maxlen);
}
int main()
{
    string s = "abbbabbdbbba";
    cout<<longestPalindrome(s)<<endl;
}