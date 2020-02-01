//exact and atmost
//assume teacher and 10 students and teacher will give 1000 to students
//in how many ways he/she can do that such that he doesnt have any money at end

//when see anyone of exact or atmost think of both
#include <bits/stdc++.h>s

using namespace std;

long long mem1[11][1001],mem2[11][1001];
const int N=10;
long long exact(int i,int rem)//code as coin change problem
{
    if(rem<0) return 0;
    if(i==N)
        return rem==0;// want to give 1000 dollar all
    long long &ret=mem1[i][rem];
    if(ret!=-1)return ret;
     ret=exact(i,rem-1)+exact(i+1,rem);//give one dollar then recurece again on it to give him again or give student after

    return ret;
}
long long Atmost(int i,int rem)
{
    if(rem<0) return 0;
    if(i==N)
        return 1;//doesn't matter to give 1000 dollar but cannot give more so rem<0
    long long &ret=mem2[i][rem];
    if(ret!=-1)return ret;
     ret=Atmost(i,rem-1)+Atmost(i+1,rem);//can be interperted by 2 ways see dp9 min=0 max=rem
    return ret;
}

int main()
{
    memset(mem1,-1,sizeof mem1);
    memset(mem2,-1,sizeof mem2);
    cout <<exact(0,1000) << endl <<Atmost(0,1000)-Atmost(0,999);
    return 0;
}
