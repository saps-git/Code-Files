#include<bits/stdc++.h>
using namespace std;
void subsequence(string ip, string op){
    if(ip.length() == 0){ // when input string is zero, print the output string 
        cout<<op<<"\n";
        return;
    }
    
    //making two output strings
    string op1 = op; 
    string op2 = op;
    op2.push_back(ip[0]); //pushing the first letter of the input string on the output string

    ip.erase(ip.begin() + 0); // erasing the first letter in the input string

    subsequence(ip, op1); //calling the funuction with different output strings
    subsequence(ip, op2);
}
int main()
{
    string ip = "abc";
    string op = " ";
    subsequence(ip, op);
}