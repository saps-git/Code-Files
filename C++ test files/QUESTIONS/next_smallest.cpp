#include<bits/stdc++.h>
using namespace std;
vector<int> help_classmate(vector<int> array, int n) 
{ 
    vector<int> sol(n,-1);
    stack<int> st;
    for (int i=0;i<n;i++){ 

        /*
        if (st.empty()){ 
            st.push(i); 
            continue; 
        }
        */
        while (!st.empty() && array[st.top()] > array[i]) { 
            sol[st.top()] = array[i];
            st.pop(); 
        } 
        st.push(i); 
    } 
    
    return sol;
}

int main(){
    vector<int> vec = {4,8,5,2,25};
    int n = 5;
    vector<int> ans = help_classmate(vec, n);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
}