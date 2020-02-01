//https://practice.geeksforgeeks.org/problems/longest-common-substring/0
//there are consecutive and non consective solution
#include <bits/stdc++.h>
using namespace std;
int N,M;
string s1,s2;

int LCS(int i,int j,int c)
{
    if(i==0||j==0)
        return 0;
    if(s1[i-1]==s2[j-1])
        c=LCS(i-1,j-1,c+1);
    c=max(c,max(LCS(i-1,j,0),LCS(i,j-1,0)));
    return c;
}
int LCS2()
{
    int table[N+1][M+1];
    int result=0;
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i==0||j==0)
                table[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            {
                table[i][j]=1+table[i-1][j-1];
                result=max(result,table[i][j]);
            }
            else
                table[i][j]=0;
        }
    }
    return result;
}
int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        cin>>N>>M>>s1>>s2;
        cout<<LCS2()<<endl;
    }
return 0;
}
