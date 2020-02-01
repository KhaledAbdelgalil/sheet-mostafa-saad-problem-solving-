#include <bits/stdc++.h>
using namespace std;
int t,n;
int p[101];
int q[101];
int mem[101][101];
int acc_sum[101];
int min_price(int curr,int last)
{
    if(curr==n)
        return 0;
    int &ret=mem[curr][last];
    if(ret!=-1) return ret;

    //close group
    int sum=10;
    if(last==0)
        sum+=acc_sum[curr];
    else
        sum+=acc_sum[curr]-acc_sum[last-1];
    ret=min_price(curr+1,curr+1)+(sum)*p[curr];

    //let group open
    if(curr!=n-1)
        ret=min(ret,min_price(curr+1,last));
    return ret;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            {
                cin>>q[i]>>p[i];
                if(i)
                    acc_sum[i]=acc_sum[i-1]+q[i];
                else
                    acc_sum[i]=q[i];
            }
        memset(mem,-1,sizeof mem);
        cout<<min_price(0,0)<<endl;



    }
    return 0;
}
