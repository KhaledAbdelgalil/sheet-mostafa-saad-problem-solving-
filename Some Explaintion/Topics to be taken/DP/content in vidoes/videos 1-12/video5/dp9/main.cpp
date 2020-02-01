//consecutive range styles
//pearls problem:https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=676
#include <bits/stdc++.h>
using namespace std;
int n;
int req[101];
int price[101];
int acc_req[101];
int mem1[101][101];
int sol1(int curridx,int lastidx)
{

    if(curridx==n)
        return 0;
    int &ret=mem1[curridx][lastidx];
    if(ret!=-1) return ret;
    int sum=10;
    //assume one group(enough interval)
    for(int i=lastidx;i<=curridx;i++)
        sum+=req[i];
    ret=sol1(curridx+1,curridx+1)+price[curridx]*sum;//open anew group
    if(curridx!=n-1)//as long bigger interval is possible
        ret=min(ret,sol1(curridx+1,lastidx));

    return ret;

}
//accumulative
int sol2(int curridx,int lastidx)
{

    if(curridx==n)
        return 0;
    int &ret=mem1[curridx][lastidx];
    if(ret!=-1) return ret;
    int sum=10;
    //assume one group(enough interval)
    sum+=acc_req[curridx]-acc_req[lastidx-1];
    ret=sol1(curridx+1,curridx+1)+price[curridx]*sum;//open anew group
    if(curridx!=n-1)//as long bigger interval is possible
        ret=min(ret,sol1(curridx+1,lastidx));

    return ret;

}
int sol3(int curr,int last,int prevsum=0)//prevsum is inferenced variable no need to memorize it
{
    if(curr==n)
    {
        if(curr!=last)//@end all groups finished
            return (int)(100*1010*1010);//let it make a mistake then check on it
        return 0;
    }

    int& ret=mem1[curr][last];
    if(ret!=-1)return ret;
    ret=sol3(curr+1,curr+1,0)+(prevsum+req[curr]+10)*price[curr];
    ret=min(ret,sol3(curr+1,last,prevsum+req[curr]));
    return ret;
}
const int oo=(int)1e10;
int mem2[101];
//solution:order of memory is better (minimize on fly and sum on fly)
int sol4(int start)
{
    if(start==n) return 0;
    int &ret=mem2[start];
    if(ret!=-1) return ret;
    int sum=0;
    ret=oo;
    for(int i=start;i<n;i++)//try ABC:take A then recurece from B then take AB and recurce from C
    {
        sum+=req[i];
        ret=min(ret,sol4(i+1)+(sum+10)*price[i]);
    }
    return ret;
}
int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>req[i]>>price[i];
            if(i==0)acc_req[i]=req[i];
            else acc_req[i]=req[i]+acc_req[i-1];
        }
       // memset(mem1,-1,sizeof mem1);
        memset(mem2,-1,sizeof mem2);

        //cout<<sol1(0,0)<<endl;
       // cout<<sol2(0,0)<<endl;
        cout<<sol4(0)<<endl;

    }
    return 0;
}
