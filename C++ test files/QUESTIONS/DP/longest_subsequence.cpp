#include<bits/stdc++.h>
using namespace std;
//Memoized
vector<vector<int>> dp; //global 2D vector

int longest(string text1, string text2, int len1, int len2){
    if(len1 == 0 || len2 == 0)
        return 0;

    if(dp[len1][len2] != -1)
        return dp[len1][len2];

    if(text1[len1-1] == text2[len2-1])
        return dp[len1][len2] = longest(text1, text2, len1-1, len2-1) + 1;

    else
        return dp[len1][len2] = max(longest(text1, text2, len1-1, len2) , longest(text1, text2, len1, len2-1));
}
//Recursive
/*
int longest(string text1, string text2, int len1, int len2){
    if(len1 == 0 || len2 == 0) //base, if either of string's length becomes zero
        return 0;

    else if(text1[len1-1] == text2[len2-1]) //if the current element is same
        return longest(text1, text2, len1-1, len2-1) + 1; //then remove the last element, and call for shorter, aslo add +1 to keep count

    else // else, take max of, if you remove the element from first and keep the second same, or, if you remove the element from second and keep the first same
        return max(longest(text1, text2, len1-1, len2) , longest(text1, text2, len1, len2-1));
}
*/
int main()
{
    string text1 = "abcde", text2 = "ace";
    int len1 = text1.size();
    int len2 = text2.size();
    
    dp.resize(len1+1, vector<int> (len2+1, -1)); //filling the vector with -1

    cout<<longest(text1, text2, len1, len2)<<endl;    
}