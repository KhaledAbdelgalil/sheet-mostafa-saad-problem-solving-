//hackerrank:largestIncreasingsubsequent
//knapsack problem:geeksforgeeks
//longest common string:geeksforgeeks
//if you are in front of problem take subset from input think of dp or intial recursion take and not take
//try this using tabular form
#include <bits/stdc++.h>
using namespace std;
const int m = 6;
int numList[m] = {5, 2, 7, 3, 4, 6}; // solution is finally set of 0s and 1s..pick or leave.
// 0 1 0 1 1 1


// called with LIS(0, m)
int LIS(int i, int prev)
{
if(i == m)
return 0;

int choice1 = LIS(i+1, prev); // LEAVE
int choice2 = 0;

if(prev == m || numList[prev] <= numList[i])
choice2 = LIS(i+1, i) + 1;

return max(choice1, choice2);
}
int LIS2(int arr[],int n)
{
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
            if(arr[j]<arr[i]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    }
    return *max_element(lis,lis+n);
}

int w[1000];
int v[1000];
int n;
int states[1001][1001];

int knapSack_dp(int W)//not understood yet
{
   int i, wj;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (wj = 0; wj <= W; wj++)
       {
           if (i==0 || w==0)
               K[i][wj] = 0;
           else if (w[i-1] <= wj)
                 K[i][wj] = max(v[i-1] + K[i-1][wj-w[i-1]],  K[i-1][wj]);
           else
                 K[i][wj] = K[i-1][wj];
       }
   }

   return K[n][W];
}
int knapsnack_rec_memorize(int i,int W)
{
    if(i==n) return 0;
    int &ret=states[i][W];
    if(ret!=-1) return ret;
    ret=0;
    if(w[i]>W)
       return ret=knapsnack_rec_memorize(i+1,W);
    else
        return ret=max(knapsnack_rec_memorize(i+1,W-w[i])+v[i],knapsnack_rec_memorize(i+1,W));
}
int knapsnack_rec(int i,int W)
{
    if(i==n) return 0;
    if(w[i]>W)
       return knapsnack_rec(i+1,W);
    else
        return max(knapsnack_rec(i+1,W-w[i])+v[i],knapsnack_rec(i+1,W));
}
void knapsnack_geeksforgeeks()
{
    int test,W;

    cin>>test;
    while(test--)
    {
        cin>>n>>W;
        for(int i=0;i<n+1;i++)
            for(int j=0;j<W+1;j++)
             states[i][j]=-1;
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int j=0;j<n;j++)
            cin>>w[j];
        //cout<<knapsnack_rec(0,W)<<endl;
        //cout<<knapsnack_rec_memorize(0,W)<<endl;
        cout<<knapSack_dp(W)<<endl;
    }
}

int N,M;
string s1,s2;
int LCS_rec(int i,int j)
{
    if(i==N||j==M)
        return 0;
    if(s1[i]==s2[j])
        return 1+LCS_rec(i+1,j+1);
    return max(LCS_rec(i+1,j),LCS_rec(i,j+1));
}

void LCS_geeksforgeeks()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        cin>>N>>M>>s1>>s2;
        cout<<LCS_rec(0,0);
    }
}

 int main()
 {
 	//cout<<LIS(0, m);
    //cout<<endl<<LIS2(numList,m);
    //knapsnack_geeksforgeeks();
    LCS_geeksforgeeks();
 	return 0;
 }





























