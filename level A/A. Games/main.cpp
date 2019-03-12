#include<iostream>
using namespace std;

int host[109];
int guest[109];
int n,h,g;
int main()

{
    cin>>n;
    while(n--)
    {
      cin>>h>>g;
      host[h]++;
      guest[g]++;
    }
   unsigned int sum=0;
   for(int i=1;i<=100;i++)
   sum+=host[i]*guest[i];

   cout<<sum;

}
