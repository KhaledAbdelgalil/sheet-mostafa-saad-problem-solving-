//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>
using namespace std;
int N,W;
int v[1001],w[1001],t;
int max_knap()
{
    int table_knap[N+1][W+1];

    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
                table_knap[i][j]=0;
            else if(j>=w[i-1])
                table_knap[i][j]=max(v[i-1]+table_knap[i-1][j-w[i-1]],table_knap[i-1][j]);
            else
                 table_knap[i][j]=table_knap[i-1][j];
        }
    }
    return table_knap[N][W];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>N>>W;
        for(int i=0;i<N;i++)
            cin>>v[i];
        for(int i=0;i<N;i++)
            cin>>w[i];
        cout<<max_knap()<<endl;
    }
    return 0;
}
