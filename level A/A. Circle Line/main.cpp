#include<iostream>
using namespace std;



int main()
{

     int n;
     cin>>n;
     int d[n];
     int s,t;
     int sum1=0,sum2=0;
     for(int i=0;i<n;i++)
     {
     cin>>d[i];
     sum2+=d[i];
     }
     cin>>s>>t;

     for(int i=min(s,t)-1;i<max(s,t)-1;i++)
     sum1+=d[i];

     cout<<min(sum1,sum2-sum1);

}
