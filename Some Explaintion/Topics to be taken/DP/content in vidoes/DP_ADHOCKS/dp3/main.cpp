//given array 2d ::get subrectangle have some feature

//some problems in dp in 2d are based on your solution in 1d linear

//problem::https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0
//1-brute force solution 2-dp solution

//problem::https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
//rec::max=max(me,or me+before-me)

#include <bits/stdc++.h>
using namespace std;

void sum_max_array2d_bruteforce()
{
    int t,n,m,value,sum=0,maxx;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector< vector<int> >dp1(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            sum=0;
            for(int j=1;j<=m;j++)
            {
                cin>>value;
                sum+=value;
                dp1[i][j]=sum+dp1[i-1][j];
            }
        }

        maxx=dp1[1][1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=i;k<=n;k++)
                    for(int l=j;l<=m;l++)
                {
                    sum=dp1[k][l]+dp1[i-1][j-1]-dp1[k][j-1]-dp1[i-1][l];
                    if(sum>maxx)maxx=sum;
                }
                cout<<maxx<<endl;
    }
}

void contiguous_sub_array_sum()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long value,best=-(1e8);
        long long maxx=-(1e8);
        while(n--)
        {
            cin>>value;
            if(best<0)//so start from next
                best=value;
            else
                best+=value;
            if(best>maxx)
                maxx=best;
        }
        cout<<maxx<<endl;
    }
}

int main()
{
    sum_max_array2d_bruteforce();
    return 0;
}
