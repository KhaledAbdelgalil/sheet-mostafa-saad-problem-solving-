#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,x;
  cin>>n>>x;
  char c;
  int flag=0;

    for(int i=0;i<n*x;i++)
 {
         cin>>c;
         if(c=='C'||c=='M'||c=='Y') flag=1;
 }

(flag==1)?cout<<"#Color":cout<<"#Black&White";
    return 0;
}
