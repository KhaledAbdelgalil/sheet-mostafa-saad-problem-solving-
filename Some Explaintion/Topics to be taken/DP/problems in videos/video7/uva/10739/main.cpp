#include <bits/stdc++.h>
using namespace std;

string s;
int mem[1001][1001];
int min_cost(int i,int j)
{
    if(i>=j)return 0;
    if(mem[i][j]!=-1)return mem[i][j];
    int &ret=mem[i][j];
    ret=min_cost(i+1,j-1)+(s[i]!=s[j]);
    ret=min(ret,min_cost(i+1,j)+1);
    ret=min(ret,min_cost(i,j-1)+1);
    return ret;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>s;
        memset(mem,-1,sizeof mem);
        cout<<"Case "<<i+1<<": "<<min_cost(0,s.size()-1)<<endl;
    }
    return 0;
}
