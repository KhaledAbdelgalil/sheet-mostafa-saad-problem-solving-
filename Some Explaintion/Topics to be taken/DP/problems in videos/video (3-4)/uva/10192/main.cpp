#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int N,M;
int LCS()
{
int mem[N+1][M+1];

  for(int i=0;i<=N;i++)
  {
      for(int j=0;j<=M;j++)
      {
          if(i==0||j==0)
            mem[i][j]=0;
          else if(s1[i-1]==s2[j-1])
            mem[i][j]=mem[i-1][j-1]+1;
          else
            mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
      }
  }
  return mem[N][M];
}
int main()
{
    //freopen("o.txt","w",stdout);
    int t=0;
    while(getline(cin,s1))
    {
        if(s1[0]=='#')break;
        getline(cin,s2);
        N=s1.size();
        M=s2.size();
        printf("Case #%d: you can visit at most %d cities.\n",++t,LCS());
    }
    return 0;
}
