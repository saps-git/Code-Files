#include<bits/stdc++.h>
using namespace std;

//will use the sliding window technique

bool checkInclusion(string str1, string str2){
    int s1len = str1.size();
    int s2len = str2.size();

    if(s1len > s2len)
        return false;

    // taking two hashs one for each string, smaller one acts as the window
    vector<int> vec1(26, 0);
    vector<int> vec2(26, 0);

    int left = 0;
    int right = 0;

    while(right < s1len){
        vec1[str1[right]-'a']++; 
        vec2[str2[right]-'a']++;
        right++;
    }

    right--;
    while(right < s2len){
        if(vec1 == vec2)
            return true;

        right++;
        if(right != s2len)            
            vec2[str2[right]-'a']++;
        vec2[str2[left]-'a']--;
        left++;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str1 = "ab";
    string str2 = "eidbaooo";
    checkInclusion(str1, str2) ? cout<<"true"<<endl : cout<<"false"<<endl;
}