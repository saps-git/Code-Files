/*
Train                                     Time
Train 1: ----------++++++++---------------------------------------------
Train 2: ----------------------++++++++++++++---------------------
Train 3: -----++++++++++++++--------------------------------------
Train 4: ---------------------------------------+++++++++++----------
Train 5: --------------+++++++++++++++++++++--------------
Train 6: -----------------------------+++++++++------------------------

Make each train a fixed size array filled with 1 and 0 where 1 means occupied and 0 means not occupied based on the arrival and departure time. 
Add all array together and find argmax(sum of arrays). O(N) complexity.

** The fixed size array can be a single array of size [2361] as time range from 0 to 2359 in 24 hour clock, 
     we declare an array for values from 0 to 2360  and incr when train arrived, decr when train leaves.
*/

#include<bits/stdc++.h>
using namespace std;
int platform(vector<double> vec1, vector<double> vec2){
     vector<int> sol(2361, 0); //initialiszing all values by 0
     for(int i=0;i<vec1.size();i++){
        int a = vec1[i]*100; //multiplying by 100 to convert it into int
        int b = vec2[i]*100;
        sol[a]++; // when train arrives icr
        sol[b+1]--; //when train leaves decr next value, as for that value train will be there
     }
     int ans = 1; 
     for(int i=1;i<2361;i++){
        sol[i] = sol[i] + sol[i-1]; //adding all the previous values, like adding all the different arrays of trians
        ans  = max(sol[i], ans); //and checking for the max value along the way i.e max trains at a single time
     }
     return ans;
}
int main()
{
    vector<double> vec1 = {9.00, 9.40, 9.50, 11.00, 15.00, 18.00};
    vector<double> vec2 = {9.10, 12.00, 11.20, 11.30, 19.00, 20.00};
    cout<<platform(vec1, vec2)<<endl;
}