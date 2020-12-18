#include<bits/stdc++.h>
using namespace std;
void Swap(string& s, int i, int j) //helper function to reverse (swap in place)
{
    while(i<j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}
void Reverse(string& s)
{
    if(s.empty())
        return;
    Swap(s,0,s.length()-1); // will return as reversed string 'ihsratpas mai olleh'
    //now we can just reverse that again, in order to get our o/p
    int x=0; // word var for swapping the char in word
    for(int i=0;i<=s.length();++i)
    {
        if(i==s.length() || s[i]==' ')
        {
            Swap(s,x,i-1); // will reverse every word, char by char swapping
            x= i+1; // word var set to staring index of next word
        }
    }
    cout<<s<<endl;

}
int main()
{
    string s;
    s= "hello iam saptarshi";
    Reverse(s);
}