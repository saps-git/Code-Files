#include<bits/stdc++.h>
using namespace std;
//remove k digits from the number so that the new number is the smallest possible. 
/*

eg. Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

*/

//refer to the explanation video 

string removeKdigits(string num, int k){
    int n = num.size();
    stack<char> st;
    for(char c: num){
        while(!st.empty() && k>0 && st.top() > c){
            st.pop();
            k--;
        }

        if(!st.empty() || c != '0')
            st.push(c);
    }

    while(!st.empty() && k--)
        st.pop();
    
    if(st.empty())
        return "0";

    while(!st.empty()){
        num[n-1] = st.top();
        st.pop();
        n--;
    }

    return num.substr(n);
}

int main()
{
    string num = "1432219";
    int k = 3;
    cout<<removeKdigits(num, k)<<endl;
}