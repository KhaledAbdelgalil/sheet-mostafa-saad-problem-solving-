#include<iostream>
#include<math.h>
using namespace std;


int main()
{
   int a,b,sum1=0,sum2=0;
   cin>>a>>b;

   for(int i=1;i<=6;i++)
   {
     if(abs(a-i)<abs(b-i)) sum1++;
     else if (abs(a-i)>abs(b-i)) sum2++;
   }
             cout<<sum1<<" " <<6-sum1-sum2<<" "<<sum2;
}
