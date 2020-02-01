//gaming::three concepts are important:
/*
1-winning position::will always win
2-losing position::any turn will always lose
3-terminal:finish game base condition of recursion

take care if 2 players play same way or not
//same target
//different target
//this will affect code
//different terminal position
//include player in state or not also code consider which player plays now
*/

/*problem::TC(https://arena.topcoder.com/#/u/practiceCode/14656/18215/11530/1/310076)
2 players play with same target same way have same terminal

*/
#include <bits/stdc++.h>
using namespace std;
vector <string> board;
double mem[51][200][200];
double winProb(int turns,int score1,int score2)
{
    if(turns==0)
        return score1==score2 ? 0.5:(score1>score2? 1.0:0);
    double &ret=mem[turns][score1][score2];
    if(ret==ret) return ret;
    bool isplayer1=(turns%2==0);
    ret=0;
    for(int i=1;i<board.size()-1;i++)//not playing at edges
    {
        for(int j=1;j<board[0].size()-1;j++)
        {
            double p=0;
            for(int k=-1;k<2;k++)
                for(int m=-1;m<2;m++)
            {
                int score=board[i+k][j+m]-'0';
                if(isplayer1)
                    p+=1-winProb(turns-1,score1+score,score2);
                else
                    p+=1-winProb(turns-1,score1,score2+score);
            }
            ret=max(ret,p/9);
        }
    }
    return ret;
}
double mem2[51][2*180+20];
double winProb2(int turns,int diff)
{
    if(turns==0)
        return diff==0 ? 0.5:(diff>0? 1.0:0);
    double &ret=mem2[turns][diff];
    if(ret==ret) return ret;
    ret=0;
    for(int i=1;i<board.size()-1;i++)//not playing at edges
    {
        for(int j=1;j<board[0].size()-1;j++)
        {
            double p=0;
            for(int k=-1;k<2;k++)
                for(int m=-1;m<2;m++)
            {
                int score=board[i+k][j+m]-'0';

                    p+=1-winProb2(turns-1,-(diff+score));

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
         //memset(mem,-1,sizeof mem);
         //return 1-winProb(2*darts,0,0);
         memset(mem2,-1,sizeof mem2);
         return 1-winProb2(2*darts,0);
     }
};
int main()
{
    PerfectlyFairGame* t;
    t=new PerfectlyFairGame();
    string arr[]={"888","808","888","000","000","999","999"};
    vector<string>b(arr,arr+7);


    cout<<t->winChance(b,1);
    return 0;
}
