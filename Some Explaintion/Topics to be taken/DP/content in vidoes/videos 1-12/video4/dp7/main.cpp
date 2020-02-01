//uva problems(357-674)

#include <bits/stdc++.h>
using namespace std;
//357-1
int coins[]={1,5,10,25,50};
long long mem[5][30001];
long long rec_mem_357(int idx,int rem)
{
    if(rem==0) return 1;
    if(rem<coins[idx]||idx==5) return 0;
    long long &ret=mem[idx][rem];
    if(ret!=-1) return ret;
    return ret=rec_mem_357(idx+1,rem)+rec_mem_357(idx,rem-coins[idx]);
}
//357-2
long long table_2d[5][30001];
void init_table2d()
{
    for(int i=0;i<5;i++)
        table_2d[i][0]=1;
    for(int coin=coins[0];coin<30001;coin++)
        for(int i=0;i<5;i++)
    {
        if(i)table_2d[i][coin]=table_2d[i-1][coin];
        if(coin-coins[i]>=0)
            table_2d[i][coin]+=table_2d[i][coin-coins[i]];
    }
}
//357-3
long long mem_1d[30005];
void init_1d()
{
    mem_1d[0]=1;
    for(int i=0;i<5;i++)
        for(int coin=coins[i];coin<30001;coin++)
            mem_1d[coin]+=mem_1d[coin-coins[i]];
}
void solve_357()
{
    int n;
    long long ans;
    //init_table2d();
    init_1d();
    while(scanf("%d",&n)!=EOF)
    {
        //memset(mem,-1,sizeof mem);
        //ans=rec_mem_357(0,n);
       // ans=table_2d[4][n];
       ans=mem_1d[n];
        if(ans==1)
            cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        else
            cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change."<<endl;
    }
}
//674 as 357
void solve_674()
{

    int n;
    long long ans;
    init_1d();
    while(scanf("%d",&n)!=EOF)
    {

       ans=mem_1d[n];
       cout<<ans<<endl;
    }
}
int main()
{
   //solve_357();
   //solve_674();
    return 0;
}
