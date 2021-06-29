#include<bits/stdc++.h>
using namespace std;
bool Anagram(string str1, string str2)
{
    vector<int> vec1(26,0); //taking two vectors of size 26, with 0 in all of the cells
    vector<int> vec2(26,0);

    if(str1.length()!=str2.length()) 
        return false;
    
    for(int i=0;i<str1.length();i++){
        vec1[str1[i]-'a']++;  //incrementing the value of the char in the vector as eg. 'n'-'a' = 13
        vec2[str2[i]-'a']++;
    }

    if(vec1 == vec2) //if both the vectors are equal, then it is true
        return true;
    return false;
}
int main()
{
    string str1 = "anagram";
    string str2 = "nagaram";
    Anagram(str1,str2)?cout<<"Anagram"<<"\n":cout<<"Not Anagram"<<"\n";
}