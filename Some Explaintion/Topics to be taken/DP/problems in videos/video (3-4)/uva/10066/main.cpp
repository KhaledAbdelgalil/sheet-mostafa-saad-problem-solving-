#include <bits/stdc++.h>
using namespace std;
int n,m;
int mem[101][101];
vector<int>v1,v2;
int LCS(int i,int j)
{
    if(i==n||j==m)
        return 0;
    int &ret=mem[i][j];
    if(ret!=-1) return ret;
    ret=0;
    if(v1[i]==v2[j])
        ret=1+LCS(i+1,j+1);
    return ret=max(ret,max(LCS(i+1,j),LCS(i,j+1)));
}
int main()
{
    int x;
    int t=0;
    while(cin>>n>>m)
    {
        v1.clear();
        v2.clear();
        if(n==0&&m==0)
            break;
        memset(mem,-1,sizeof mem);
        for(int i=0;i<n;i++)
        {
            cin>>x;
            v1.push_back(x);
        }

        for(int i=0;i<m;i++)
        {
            cin>>x;
            v2.push_back(x);
        }
        n=v1.size();
        m=v2.size();
        cout<<"Twin Towers #"<<++t<<endl;
        cout<<"Number of Tiles : ";
        cout<<LCS(0,0)<<endl<<endl;
    }
    return 0;
}
