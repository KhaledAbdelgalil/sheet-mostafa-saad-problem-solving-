#include <bits/stdc++.h>
using namespace std;
int r[21],b[21],g[21];
int n;
int mem[21][4];

int min_cost(int i,int lastColor)
{
    if(i==n)return 0;
    int &ret=mem[i][lastColor];
    if(ret!=-1)return ret;
    ret=1e9;
    if(lastColor!=0)
        ret=min(ret,r[i]+min_cost(i+1,0));
    if(lastColor!=1)
        ret=min(ret,b[i]+min_cost(i+1,1));
    if(lastColor!=2)
        ret=min(ret,g[i]+min_cost(i+1,2));

    return ret;
}
class RGBStreet{

public:
     int estimateCost(vector <string> houses)
     {
         memset(mem,-1,sizeof mem);
         n=houses.size();
         for(int i=0;i<n;i++)
         {
             istringstream iss(houses[i]);
             iss>>r[i]>>b[i]>>g[i];
         }
         return min_cost(0,3);
     }

};
int main()
{
    cin>>n;
    memset(mem,-1,sizeof mem);

    vector<string>houses(n);
    for(int i=0;i<n;i++)
        cin>>r[i]>>b[i]>>g[i];

    cout<<min_cost(0,3);
    return 0;
}
