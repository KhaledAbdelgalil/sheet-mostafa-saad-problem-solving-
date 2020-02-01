//expectation:you have event with probability to happen
//In the case of uncertainty, expectation is what is considered the most likely to happen
//problem codeforces:C. Bath Queue(left for now) video 13
#include <bits/stdc++.h>
using namespace std;
long long C[51][51]={0};
int roombaths[51];
//for buliding combination
int n,m;
double mem[51][51][51];
void build_nCK()
{
    for(int i=0;i<51;i++)
    {
        for(int j=0;j<51;j++)
        {
                if(j==0)
                {
                    C[i][j]=1;
                }
                else if(i==0)
                {
                    C[i][j]=0;
                }
                else
                {
                  C[i][j]= C[i-1][j-1]+C[i-1][j];
                }
        }

    }
}
double rec(int r,int s,int maxSoFar)
{
    if(r==m)
        return s==0?maxSoFar:0;
    double &ret=mem[r][s][maxSoFar];
    if(ret==ret)
        return ret;
    double p=1.0;
    ret=0;
    for(int ss=0;ss<=s;ss++)
    {
        int largestQueue=(ss+roombaths[r]-1)/roombaths[r];//for ceiling add in numerator value-1
        ret+=C[s][ss]*p*rec(r+1,s-ss,max(maxSoFar,largestQueue));
        p/=(double)m;
    }
    return ret;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>roombaths[i];
    build_nCK();
    memset(mem,-1,sizeof mem);
    cout<<setprecision(6)<<rec(0,n,0)<<endl;
    return 0;
}
