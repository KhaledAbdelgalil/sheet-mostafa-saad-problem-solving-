#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  string x,y,temp;
  int sumx=0,sumy=0;
  for(int i=0;i<n;i++)
  {
      cin>>temp;
      if(i==0)
      {x=temp;sumx++;}
      else{

        if(x==temp) sumx++;
        else {sumy++;y=temp;}
      }
  }
if(sumx>sumy)cout<<x;
else cout<<y;
    return 0;
}
