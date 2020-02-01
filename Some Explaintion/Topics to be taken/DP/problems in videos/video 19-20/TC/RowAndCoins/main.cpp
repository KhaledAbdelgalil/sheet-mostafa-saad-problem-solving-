//don't think of all gaming problems as dp

//as this problem::https://arena.topcoder.com/#/u/practiceCode/14682/22364/11566/1/310389
#include <bits/stdc++.h>
using namespace std;
string cells;
string winner()
{
    if(cells[0]=='A'||cells[cells.size()-1]=='A')return "Alice";
    return "Bob";
}

class RowAndCoins{
public:
  string getWinner(string _cells)
   {
       cells = _cells;
        return winner();
   }
};

int main()
{
    RowAndCoins *p=new RowAndCoins();
    cout<<p->getWinner("BBBB");
}
