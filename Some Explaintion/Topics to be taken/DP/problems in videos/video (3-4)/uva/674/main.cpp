#include <bits/stdc++.h>
using namespace std;
int coins[5]={1,5,10,25,50};
long long mem[7500];
void init()
{
    mem[0]=1;
    for(int j=0;j<5;j++)
        for(int coin=coins[j];coin<7500;coin++)
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
        cout<<ans<<endl;
    }
    return 0;
}
