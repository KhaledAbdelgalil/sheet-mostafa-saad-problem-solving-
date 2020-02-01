#include <bits/stdc++.h>
using namespace std;
 int t,n,p,q,x;
int main()
{

      cin>>t;
    int a[100001],b[100001];
    for(int tt=0;tt<t;tt++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof (b));
        cin>>n>>p>>q;
        for(int i=1;i<=p+1;i++)
        {
            cin>>x;
            a[x]=i;
        }

        for(int i=1;i<=q+1;i++)
        {
            cin>>x;
            if(a[x])
                b[i]=a[x];
            else
                b[i]=-1;
        }
        b[0]=9999999;
        vector<int>l;
        vector<int>dp(q+2);
        for(int i=1;i<=q+1;i++)
        {
            int num=b[i];
            int pos=upper_bound(l.begin(),l.end(),num)-l.begin();
            if(pos==l.size())
            {
                l.push_back(num);
            }
            else
                l[pos]=num;
            dp[i]=pos+1;
        }
        int ans=dp[1];
        for(int i=2;i<=q+1;i++)
            ans=max(ans,dp[i]);
        cout<<"Case "<<tt+1<<": "<<ans<<endl;

    }


    return 0;
}
