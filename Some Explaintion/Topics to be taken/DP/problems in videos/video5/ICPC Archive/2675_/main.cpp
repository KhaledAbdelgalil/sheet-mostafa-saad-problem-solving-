#include <bits/stdc++.h>
using namespace std;
int t,n;
int p[101];
int q[101];
int mem[101];
int min_price(int start)
{
    if(start==n)
    {
        return 0;
    }
    int &ret=mem[start];
    if(ret!=-1) return ret;

    int sum=0;
    ret=INT_MAX;
   for(int i=start;i<n;i++)
   {
       sum+=q[i];
       ret=min(ret,min_price(i+1)+(sum+10)*p[i]);
   }
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
        cout<<min_price(0)<<endl;



    }
    return 0;
}
