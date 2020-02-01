#include <bits/stdc++.h>
using namespace std;
//this problem needs bigint in java
 long long mem[1001];
 long long nways(int n)
{
    if(n==1)return 2;
    if(n==2)return 5;
    if(n==3)return 13;
    long long &ret=mem[n];
    if(ret!=-1)return ret;

    return ret=2*nways(n-1)+nways(n-2)+nways(n-3);
}
void init()
{
    mem[1]=2;
    mem[2]=5;
    mem[3]=13;
    for(int i=4;i<=1000;i++)
        mem[i]=2*mem[i-1]+mem[i-2]+mem[i-3];
}
int main()
{
    freopen("o.txt","w",stdout);
    memset(mem,-1,sizeof mem);
    int n;
    while(cin>>n)
    {
        cout<<nways(n)<<endl;
    }
    return 0;
}
