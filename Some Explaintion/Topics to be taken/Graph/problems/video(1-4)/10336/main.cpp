#include <bits/stdc++.h>
using namespace std;
map<char,int>mp;
int H,W;
vector<  vector<char> >world;
vector<  vector<bool> >seen;
void dfs(int i,int j,char c)
{
    seen[i][j]=1;
    if(i+1<H&&!seen[i+1][j]&&world[i+1][j]==c)
        dfs(i+1,j,c);

    if(j+1<W&&!seen[i][j+1]&&world[i][j+1]==c)
        dfs(i,j+1,c);

    if(i-1>=0&&!seen[i-1][j]&&world[i-1][j]==c)
        dfs(i+1,j,c);

    if(j-1>=0&&!seen[i][j-1]&&world[i][j-1]==c)
        dfs(i,j-1,c);
}
struct states_lang{
char l;
int co;

};
bool cmp(const states_lang& a,const states_lang& b)
{
    if(a.co>b.co)return true;
    if(a.co==b.co)
        if(a.l<b.l)return true;
    return false;
}
int main()
{
    int t;
    cin>>t;

    for(int tt=1;tt<=t;tt++)
    {
        cin>>H>>W;
        world.clear();
        seen.clear();
        mp.clear();
        world.resize(H,vector<char>(W));
        seen.resize(H,vector<bool>(W));
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
            {cin>>world[i][j];seen[i][j]=0;}

        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
            {
                char in=world[i][j];
                if(!seen[i][j])
                {
                    dfs(i,j,in);
                    mp[in]++;
                }
            }
        vector<states_lang>ans;
        struct states_lang temp;
        for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            temp.co=it->second;
            temp.l=it->first;
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end(),cmp);
            cout<<"World #"<<tt<<endl;

        for(int i=0;i<ans.size();i++)
        {
           cout<<ans[i].l<<": "<<ans[i].co<<endl;
        }
        cout<<endl;
    }
    return 0;
}
