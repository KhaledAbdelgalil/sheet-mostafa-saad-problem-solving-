#include <bits/stdc++.h>
using namespace std;
int m,arr[101];
int mem[101][50005];
int min_cost(int i,int container)
{
    if(i==m)return 0;
    if(container<=0)return 0;
    int &ret=mem[i][container];
    if(ret!=-1)return ret;

    ret=min_cost(i+1,container);
    if(container>=arr[i])
        ret=max(ret,arr[i]+min_cost(i+1,container-arr[i]));

    return ret;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>m;
        int sum=0;
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        cout<<sum-2*min_cost(0,sum/2)<<endl;
    }
    return 0;
}
