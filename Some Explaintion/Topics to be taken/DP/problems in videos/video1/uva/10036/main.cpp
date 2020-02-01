#include <bits/stdc++.h>

using namespace std;
int mem[10001][101];
int numbers[10001];
int n,k;
bool divs(int i,int mod=0)
{
    if(i==n)
        return mod==0;
    int &ret=mem[i][mod];
    if(ret!=-1) return ret;
    return ret=divs(i+1,(mod+numbers[i])%k)||divs(i+1,(mod-numbers[i])%k);

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(mem,-1,sizeof mem);
        for(int i=0;i<n;i++)
            cin>>numbers[i];
        bool ans=divs(0);
        if(ans)
            cout<<"Divisible\n";
        else
            cout<<"Not divisible\n";
    }
    return 0;
}
