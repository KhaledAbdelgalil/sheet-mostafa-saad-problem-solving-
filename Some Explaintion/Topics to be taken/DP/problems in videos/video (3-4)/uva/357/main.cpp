#include <bits/stdc++.h>
using namespace std;
int coins[5]={1,5,10,25,50};
long long mem[5][300005];
long long nways(int idx,int rem)
{
    if(rem==0) return 1;
    if(rem<coins[idx]||idx==5)return 0;
    long long &ret=mem[idx][rem];
    if(ret!=-1)return ret;
    ret=nways(idx+1,rem)+nways(idx,rem-coins[idx]);
    return ret;
}
int main()
{
    int n;
    memset(mem,-1,sizeof mem);
    while(cin>>n)
    {
        if(cin.eof())break;
        long long ans=nways(0,n);
        if(ans==1)
            cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        else
            cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change.\n";
    }
    return 0;
}
