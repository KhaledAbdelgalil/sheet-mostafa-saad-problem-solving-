#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int mem[1005][1005];
int min_cost(int s,int e)
{
    if(s==e) return 0;
    int &ret=mem[s][e];
    if(ret!=-1)
        return ret;
    ret=1e9;
    for(int i=s;i<e;i++)
    {
        if(arr[i])
            ret=min(ret,min_cost(i+1,e)+min_cost(s,i)+e-s+1);
    }
    if(ret==1e9)ret=0;//if no cuts more
    return ret;
}
int main()
{
    int l;
    int n,x;
    while(cin>>l&&l)
    {
        cin>>n;
        memset(arr,0,sizeof arr);
        memset(mem,-1,sizeof mem);
        for(int i=0;i<n;i++)
        {
            cin>>x;
            arr[x-1]=1;
        }
       cout<<"The minimum cutting is "<<min_cost(0,l-1)<<".\n";
    }
    return 0;
}
