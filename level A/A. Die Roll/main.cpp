#include<bits/stdc++.h>

using namespace std;

int main()
{
   int out=0,x,y;
   cin>>x>>y;
   x=max(x,y);
   out+=6-x+1;
   if(out==6)cout<<"1/1";
   else if(out==2)cout<<"1/3";
   else if(out==3)cout<<"1/2";
   else if(out==4)cout<<"2/3";
   else cout<<out<<"/6";
    return 0;
}
