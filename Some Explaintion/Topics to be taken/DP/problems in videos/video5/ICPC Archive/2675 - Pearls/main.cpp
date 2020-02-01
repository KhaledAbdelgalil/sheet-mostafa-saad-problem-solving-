#include <bits/stdc++.h>
using namespace std;
int t,n;
int p[101];
int q[101];
int mem[101][101];
int min_price(int curr,int last)
{
    if(curr==n)
        return 0;
    int &ret=mem[curr][last];
    if(ret!=-1) return ret;

    //close group
    int sum=0;
    for(int i=last;i<=curr;i++)
        sum+=q[i];
    ret=min_price(curr+1,curr+1)+(sum+10)*p[curr];

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
            cin>>q[i]>>p[i];
        memset(mem,-1,sizeof mem);
        cout<<min_price(0,0)<<endl;



    }
    return 0;
}
