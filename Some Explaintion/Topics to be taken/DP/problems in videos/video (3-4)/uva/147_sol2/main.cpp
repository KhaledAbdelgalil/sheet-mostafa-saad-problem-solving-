//uva problems :147
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int coins[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};

long long mem_1d[30005];//the most important one very important
void init_mem1d()
{
    mem_1d[0]=1;
    for(int j=0;j<11;j++)
    {

        for(int coin=coins[j];coin<30005;coin+=5)
        {
            mem_1d[coin]+=mem_1d[coin-coins[j]];
        }
    }
}
void solve_147()
{
     double num;

     init_mem1d();
    while (scanf("%lf", &num), num > 0.0000001)
    {
        int n=static_cast<int>(num*100+0.5);//note that cast

       cout << right << setw(6) << setprecision(2) << fixed << num << right << setw(17) << mem_1d[n]<< endl;
    }
}


int main()
{
    solve_147();
    return 0;
}
