#include<iostream>
using namespace std;
int main(void)
{
int n,x,y=0,out=0;
cin>>n;
for(int i=0;i<n;i++)
{
 y=0;
 for(int j=0;j<3;j++)
 {
   cin>>x;
   if(x==1) y++;
 }
 if(y>1) out++;
}
cout<<out;
}
