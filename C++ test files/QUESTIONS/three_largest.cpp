#include<bits/stdc++.h>
using namespace std;

void answerVec(vector<int>& ans, int x, int num){
    for(int i=0; i<=num; i++){
        if(i == num)
            ans[i] = x;
        else
            ans[i] = ans[i+1];
    }
}

void helper(vector<int>& ans, int x){
    if(x > ans[2])
        answerVec(ans, x, 2);
    else if(x > ans[1])
        answerVec(ans, x, 1);
    else if(x > ans[0])
        answerVec(ans, x, 0);
}

vector<int> threeLarge(vector<int> vec){
    vector<int> ans{INT_MIN, INT_MIN, INT_MIN};
    for(int i: vec){
        helper(ans, i);
    }

    return ans;
}

int main()
{
    vector<int> vec = {10,1,-1,45,6,7};
    vector<int> ans = threeLarge(vec);
    for(int i: ans)
        cout<<i<<"\t";
    cout<<endl;
}