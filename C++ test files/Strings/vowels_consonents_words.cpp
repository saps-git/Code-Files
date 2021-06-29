#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "hello how are you";
    int vowel=0,consonent=0,word = 1;
    for(int i=0; i<str.length();i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||str[i]=='o' || str[i]=='u')
            vowel++;
        else if(str[i]>=97 && str[i]<=122)
            consonent++;
    }
    cout<<"vowel: "<<vowel<<" "<<"consonent: "<<consonent<<" ";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ' && str[i-1]!=' ')
            word++;
    }
    cout<<"word: "<<word<<endl;

}