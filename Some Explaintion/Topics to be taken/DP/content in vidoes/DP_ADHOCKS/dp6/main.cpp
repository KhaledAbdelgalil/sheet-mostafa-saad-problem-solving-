//inequality constraints manipulation(left for now)
/*In a given special case
-- Convert Less than to less than or equal
-- Dropping Inequality constraints*/
//problem::https://arena.topcoder.com/#/u/practiceCode/13634/8829/9904/1/298587

//how many way to form 6 positive different numbers their mean <=M
/*i.e
    0<x1<x2<x3<x4<x5<x6
    x1+x2+x3+x4+x5+x6<=6M
    y1=x1-1 y2=x2-2
    0<=y1<=y2<=y3<y4<=y5<=y6
    y1+y2+y3+y4+y5+y6<=6M-21

    z1=y6-y5
    z2=y5-y4
    z3=y4-y3
    z4=y3-y2
    z5=y2-y1
    z6=y1
    z1+2z2+3z3+4z4+5z5+6z6<=6M-1
    0<=z1,z2,z3,z4,z5,z6

    like knapsack as at beginning it's state 6*1000000*1000000  6 * from where to start x2 * M

*/


#include <bits/stdc++.h>
using namespace std;
const int MAX= 6*1000000+1;
long long mem[7][MAX];
const int mmod = 1000000007;
long long nways(int i,int m)
{
    if(i==0)
        return 1;
    if(m<0)
        return 0;
    long long &ret=mem[i][m];
    if(ret!=-1)return ret;
    long long a=nways(i-1,m);
     long long b=nways(i,m-i);

    return ret=(long long)((a+b))%mmod;
}
class  CustomDice{

public:
     int countDice(int M)
     {
         memset(mem,-1,sizeof mem);
         return nways(6,6*M);
     }
};
int main()
{
    CustomDice* t;
    int f;
    cin>>f;
    cout<<t->countDice(f);
    return 0;
}
