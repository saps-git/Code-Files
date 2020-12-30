#include<bits/stdc++.h>
using namespace std;

// O(2n) = O(n) with space O(n)

char nonRepeating(string str){
    map<char,int> m;
    for(int i=0;i<str.length();i++){
        if(m.find(str[i])==m.end()) // if char is not present in the map, the add it , with no of occur or value is 1
            m.insert(make_pair(str[i],1));
        else 
            m[str[i]]++; // if it is already present, then just increment the number of occurence, or the value
    }

    for(int i=0;i<str.length();i++){ //iterating through the list and comparing with the map for the first non repeating char
        if(m[str[i]]==1)
            return str[i];
    }
    return '0';

}

int main(){
    string str = "aaabcccdeeef";
    char n = nonRepeating(str);
    cout<<n<<endl;
}