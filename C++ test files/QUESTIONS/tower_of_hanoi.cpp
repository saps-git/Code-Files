#include<iostream>
using namespace std;
void tow(int n,char from,char to,char aux)
{
    if(n==1){
        cout<<"move disk 1 from "<<from<<" to "<<to<<endl;
        return;
    }
    tow(n-1,from,aux,to);
    cout<<"move disk "<<n<<" from "<<from<<" to "<<to<<endl;
    tow(n-1,aux,to,from);
}
int main()
{
    int n;
    cout<<"enter the number of disks ";
    cin>>n;
    tow(n,'a','c','b');
}
