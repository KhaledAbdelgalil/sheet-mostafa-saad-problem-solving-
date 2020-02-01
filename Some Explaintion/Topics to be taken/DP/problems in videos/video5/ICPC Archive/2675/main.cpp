#include <bits/stdc++.h>
using namespace std;
int t,n;
int p[101];
int q[101];
int mem[101][101];
int min_price(int curr,int last,int prevsum=0)
{
    if(curr==n)
    {
      if(curr!=last)
        return int(100*1010*1010);
        return 0;
    }
    int &ret=mem[curr][last];
    if(ret!=-1) return ret;

    //close group

    ret=min_price(curr+1,curr+1,0)+(prevsum+q[curr]+10)*p[curr];

    //let group open
        ret=min(ret,min_price(curr+1,last,prevsum+q[curr]));
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

            }
        memset(mem,-1,sizeof mem);
        cout<<min_price(0,0)<<endl;



    }
    return 0;
}
