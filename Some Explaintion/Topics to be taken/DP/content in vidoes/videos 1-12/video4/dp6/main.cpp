//uva problems :147
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int coins[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long mem_dollars[11][30000+5];
long long rec_dollars_nways(int indx,int rem)
{
    if(rem==0)
        return 1;
    if(rem<coins[indx]||indx>=11) return 0;

    long long ret;
    if(mem_dollars[indx][rem]!=-1) return mem_dollars[indx][rem];

    ret=rec_dollars_nways(indx+1,rem);
    while(rem-coins[indx]>=0)
    {
        ret+=rec_dollars_nways(indx+1,rem-coins[indx]);
        rem-=coins[indx];
    }

    return mem_dollars[indx][rem]=ret;
}
long long rec_dollars_nways2(int indx,int rem)
{
    //cout<<rem<<endl;
    if(rem==0)
        return 1;
    if(rem<coins[indx]||indx>=11) return 0;
    long long &ret=mem_dollars[indx][rem];
    if(ret!=-1) return ret;

    return ret=rec_dollars_nways2(indx+1,rem)+rec_dollars_nways2(indx,rem-coins[indx]);

}

long long table_mem[11][30005];
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
   /* for(int j=0;j<11;j++,cout<<endl)
     for(int coin=coins[0];coin<=50;coin+=5)

        {
            cout<<table_mem[j][coin]<<"  ";
        }*/
}

//rolling techinque:use first loop the index use j and j-1
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
long long mem_1d[30005];//the most important one very important
void init_mem1d()
{
    mem_1d[0]=1;
    for(int j=0;j<11;j++)
    {

        for(int coin=coins[j];coin<30005;coin++)
        {
            mem_1d[coin]+=mem_1d[coin-coins[j]];
        }
    }
}
void solve_147()
{
     double num;
     //init_table();
     //init_mem_roll();
     init_mem1d();
    while (scanf("%lf", &num), num > 0.0000001)
    {
        int n=static_cast<int>(num*100+0.5);//note that cast
        //cout<<n;
        memset(mem_dollars,-1,sizeof mem_dollars);
        //cout << right << setw(6) << setprecision(2) << fixed << num << right << setw(17) << rec_dollars_nways2(0,n) << endl;
       //cout << right << setw(6) << setprecision(2) << fixed << num << right << setw(17) << table_mem[10][n]<< endl;
       //cout << right << setw(6) << setprecision(2) << fixed << num << right << setw(17) << mem_roll[1][n]<< endl;
       cout << right << setw(6) << setprecision(2) << fixed << num << right << setw(17) << mem_1d[n]<< endl;
    }
}


int main()
{
    solve_147();
    return 0;
}
