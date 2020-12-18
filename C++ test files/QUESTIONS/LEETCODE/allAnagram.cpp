#include<bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> ans;
    vector<int> vec_s(26, 0);
    vector<int> vec_p(26, 0);
    
    int slen = s.size();
    int plen = p.size();
    
    if(plen > slen)
        return ans;
    
    int left = 0, right = 0;
    while(right < plen){
        vec_s[s[right]-'a']++;
        vec_p[p[right]-'a']++;
        right++;
    }
    
    right--;
    while(right < slen){
        if(vec_s == vec_p)
            ans.push_back(left);
        
        right++;
        if(right != slen)
            vec_s[s[right]-'a']++;
        vec_s[s[left]-'a']--;
        left++;
    }
    return ans;
}
int main()
{
    string s = "abb"; 
    string p = "bb";

    vector<int> ans = findAnagrams(s, p);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
}