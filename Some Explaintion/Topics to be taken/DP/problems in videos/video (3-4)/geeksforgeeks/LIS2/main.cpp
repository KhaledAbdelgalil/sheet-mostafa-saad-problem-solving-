//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int n,A[1001];
int lis[1001];

int LIS2()
{
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
            if(A[j]<A[i]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    }

    return *max_element(lis,lis+n);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(lis,-1,sizeof lis);
        for(int i=0;i<n;i++)
            cin>>A[i];
        cout<<LIS2()<<endl;
    }
    return 0;
}
