//probability with dp
//TC: PrimeSoccer(another solution(prob without dp)in video 12 is left for now)
#include <bits/stdc++.h>
using namespace std;
double a,b;
double mem[19][19][19];
bool isPrime(int r)
{
    switch(r){

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
double sol(int r,int g1,int g2)
{
    if(r>=18)
        return isPrime(g1)||isPrime(g2);
    if(mem[r][g1][g2]==mem[r][g1][g2])return mem[r][g1][g2];

    double res=a*b*sol(r+1,g1+1,g2+1);
    res+=a*(1-b)*sol(r+1,g1+1,g2);
        res+=(1-a)*(1-b)*sol(r+1,g1,g2);
        res+=(1-a)*b*sol(r+1,g1,g2+1);
        return mem[r][g1][g2]=res;
}
class  PrimeSoccer{
public:
    double getProbability (int skillOfTeamA,int skillOfTeamB)
    {
       double A=(double)(skillOfTeamA)/100.0;
       double B=(double)(skillOfTeamB)/100.0;
       a=A;
       b=B;
       memset(mem,-1,sizeof mem);
    return sol(0,0,0);
    }


};
int main()
{
    PrimeSoccer *p=new PrimeSoccer();
    cout<<p->getProbability(50,50)<<endl<<p->getProbability(100,100)<<endl<<p->getProbability(12,89);
}
