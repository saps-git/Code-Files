#include<bits/stdc++.h>
using namespace std;
bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    int i = 0;
    int j = 0;
    while(i<array.size() && j<sequence.size())
    {
        if(array[i] == sequence[j])
            j++;
        i++;
    }
    return j == sequence.size(); // if true , then return 1, else 0
}
int main()
{
    vector<int> array = {5,1,22,25,6,-1,8,10};
    vector<int> sequence = {1,6,-1,10};
    isValidSubsequence(array, sequence) ? cout<<"true" : cout<<"false";
    cout<<endl;
}