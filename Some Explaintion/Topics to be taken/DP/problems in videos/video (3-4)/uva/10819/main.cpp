#include <bits/stdc++.h>
using namespace std;
int P,N;
int p[101],f[101];
int mem[101][15001];

int max_favor(int i,int moneyused)
{
    if(i==N)
    {
        if(moneyused<=P||(moneyused>2000&&moneyused<=P+200))
            return 0;
        return -1e9;
    }
    int &ret=mem[i][moneyused];
    if(ret!=-1)return ret;
    ret=max_favor(i+1,moneyused);
    if(moneyused+p[i]<=P+200)
    ret=max(ret,max_favor(i+1,moneyused+p[i])+f[i]);
    return ret;
}
int main()
{

    while(cin>>P>>N)
    {
        if(cin.eof())break;
        for(int i=0;i<N;i++)
        cin>>p[i]>>f[i];

        memset(mem,-1,sizeof mem);
        cout<<max_favor(0,0)<<endl;
    }
    return 0;
}
