#include <bits/stdc++.h>
using namespace std;
int coins[5]={1,5,10,25,50};
long long mem[30005];
void init()
{
    mem[0]=1;
    for(int j=0;j<5;j++)
        for(int coin=coins[j];coin<30005;coin++)
            mem[coin]+=mem[coin-coins[j]];
}
int main()
{
    int n;
    init();
    while(cin>>n)
    {
        if(cin.eof())break;
        long long ans=mem[n];
        if(ans==1)
            cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        else
            cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change.\n";
    }
    return 0;
}
