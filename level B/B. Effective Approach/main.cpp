#include<bits/stdc++.h>
using namespace std;
int found_index[1000000];
int main()
{

   int n,q,x;

   cin>>n;
   int arr[n+1];

   unsigned long long sum1=0,sum2=0;


   for(int i=0;i<n;i++)
   {
       cin>>arr[i] ;
       found_index[arr[i]]=i+1;
   }

   cin>>q;

   for(int i=0;i<q;i++)
{
         cin>>x;
        int index_found=found_index[x];
        sum1+=index_found;
        sum2+=n-index_found+1;
}
  cout<<sum1<<" "  <<sum2;






}
