#include <bits/stdc++.h>
using namespace std;
string in;
int mem[1001][1001];
vector<int>v;
int max_sub(int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)return 1;
    if(mem[i][j]!=-1)return mem[i][j];
    int &ret=mem[i][j];
    ret=0;
    if(in[i]==in[j])
        ret=2+max_sub(i+1,j-1);
    else
        ret=max_sub(i+1,j-1);
    ret=max(ret,max_sub(i+1,j));
    ret=max(ret,max_sub(i,j-1));
    return ret;
}
void build_dp(int i,int j)
{

    if(i>j)
        {
            for(int k=0;k<v.size();k++)
                cout<<in[v[k]];
            for(int k=v.size()-1;k>=0;k--)
                cout<<in[v[k]];
            cout<<endl;
            return;

        }
    if(i==j)
       {
            for(int k=0;k<v.size();k++)
                cout<<in[v[k]];
            cout<<in[i];
            for(int k=v.size()-1;k>=0;k--)
                cout<<in[v[k]];
            cout<<endl;
            return;
       }

    int c1=0,c2,c3;
    if(in[i]==in[j])
        c1=2+max_sub(i+1,j-1);
    else
        c1=max_sub(i+1,j-1);
    c2=(max_sub(i+1,j));
    c3=(max_sub(i,j-1));
    int sol=max_sub(i,j);

    if(sol==c1&&in[i]==in[j])
    {
        if(in[i]==in[j])
            v.push_back(i);
        build_dp(i+1,j-1);
        return;
    }

     else if(sol==c3)
    {
        //v.push_back(i);
        build_dp(i,j-1);
        return;
    }

    else if(sol==c2)
    {
        // v.push_back(j);
        build_dp(i+1,j);
        return;
    }
    else
    {
     build_dp(i+1,j-1);
    }
}
int main()
{
    while(cin>>in)
    {
        if(cin.eof())break;
        memset(mem,-1,sizeof mem);
        v.clear();
        //cout<<max_sub(0,in.size()-1)<<endl;
        max_sub(0,in.size()-1);
        build_dp(0,in.size()-1);
    }
    return 0;
}
