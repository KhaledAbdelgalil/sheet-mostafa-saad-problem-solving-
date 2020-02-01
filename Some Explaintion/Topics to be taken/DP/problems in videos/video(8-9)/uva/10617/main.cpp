#include <bits/stdc++.h>
using namespace std;
long long mem[61][61];
string in;

long long count_ways(int i,int j)
{
    if(i==j)return 1;
    if(i+1==j)return 2+(in[i]==in[j]);

    long long &ret=mem[i][j];
    if(ret!=-1)return ret;
    ret=0;
    if(in[i]==in[j])
            ret+= 1+count_ways(i+1,j-1);
    ret+=count_ways(i+1,j);
    ret+=count_ways(i,j-1);
    ret-=count_ways(i+1,j-1);
    return ret;
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>in;
        cout<<count_ways(0,in.size()-1)<<endl;
    }
    return 0;
}
