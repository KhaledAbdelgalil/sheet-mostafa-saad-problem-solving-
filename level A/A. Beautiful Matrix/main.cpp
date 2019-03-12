#include<iostream>
using namespace std;
int main(void)
{

int x,out,r,c;
for(int i=1;i<=5;i++)
{
for(int j=1;j<=5;j++)
{
     cin>>x;
     if(x==1)
     {
         r=i;
         c=j;
         goto yala;
     }
}
}
yala:out=abs(r-3)+abs(c-3);
cout<<out;
}
