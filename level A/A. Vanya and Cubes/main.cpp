#include<iostream>
using namespace std;

int main()
{
   int n,s=0;
   cin>>n;
   int i=0;

   while(n>0)
   {
        i++;
        s+=i;
        n-=s;


   }

 (n>=0)?cout<<i:cout<<--i;

}
