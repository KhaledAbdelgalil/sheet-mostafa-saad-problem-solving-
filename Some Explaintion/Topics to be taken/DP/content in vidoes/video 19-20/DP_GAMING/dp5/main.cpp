//problem::https://arena.topcoder.com/#/u/practiceCode/1628/5655/6127/1/1628
//2 players play with same startegy
#include <bits/stdc++.h>
using namespace std;
vector<int>turns;

int mem[100001];
int win(int stones)
{
    if(stones<=0)
        return 0;//I try to play I can't
    int &ret=mem[stones];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=0;i<turns.size();i++)
    {
        if(turns[i]<=stones)
        ret=max(ret,1-win(stones-turns[i]));
    }
    return ret;
}
int win1[100001];
class LastStone {
  public:
  int numWins(vector <int> turns, int m, int n) {
    win1[0] = 0;
    for (int i = 1; i <= 100000; i++)
    for (int j = 0; j < turns.size(); j++) {
      if (i - turns[j] >= 0) {
        if (!win1[i-turns[j]]) win1[i] = 1;
      }
    }
    int ret = 0;
    for (int i = m; i <= n; i++) ret += win1[i];
    return ret;
  }
};

class LastStone2{

public:
     int numWins(vector <int> turns, int m, int n)
     {
         ::turns=turns;
         int ans=0;
            memset(mem,-1,sizeof mem);//memset only one time if you have definite stones so can win or not don't put it in for loop or you will stuck
         for(int i=m;i<=n;i++)
            {
                ans+=win(i);
            }
            return ans;
     }
};

int main()
{
    LastStone* f;
    int t;
    cin>>t;
    vector<int>tt(t);
    for(int i=0;i<t;i++)
        cin>>tt[i];
    int n,m;
    cin>>m>>n;
    cout<<f->numWins(tt,m,n);
    return 0;
}
