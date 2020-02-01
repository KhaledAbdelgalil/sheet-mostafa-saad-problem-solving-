#include <bits/stdc++.h>
using namespace std;
unsigned long long count1=1;
void dfs(vector<list<int> > & adjacency_list, vector<bool> & visited,	int source)
{
	visited[source] = true;
	// pre
	for (list<int>::iterator itr = adjacency_list[source].begin();
		itr != adjacency_list[source].end(); itr++)
	{
		if (!visited[*itr])
		{
		    count1=count1*2;
			dfs(adjacency_list, visited,*itr);
		}
	}
	// post
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector< list<int> > adj_list(n);
    vector<bool> visited(n,0);
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj_list[u-1].push_back(v-1);
        adj_list[v-1].push_back(u-1);
    }
    for(int i=0;i<n;i++)
        if(!visited[i])
    {
        visited[i]=1;
        dfs(adj_list,visited,i);
    }
    cout<<count1;
    return 0;
}
