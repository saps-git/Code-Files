//If a permutation of the given string is it's palindrome

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str= "civggvi";
    unordered_set<char> p; //set only saves a single copy
    for(char c: str)
    {
        if(p.find(c)!=p.end()) //if the char is already present in the set, then erase it
            p.erase(c);
        else
            p.insert(c); //else add it to the set
    }
    if(p.size()<=1) //if size is less than or equal to 1(single middle char in palindrome) it is plaindrome
        cout<<"palindrome"<<"\n";
    else 
        cout<<"non palindrome"<<"\n";

}