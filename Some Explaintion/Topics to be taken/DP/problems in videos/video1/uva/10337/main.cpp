#include <bits/stdc++.h>
using namespace std;
int speeds_of_wind[10][1005];
int mem[10][1005];
int n,alt,dis,x;
int min_fuel(int alt,int dis)
{
    if(alt<0||alt>9||dis>x)//invalid state
        return 1e9;
    if(dis==x)
    {
        if(alt==0)
            return 0;
        return 1e9;
    }
    int &ret=mem[alt][dis];
    if(ret!=-1)
        return ret;

    return ret=min(60-speeds_of_wind[alt][dis]+min_fuel(alt+1,dis+1),min(30-speeds_of_wind[alt][dis]+min_fuel(alt,dis+1),
                                                                         20-speeds_of_wind[alt][dis]+min_fuel(alt-1,dis+1)));
}
int main()
{
    freopen("out2.txt","w",stdout);
    cin>>n;
    while(n--)
    {
        memset(mem,-1,sizeof mem);
        cin>>x;
        x/=100;
        for(int i=9;i>=0;i--)
        {
            for(int j=0;j<x;j++)
            {
                cin>>speeds_of_wind[i][j];
            }
        }
        cout<<min_fuel(0,0)<<endl<<endl;
    }
    return 0;
}
