#include<bits/stdc++.h>
using namespace std;
void deleteMid(stack<int>& st, int k){
    if(st.size() == 0){
        cout<<"invalid";
        return;
    }

    if(k == 1){ //if k=1 , i.e we have reached the middle of the stack
        st.pop(); //pop the element out
        return;
    }

    int x = st.top(); //else for all the other element above it, store them in a var
    st.pop(); //and pop for now
    deleteMid(st, k-1); //calling the function for k-1
    st.push(x); // after it has returned, on the way back, push the element back
    return;
}

int main()
{
    stack<int> st;
    st.push(1); 
    st.push(2); 
    st.push(3); 
    st.push(4); 
    st.push(5); 
    st.push(6); 
    st.push(7); 

    int k = (st.size()/2) + 1; //middle element to be deleted
    deleteMid(st, k);

    while (!st.empty()) 
    { 
        int p=st.top(); 
        st.pop(); 
        cout<<p<<" "; 
    }
    cout<<endl; 
}