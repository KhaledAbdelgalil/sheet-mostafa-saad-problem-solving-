//important Link:://https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
#include <bits/stdc++.h>
using namespace std;
int n;
#define INF 100000000
vector< list < pair<int,pair<int,int> > > > adj_list;//node t d
void dijsktra(int source,int target)
{
   //distance - current node-parent node
   priority_queue< pair <int , pair <int , int> > ,
    vector< pair< int,pair<int ,int> > >,
    greater< pair < int,pair < int,int > > > > nodes;//
    vector<int>t(n,INF);
    vector<int>d(n,INF);
    nodes.push({0,{source,0}});
    while(!nodes.empty())
    {
        pair <int , pair <int , int> > q=nodes.top();
        nodes.pop();
        int time =q.first;
        int current_node=q.second.first;
        int dist=q.second.second;
        if(t[current_node]!=INF) continue;
        t[current_node]=time;
        d[current_node]=dist;
        for(list< pair< int,pair<int,int> > >::iterator it=adj_list[current_node].begin();it!=adj_list[current_node].end();it++)
        {
            int next_node=(*it).first;
            pair<int,int> wt=(*it).second;
            if(t[next_node]!=INF)continue;
            nodes.push({time+wt.first,{next_node,dist+wt.second}});
        }
    }
    cout<<"distance from: "<<source<<" till "<<target<<" is: "<<d[target]<<endl;

}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>n>>m;
        adj_list.clear();
        adj_list.resize(n);
        for(int i=0;i<m;i++)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            adj_list[a-1].push_back({b-1,{c,d}});
            adj_list[b-1].push_back({a-1,{c,d}});
        }
        int q;
        cin>>q;
        int src,des;
        for(int i=0;i<q;i++)
        {
            cin>>src>>des;
            dijsktra(src,des);
        }
    }

    return 0;
}
