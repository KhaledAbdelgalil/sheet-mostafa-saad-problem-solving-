//exact and atmost
//assume teacher and 20 students and teacher will give 1000 to students
//in how many ways he/she can do that such that he doesnt have any money at end
//same problem as last tutorial but with constrain that student doesn't take more than r and less than l
//assume for now constant ranges for all students r=50 l=5

//exact can be calculated from atmost
#include <bits/stdc++.h>s

using namespace std;

long long mem1[21][1001],mem2[21][1001];
const int N=20;

long long exact(int i,int rem)//code as coin change problem
{
    if(rem<0) return 0;
    if(i==N)
        return rem==0;// want to give 1000 dollar all
    long long &ret=mem1[i][rem];
    if(ret!=-1)return ret;

     ret=0;
     for(int t=5;t<=50;t++)
        ret+=exact(i+1,rem-t);//here we cannot give him/here one and recurece
    return ret;
}
long long Atmost(int i,int rem)
{
    if(rem<0) return 0;
    if(i==N)
        return 1;//doesn't matter to give 1000 dollar but cannot give more so rem<0
    long long &ret=mem2[i][rem];
    if(ret!=-1)return ret;
    ret=0;
     for(int t=5;t<=50;t++)
        ret+=Atmost(i+1,rem-t);//here we cannot give him/here one and recurece
    return ret;
}

//as you see converting exact to atmost save time space
long long Atmost2(int i,int rem)
{
    if(rem<0) return 0;
    if(i==N)
        return 1;//doesn't matter to give 1000 dollar but cannot give more so rem<0
    long long &ret=mem2[i][rem];
    if(ret!=-1)return ret;

    ret=Atmost2(i,rem-1)+Atmost2(i+1,rem-5)-Atmost2(i+1,rem-50-1);//rem-min da kbeer min-max da so8yar kda gbt  exact range mn min->max//atmost rem i.e can be rem-1 and can be exact rem
    return ret;
}


int main()
{
    memset(mem1,-1,sizeof mem1);
    memset(mem2,-1,sizeof mem2);
    cout <<exact(0,1000) << endl <<Atmost(0,1000)-Atmost(0,999);
    memset(mem2,-1,sizeof mem2);
    cout<<endl<<Atmost2(0,1000)-Atmost2(0,999);
    return 0;
}
