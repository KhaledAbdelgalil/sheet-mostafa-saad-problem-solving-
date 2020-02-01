//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int n,A[1001];
int mem[1001][1001];

int LIS1(int i,int prev,int taken=0)
{
    if(i==n)return 0;


    int c1=LIS1(i+1,prev,taken);
    int c2=0;

    if(prev==-1||A[prev]<=A[i])
        c2=1+LIS1(i+1,i,taken+1);

    return max(c1,c2);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(mem,-1,sizeof mem);
        for(int i=0;i<n;i++)
            cin>>A[i];
        cout<<LIS1(0,-1)<<endl;
    }
    return 0;
}
