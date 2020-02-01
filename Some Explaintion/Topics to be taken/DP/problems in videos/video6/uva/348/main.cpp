#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

LL cols[11],rows[11];
LL mem[11][11];
string dp[11][11];

LL min_cost(int l,int r)
{
    if(mem[l][r]!=-1)return mem[l][r];
    dp[l][r]="";
    if(l==r)
    {
        stringstream ss;
        ss<<"A"<<l+1;
        ss>>dp[l][r];
        return 0;
    }

    LL ret=(1LL<<62);
    int mid;
    for(int i=l;i<r;i++)
    {
        LL temp=rows[l]*cols[i]*cols[r]+min_cost(l,i)+min_cost(i+1,r);
        if(temp<ret)
        {
            ret=temp;
            mid=i;
        }
    }
    dp[l][r]="("+dp[l][mid]+" x "+dp[mid+1][r]+")";
    return mem[l][r]=ret;
}
int main()
{
    int n;
    int k=1;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
            cin>>rows[i]>>cols[i];
        memset(mem,-1,sizeof mem);
        LL temp=min_cost(0,n-1);
        //cout<<temp;
        cout<<"Case "<<k++<<": "<<dp[0][n-1]<<endl;//((A1 x (A2 x A3)) x ((A4 x A5) x A6))
    }
    return 0;
}
