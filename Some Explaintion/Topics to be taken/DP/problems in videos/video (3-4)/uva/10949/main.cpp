#include <bits/stdc++.h>
using namespace std;
char grid[22][22];
string s1,s2;
int N,M;
int mem[20002][20002];

int LCS()
{

  for(int i=1;i<=N;i++)
  {
      for(int j=1;j<=M;j++)
      {
          if(s1[i-1]==s2[j-1])
            mem[i][j]=mem[i-1][j-1]+1;
          else
            mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
      }
  }
  return mem[N][M];
}

int main()
{

    int t,r,c;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>r>>c;
        for(int rr=0;rr<r;rr++)
            for(int cc=0;cc<c;cc++)
                cin>>grid[rr][cc];
        int nn,xo,yo;
        cin>>nn>>xo>>yo;
        char in;
        xo--;
        yo--;
        s1="";
        s1+=grid[xo][yo];
        for(int i=0;i<nn;i++)
        {
            cin>>in;
            switch(in)
            {
                case 'S':xo++;break;
                case 'N':xo--;break;
                case 'E':yo++;break;
                case 'W':yo--;break;
            }
            s1+=grid[xo][yo];
        }


        //s2

        cin>>nn>>xo>>yo;
        xo--;
        yo--;
        s2="";
        s2+=grid[xo][yo];
        for(int i=0;i<nn;i++)
        {
            cin>>in;
            switch(in)
            {
                case 'S':xo++;break;
                case 'N':xo--;break;
                case 'E':yo++;break;
                case 'W':yo--;break;
            }
            s2+=grid[xo][yo];
        }
        N=s1.size();
        M=s2.size();

        int deleted=LCS();
       // cout<<s1<<" "<<s2<<endl<<deleted<<endl;

        cout<<"Case "<<tt<<": "<<s1.size()-deleted<<" "<<s2.size()-deleted<<endl;
    }
    return 0;
}
