//1st problem::domino tilling can be solved using counting princple and recursion and using rows of bits try to add or not
//but we will solve it using geometry inspiration
//uva:(10918 - Tri Tiling)::https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1859
//geeksforgeeks::https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor/0

//2nd problem ::solve joseph problem::https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0

#include <bits/stdc++.h>
using namespace std;
int f(int n);
int g(int n);
int g(int n)
{
    if(n==1) return 1;
    if(n==0) return 0;

    return f(n-1)+g(n-2);
}
int f(int n)
{
    if(n==1) return 0;
    if(n==0) return 1;
    return f(n-2)+g(n-1)*2;
}
void solve_10918()
{
    int n;
    while(cin>>n)
    {
        if(n==-1) break;

        cout<<f(n)<<endl;
    }
}
unsigned long long dp[100];
void solve_2W()
{
    int t,n;
    cin>>t;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<100;i++)
        dp[i]=dp[i-1]+dp[i-2];
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
}
int mem[205][205];
int killJo(int n,int k)
{
    if(n==1)return 1;
    if(mem[n][k]!=-1)return mem[n][k];
    return mem[n][k]=(killJo(n-1,k)+k-1)%n+1;
}
int killJo2(int n,int k)
{

    if(mem[n][k]!=-1)return mem[n][k];

    mem[1][k]=1;
    for(int i=2;i<=n;i++)
        mem[i][k]=(mem[i-1]+k-1)%i+1;

    return mem[n][k];
}
//the idea in mapping only
void solve_jose()
{

    int t,n,k;
    cin>>t;
    memset(mem,-1,sizeof mem);
    while(t--)
    {
        cin>>n>>k;
        cout<<killJo2(n,k)<<endl;
    }
}
int main()
{
    //solve_10918();
    //solve_2W();
    solve_jose();
    return 0;
}
