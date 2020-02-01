//given array 2d ::get subrectangle have some feature

//some problems in dp in 2d are based on your solution in 1d linear by compression

//problem::https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0
//1-brute force solution 2-dp solution

//problem::https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
//rec::max=max(me,or me+before-me)

//problem::https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0

#include <bits/stdc++.h>
using namespace std;
int rows,cols;
int A[50][50];
int LSBINARY(int i,int j)
{
    if(i<0||j<0||i>=rows||j>=cols) return 0;
    if(A[i][j]==0) return 0;
    return 1+min(LSBINARY(i+1,j+1),min(LSBINARY(i+1,j),LSBINARY(i,j+1)));
}
void Square_sol()
{
    int t;
    cin>>t;
    while(t--)
    {
        int mx=0;
        cin>>rows>>cols;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                cin>>A[i][j];
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                    mx=max(mx,LSBINARY(i,j));
        cout<<mx<<endl;
    }
}



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

void sum_max_array2d_dp()
{
    int t,n,m,value,best=0,maxx;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector< vector<int> >dp1(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>value;
                dp1[i][j]=dp1[i][j-1]+value;//accumluative array
            }
        }
        maxx=dp1[1][1];
        for(int window=1;window<=m;window++)//O(n2)bruteforce +O(n) dynamic programming
            for(int j=window;j<=m;j++)
        {
            for(int i=1,best=0;i<=n;i++)
                {
                    int elment=dp1[i][j]-dp1[i][j-window];
                    if(best<0)
                        best=elment;
                    else
                        best+=elment;
                    if(best>maxx) maxx=best;
                }
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
    //sum_max_array2d_bruteforce();
    //contiguous_sub_array_sum();
    //sum_max_array2d_dp();
    //Square_sol();
    Square_sol_using_rect_concept();
    return 0;
}
