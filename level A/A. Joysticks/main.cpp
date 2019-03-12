#include<bits/stdc++.h>

using namespace std;

int main()
{

  int flag=0,count1=0;//0 n1 1 n2;
  int n1,n2;

  cin>>n1>>n2;
  if(n1<2&&n2<2)
  {
   cout<<0;
   return 0;
  }
  if(n1>n2) flag=1;
  while(n1>0&&n2>0)
  {
     if(flag==0)
  {
     n1+=1;
     n2-=2;
     if(n2<=2) flag=1;
  }
  else
  {
       n2+=1;
     n1-=2;
      if(n1<=2) flag=0;
  }
  count1++;
  }
  cout<<count1;
    return 0;
}
