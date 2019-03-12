#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i] ;
  }
sort(arr,arr+n);
for(int i=0;i<n-2;i++)
{
   if((arr[i]+arr[i+1]>arr[i+2])&&(arr[i+1]+arr[i+2]>arr[i])&&(arr[i]+arr[i+2]>arr[i+1]))
{
      cout<<"YES" ;return 0;
}
}


cout<<"NO";

return 0;
}
