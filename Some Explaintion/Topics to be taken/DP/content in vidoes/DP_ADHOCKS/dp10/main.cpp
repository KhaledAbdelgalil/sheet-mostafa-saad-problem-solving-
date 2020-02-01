//this tutorial talking about issue:time issue(time order)(video 26/27) could be escaped for now
#include <bits/stdc++.h>

using namespace std;

long long mem1[21][1001],mem2[21][1001];
long long mem3[21][1001];
const int N=20;

long long exact(int i,int rem)//code as coin change problem
{
    if(rem<0) return 0;
    if(i==N)
        return rem==0;// want to give 1000 dollar all
    long long &ret=mem1[i][rem];
    if(ret!=-1)return ret;

     ret=0;
     for(int t=5;t<=50;t++)
        ret+=exact(i+1,rem-t);//here we cannot give him/here one and recurece
    return ret;
}
//covert exact into table method
long long exact2(long long n,long long money)
{
 //clear mem3:global cleard
 mem3[0][0]=1;
 for(int i=1;i<=n;i++)//pass on students
    for(int j=5;j<=money;j++)//pass on money
        for(int k=5;k<=min(50,j);k++)
            mem3[i][j]+=mem3[i-1][j-k];
 return mem3[n][money];
}
//as you see converting exact to atmost save time space
long long Atmost(int i,int rem)
{
    if(rem<0) return 0;
    if(i==N)
        return 1;//doesn't matter to give 1000 dollar but cannot give more so rem<0
    long long &ret=mem2[i][rem];
    if(ret!=-1)return ret;

    ret=Atmost(i,rem-1)+Atmost(i+1,rem-5)-Atmost(i+1,rem-50-1);//rem-min da kbeer min-max da so8yar kda gbt  exact range mn min->max//atmost rem i.e can be rem-1 and can be exact rem
    return ret;
}


int main()
{
    memset(mem1,-1,sizeof mem1);
    memset(mem2,-1,sizeof mem2);
    cout <<exact(0,500) << endl <<Atmost(0,500)-Atmost(0,499);
    cout<<endl<<exact2(20,500);
    return 0;
}
