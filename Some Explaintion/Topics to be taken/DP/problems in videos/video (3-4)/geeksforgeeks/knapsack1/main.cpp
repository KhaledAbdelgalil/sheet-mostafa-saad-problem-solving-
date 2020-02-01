//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>
using namespace std;
int N,W;
int v[1001],w[1001],t;
int mem[1001][1001];
int max_knap(int index,int weight)
{
    if(index==N)return 0;
    int &ret=mem[index][weight];
    if(ret!=-1) return ret;

    ret=0;
    ret=max(ret,max_knap(index+1,weight));
    if(weight>=w[index])
        ret=max(ret,max_knap(index+1,weight-w[index])+v[index]);

    return ret;
}
int main()
{
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>N>>W;
        for(int i=0;i<N;i++)
            cin>>v[i];
        for(int i=0;i<N;i++)
            cin>>w[i];
        cout<<max_knap(0,W)<<endl;
    }
    return 0;
}
