#include <bits/stdc++.h>

using namespace std;
vector< vector<int> >graph;
int vis[105];
void dfs(int i,vector<int>&order)
{
    if(vis[i])return;
    vis[i]=1;
    for(int j=0;j<graph[i].size();j++)
        if(vis[graph[i][j]]==0)dfs(j,order);
    order.push_back(i);
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        graph.resize(n+1);

        vector<int>ts;
        memset(vis,0,sizeof vis);
        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            graph[y-1].push_back(x-1);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,ts);
        }
        cout<<ts[n-1]+1;
        for(int i=n-2;i>=0;i--)
            cout<<" "<<ts[i]+1;
        cout<<endl;
    }
    return 0;
}
