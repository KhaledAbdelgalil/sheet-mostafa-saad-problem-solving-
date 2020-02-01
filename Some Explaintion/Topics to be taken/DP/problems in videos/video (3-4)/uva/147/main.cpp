#include <bits/stdc++.h>
using namespace std;
int coins[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long table_mem[11][300000+5];


void init_table()
{
    for(int i=0;i<11;i++)
        table_mem[i][0]=1;
    for(int coin=coins[0];coin<=30005;coin+=5)
        for(int j=0;j<11;j++)
        {
        if(j) table_mem[j][coin]=table_mem[j-1][coin];
        if(coin-coins[j]>=0)
             table_mem[j][coin]+=table_mem[j][coin-coins[j]];

        }
}

long long mem_roll[2][30005];
void init_mem_roll()
{
    int p=0;
    mem_roll[p][0]=mem_roll[!p][0]=1;
    for(int j=0;j<11;j++)
    {
        p=!p;
        for(int coin=coins[0];coin<30005;coin++)
        {
            //mem_roll[p][coin]=0;//avoid last iteration calculation
            if(j)
                mem_roll[p][coin]=mem_roll[!p][coin];
            if(coin-coins[j]>=0)
                  mem_roll[p][coin]+=mem_roll[p][coin-coins[j]];
        }
    }
}


int main()
{

    double num;
    init_table();
    init_mem_roll();
    while (scanf("%lf", &num), num > 0.0000001)
    {
        int n=(int)(num*100+0.5);
       cout << right << setw(6) << setprecision(2) << fixed << num << right << setw(17) << mem_roll[1][n]<< endl;
    }

    return 0;
}
