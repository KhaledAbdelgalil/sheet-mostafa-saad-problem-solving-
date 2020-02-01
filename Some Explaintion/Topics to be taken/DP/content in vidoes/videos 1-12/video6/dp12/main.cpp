//nested range style
//uva problems:10003(cutting stick)
#include <bits/stdc++.h>

using namespace std;
int arr[1001];
int mem[1001][1001];
//cut indecs
int arr2[1001];

int cut2(int s,int e,int is,int ie)
{
    if(is>ie) return 0;
     if(mem[is][ie]!=-1) return mem[is][ie];

     int best=(int)1e9;
     for(int i=is;i<=ie;i++)
     {
         int c=arr2[i];
            best=min(best,cut2(s,c,is,i-1)+cut2(c+1,e,i+1,ie)+e-s+1);
     }
     if(best==(int)1e9) best=0;
     return mem[is][ie]=best;

}
int cut(int s,int e)
{
    if(s==e) return 0;
     if(mem[s][e]!=-1) return mem[s][e];

     int best=(int)1e9;
     for(int i=s;i<e;i++)
     {
         if(arr[i])
            best=min(best,cut(s,i)+cut(i+1,e)+e-s+1);
     }
     if(best==(int)1e9) best=0;
     return mem[s][e]=best;

}
int main()
{
    int l,n,f;
    while(cin>>l && l)
    {
        memset(arr,0,sizeof arr);
        memset(mem,-1,sizeof mem);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>f;
            arr[f-1]=1;
            arr2[i]=f;
        }
       // cout<<"The minimum cutting is "<<cut(0,l-1)<<".\n";
       cout<<"The minimum cutting is "<<cut2(1,l,1,n)<<".\n";

    }
    return 0;
}
