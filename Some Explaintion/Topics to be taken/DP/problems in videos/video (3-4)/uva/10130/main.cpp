#include <bits/stdc++.h>
using namespace std;

int n,p[1001],w[1001],g,t,x;
int mem[1001][31];
int knap(int index,int weight)
{
    if(index==n)return 0;
    int &ret=mem[index][weight];
    if(ret!=-1) return ret;
    ret=0;
    ret=max(ret,knap(index+1,weight));
    if(weight>=w[index])
        ret=max(ret,p[index]+knap(index+1,weight-w[index]));
    return ret;
}
void knap_one_time()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=30;j++)
        {
            if(i==0||j==0)
                mem[i][j]=0;
            else if(j>=w[i-1])
                mem[i][j]=max(mem[i-1][j],mem[i-1][j-w[i-1]]+p[i-1]);
            else
                mem[i][j]=mem[i-1][j];
        }
    }
}
int main()
{
    int res=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>p[i]>>w[i];
        cin>>g;
        knap_one_time();
        for(int i=0;i<g;i++)
        {
            //memset(mem,-1,sizeof mem);
            cin>>x;
            res+=mem[n][x];
            //res+=knap(0,x);
        }
        cout<<res<<endl;
        res=0;
    }
    return 0;
}
