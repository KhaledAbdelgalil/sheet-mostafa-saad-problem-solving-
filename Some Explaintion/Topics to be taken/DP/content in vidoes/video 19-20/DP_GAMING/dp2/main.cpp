//win\lose problem
//wining positin:have steps one or more make him\her always win inspite of other player
//losing position:have steps all lose


//don't think of all gaming problems as dp

//as this problem::https://arena.topcoder.com/#/u/practiceCode/14682/22364/11566/1/310389
#include <bits/stdc++.h>
using namespace std;


//1st solution:greedy style
/*
class RowAndCoins{
public:
  string getWinner(string cells)
   {
       if(cells[0]=='A'||cells[cells.size()-1]=='A')
        return "Alice";
       return "Bob";
   }
};*/
string cells;
int n;
int mem[1<<16][2];//config player 0 Alice 1 Bob
bool can(int config,int player)
{
    if(mem[config][player]!=-1)
        return mem[config][player];
   //add config to state array
    int state[16];
    for(int i=0;i<n;i++)
        if(config&(1<<i)) state[i]=1;
        else state[i]=0;

    //check for end of game
    int empty=0,pos=-1;
    for(int i=0;i<n;i++)
    {
        if(!state[i])
        {
            ++empty;
            pos=i;
        }
    }
    if(empty==1)
    {
        if(player==0)
            return (mem[config][player]=cells[pos]=='A');
        else
             return (mem[config][player]=cells[pos]=='B');
    }


    //try every possible move for player
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(j-i+1==empty) continue;//you will put coins in all places so escape this
            bool ok=true;//assume to take consecutive group
            for(int k=i;k<=j;k++)
                if(state[k]){
                        ok=false;break;
                }
            if(!ok) continue;//escape;

            int new_config=config;

            for(int k=i;k<=j;k++)
                new_config|=(1<<k);

            if(!can(new_config,1^player))//wining postion and losing position
                return (mem[config][player]=1);
        }
    }
    return (mem[config][player]=0);
}
class RowAndCoins{
public:
  string getWinner(string _cells)
   {
       cells = _cells;
      n = cells.size();
      memset(mem, -1, sizeof(mem));
      if (can(0, 0)) return "Alice";
      return "Bob";
   }
};
int main()
{
    cout << "DP" << endl;
    return 0;
}
