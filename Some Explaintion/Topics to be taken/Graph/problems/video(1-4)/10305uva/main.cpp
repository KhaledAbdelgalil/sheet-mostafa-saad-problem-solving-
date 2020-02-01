#include <bits/stdc++.h>

using namespace std;
vector< vector<int> >graph;
int vis[105];
void dfs(int node,stack<int>&order)
{
    if(vis[node])return;
    vis[node]=1;
    for(int j=0;j<graph[node].size();j++)
        {
            int next=graph[node][j];
            if(vis[next]==0)dfs(next,order);

        }

    order.push(node);
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        graph.clear();
        graph.resize(n+1);

        stack<int>ts;
        memset(vis,0,sizeof vis);
        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            graph[x-1].push_back(y-1);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,ts);
        }
        int c=0;
        while(!ts.empty())
        {
            cout<<ts.top()+1;
            c++;
            if(c<n)cout<<" ";
            ts.pop();
        }
        cout<<endl;
    }
    return 0;
}
