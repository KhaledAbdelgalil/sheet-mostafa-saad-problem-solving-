#include <bits/stdc++.h>
using namespace std;
map<string,vector<string> > graph;


map<string,string> route;
map <string,int> visited;

int bfs(string a, string b){
  queue<string>s;
  s.push(a);
  route[a]=a;
  while(!s.empty())
  {
      string node=s.front();
      s.pop();
      if(node==b)
        return visited[node];
      for(int i=0;i<graph[node].size();i++)
      {
          string n=graph[node][i];
          if(visited[n]==-1)
          {
                visited[n]=1;
                route[n]=node;
                s.push(n);
          }
      }
  }
  return -1;
}

void printpath(string a, string b){
  if(a==b){return;}
  printpath(route[a],b);
  cout<<route[a]<<" "<<a<<endl;;
}

int main()
{
    int n;bool primera = false;
  while(scanf("%d",&n) != EOF)
    {
    graph.clear();
    string s1,s2,start,end;
    for (int i = 0; i < n; ++i)
     {
        cin>>s1>>s2;
        graph[s1].push_back(s2);
        graph[s2].push_back(s1);
        visited[s1]=-1;
        visited[s2]=-1;
     }
     cin>>start>>end;
     if(primera) printf ("\n");
    primera = true;
     if(bfs(start,end)!=-1)
      printpath(end,start);
     else
      printf("No route\n");
  }
    return 0;
}
