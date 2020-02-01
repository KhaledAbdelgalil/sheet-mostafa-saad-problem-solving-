#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map< pair <int,pair <int,int> > ,int>mp;
int nways(int h,int r ,int g)
{
    if(h==0)return 1;
    if(h>r&&h>g)return 0;


    if(mp.count({h,{r,g}})) return mp[{h,{r,g}}];
         int &ret=mp[{h,{r,g}}];
    if(r>=h)
        ret+=nways(h-1,r-h,g);
    if(g>=h)
        ret+=nways(h-1,r,g-h);
    return ret;
    /*int dp[r+1];
    dp[0]=1;
    for(int i=1;i<=h;i++)
    {
        for(int j=)
    }*/
}
int main()
{
    int r,g;
    int h_req;
    cin>>r>>g;
    for(h_req=1;h_req*(h_req+1)/2<=r+g;h_req++);
    h_req--;
    cout<<nways(h_req,r,g);

    return 0;
}
