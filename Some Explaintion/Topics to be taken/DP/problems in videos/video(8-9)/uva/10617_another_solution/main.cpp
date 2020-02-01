#include <bits/stdc++.h>
using namespace std;
string in;


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        cin>>in;
        int m=in.size();
        long long mem[m+1][m+1];
        for(int i=0;i<m;i++)
            mem[i][i]=2;

        for(int len=2;len<=m;len++)
        {
            for(int i=0;i<=m-len;i++)
            {
                int j=i+len-1;
                if(j==i+1)
                {
                    if(in[i]==in[j])
                        mem[i][j]=4;
                    else
                        mem[i][j]=3;
                }
                else if(in[i]==in[j])
                    mem[i][j]=mem[i+1][j]+mem[i][j-1];
                else
                    mem[i][j]=mem[i+1][j]+mem[i][j-1]-mem[i+1][j-1];
            }
        }
        cout<<mem[0][m-1]-1<<endl;
    }
    return 0;
}
/*#include<stdio.h>
#include<string.h>

int main()
{
 long long table[65][65];
 char str[65];
 int test,i,j,k,l,len,m;
 scanf("%d",&test);
 while(test--)
 {
  scanf("%s",str);
  len=strlen(str);
  len--;
  table[0][0]=1;
  for(i=1;i<=len;i++)
  {
   table[i][i]=1;
   table[i][i-1]=0;
  }
  k=1;
  while(k<=len)
  {
   for(i=0,j=k;j<=len;i++,j++)
   {
    table[i][j]=table[i][j-1]+1;
    for(m=i;m<j;m++)
    {
     if(str[m]==str[j])
      table[i][j]=table[i][j]+table[m+1][j-1]+1;
    }
   }
   k++;
  }
  printf("%lld\n",table[0][len]);
 }
 return 0;
}

*/
