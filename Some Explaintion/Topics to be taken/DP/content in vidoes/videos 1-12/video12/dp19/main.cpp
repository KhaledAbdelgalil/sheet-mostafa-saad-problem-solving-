//probability with dp
//TC: PrimeSoccer(another solution(prob without dp)in video 12 is left for now)
#include <bits/stdc++.h>
using namespace std;
double a,b;
double table[19][19][19];//state is which interval what a scores till now what b scores till now

bool prime(int n)
{
    switch(n)
    {
    case 0:
    case 1:
    case 4:
    case 6:
    case 8:
    case 9:
    case 10:
    case 12:
    case 14:
    case 15:
    case 16:
    case 18:
        return false;
    default: return true;
    }
}
double solution(int r,int g1,int g2)
{
    if(r>=18) return (prime(g1)||prime(g2))?1:0;
    if(fabs(table[r][g1][g2]+1)>1e-9) return table[r][g1][g2];
    double res=a*b*(solution(r+1,g1+1,g2+1));
    res+=a*(1-b)*(solution(r+1,g1+1,g2));
    res+=(1-a)*(1-b)*(solution(r+1,g1,g2));
    res+=(1-a)*(b)*(solution(r+1,g1,g2+1));
    return table[r][g1][g2]=res;
}
class  PrimeSoccer
{
public:
    double getProbability (int skillOfTeamA,int skillOfTeamB)
    {
        a=(double)(skillOfTeamA)/100.0;
        b=(double)skillOfTeamB/100.0;
        memset(table,-1,sizeof table);
        return solution(0,0,0);
    }
};

int main()
{
    PrimeSoccer* s;
    s=new PrimeSoccer();
    int c,d;
    cin>>c>>d;
    cout<<s->getProbability(c,d);
    return 0;
}
