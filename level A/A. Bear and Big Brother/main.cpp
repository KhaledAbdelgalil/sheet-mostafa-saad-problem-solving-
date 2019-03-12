#include<iostream>
using namespace std;
int main(void)
{
int a,b;
cin>>a>>b;
int out=0;
while(a<=b)
{
a*=3;
b*=2;
out++;
}
cout<<out;
}
