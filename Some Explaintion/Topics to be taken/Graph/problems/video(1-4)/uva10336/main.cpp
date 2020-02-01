#include <bits/stdc++.h>
using namespace std;
map<char,int>mp;
int H,W;
vector<  vector<char> >world;
void dfs(int i,int j,char c)
{


   if(i>H||j>W||i<0||j<0||world[i][j]!=c)return;



    world[i][j]='.';
    dfs(i+1,j,c);
    dfs(i,j+1,c);
    dfs(i+1,j,c);
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
        mp.clear();
        world.resize(H,vector<char>(W));
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
            {cin>>world[i][j];}

        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
            {
                char in=world[i][j];
                if(world[i][j]!='.')
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
