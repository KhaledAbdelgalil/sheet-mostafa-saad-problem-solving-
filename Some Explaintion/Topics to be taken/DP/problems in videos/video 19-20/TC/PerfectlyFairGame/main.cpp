#include <bits/stdc++.h>
using namespace std;
vector<string>board;
double mem[55][2*180+30];
double win(int turns,int diff)
{
    if(turns==0)
        return diff==0?0.5:((diff>0)?1.0:0.0);
    double &ret=mem[turns][diff];
    if(ret==ret)return ret;
    ret=0;
    bool isPlayer=turns%2;
    for(int i=1;i<board.size()-1;i++)
    {
        for(int j=1;j<board[0].size()-1;j++)
        {
            double p=0;
            for(int k=-1;k<2;k++)
                for(int m=-1;m<2;m++)
            {
                int score=board[i+k][j+m]-'0';
                    p+=1-win(turns-1,-(score+diff));
            }
            ret=max(ret,p/9);
        }
    }
    return ret;
}
class PerfectlyFairGame
{
public:
     double winChance(vector <string> board, int darts)
     {
        ::board=board;
        memset(mem,-1,sizeof mem);
        return 1-win(darts*2,0);
     }
};

int main()
{
    PerfectlyFairGame *p=new PerfectlyFairGame();
    int t;
    cin>>t;
    while(t--)
    {

        int n,d;
        cin>>n>>d;
        vector<string>s(n);
        for(int i=0;i<n;i++)
            cin>>s[i];
        cout<<p->winChance(s,d)<<endl;
    }
}
