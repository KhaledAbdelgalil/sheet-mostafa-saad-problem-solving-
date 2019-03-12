#include<iostream>
using namespace std;
int main(void)
{
int steps=0;
int n;
cin>>n;
steps+=n/5;
n=n%5;
steps+=n/4;
n=n%4;
steps+=n/3;
n=n%3;
steps+=n/2;
n=n%2;
steps+=n/1;
n=n%1;

    cout<<steps;

return 0;
}
