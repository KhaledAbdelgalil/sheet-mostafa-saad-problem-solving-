#include <bits/stdc++.h>
using namespace std;
int H,W;
char world[1111][1111];
void dfs(int i,int j,char c)
{


   if(i>H||j>W||i<0||j<0||world[i][j]!=c)return;


    world[i][j]='.';
    dfs(i+1,j,c);
    dfs(i,j+1,c);
    dfs(i-1,j,c);
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

        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
            {cin>>world[i][j];}
    vector<states_lang>anss;
        struct states_lang temp;
       for(char f='a';f<='z';f++){
            int ans=0;
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
            {
                char in=world[i][j];
                if(in==f)
                {
                    dfs(i,j,in);
                    ans++;
                }
            }
        temp.co=ans;
        temp.l=f;
        if(ans>0)anss.push_back(temp);
       }

        sort(anss.begin(),anss.end(),cmp);
            cout<<"World #"<<tt<<endl;

        for(int i=0;i<anss.size();i++)
        {
           cout<<anss[i].l<<": "<<anss[i].co<<endl;
        }
    }
    return 0;
}
