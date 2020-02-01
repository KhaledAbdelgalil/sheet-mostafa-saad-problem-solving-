#include <bits/stdc++.h>
using namespace std;
int n,t,k;
int arr[10001];

int min_cost(int i,int j,int cnt)
{
    if(cnt>k)   return cnt;
    if(i>j)
        return cnt;
    int &ret=mem[i][j][cnt];
    if(ret!=-1)return ret;
    if(arr[i]==arr[j])
        return ret= min_cost(i+1,j-1,cnt);
    else
        return ret=min(min_cost(i+1,j,cnt+1),min_cost(i,j-1,cnt+1));
}
int main()
{

    cin>>t;
    int u=1;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ans=min_cost(0,n-1,0);
        if(ans>k)
            cout<<"Case "<<u++<<": Too difficult"<<endl;
        else if(ans==0)
            cout<<"Case "<<u++<<": Too easy"<<endl;
        else
        cout<<"Case "<<u++<<": "<<ans<<endl;

    }
    return 0;
}
