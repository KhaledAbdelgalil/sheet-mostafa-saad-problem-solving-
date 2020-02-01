#include <bits/stdc++.h>
using namespace std;
vector<string>v1,v2;
int n,m,ans;
int mem[101][101];
int flag=0;
int LCS(int i,int j)
{
    if(i==n||j==m)
        return 0;
    int &ret=mem[i][j];
    if(ret!=-1)return ret;
    ret=0;
    if(v1[i]==v2[j])
    ret=1+LCS(i+1,j+1);
    ret=max(ret,max(LCS(i+1,j),LCS(i,j+1)));
    return ret;
}
void build_rec(int i,int j)
{
    if(i==n||j==m)
        return;
    int corr_ans=0,c1,c2,c3;
    if(v1[i]==v2[j])
    c1=1+LCS(i+1,j+1);
    c2=LCS(i+1,j);
    c3=LCS(i,j+1);
    corr_ans=LCS(i,j);
    if(corr_ans==c1)
    {
       if(!flag) cout<<v1[i];
        else cout<<" "<<v1[i];
       flag=1;
        build_rec(i+1,j+1);
    }
    else if(corr_ans==c2)
    {
        build_rec(i+1,j);
    }
    else
    {
        build_rec(i,j+1);
    }
}
int main()
{
    string s1, s2;
    while(true)
    {
        v1.clear();
        v2.clear();
        cin>>s1;
        if(cin.eof())break;
        v1.push_back(s1);
        while(cin>>s1)
            if(s1=="#") break;
            else v1.push_back(s1);

        while(cin>>s2)
            if(s2=="#") break;
            else v2.push_back(s2);
        n=v1.size();
        m=v2.size();
        memset(mem,-1,sizeof mem);
        int ans=LCS(0,0);
        flag=0;
        build_rec(0,0);
        printf("\n");
    }
    return 0;
}
