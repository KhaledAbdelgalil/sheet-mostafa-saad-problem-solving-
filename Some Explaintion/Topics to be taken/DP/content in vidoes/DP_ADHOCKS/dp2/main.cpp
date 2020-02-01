//spoj problem::https://www.spoj.com/problems/COINS/
//here n is very large can't memorize in array :try double memorization
#include <bits/stdc++.h>

using namespace std;

   map<unsigned long long,unsigned long long> mp;

unsigned long long ans(unsigned long long n)
{
    if(mp.count(n)) return mp[n];

    return mp[n]=ans(n/2)+ans(n/3)+ans(n/4);
}
int main()
{
    mp[0]=0;
   mp[1]=1;
   mp[2]=2;
   mp[3]=3;
   mp[4]=4;
   mp[5]=5;
   mp[6]=6;
   mp[7]=7;
   mp[8]=8;
   mp[9]=9;
   mp[10]=10;
   mp[11]=11;
   mp[12]=13;
   unsigned long long  x;
   while(cin>>x)
   {
       cout<<ans(x)<<endl;
   }
    return 0;
}
