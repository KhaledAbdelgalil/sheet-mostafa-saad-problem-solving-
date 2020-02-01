#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,c,lecs_ans;
ll ans_d;
int arr[1001];
int mem[1001];
int min_cost(int start,int lecs,ll d)
{
    if(start==n){
            if(lecs<=lecs_ans)
            {
                lecs_ans=lecs;
                ans_d=min(ans_d,d);
            }
            return lecs;
    }
    int &ret=mem[start];
    if(ret!=-1)return ret;
    ret=1e9;
    ll sum=0;
    for(int i=start;i<n;i++)
    {
        sum+=arr[i];
        if(sum<=l)
        {
                ll D=d;
                if(l-sum==0);
                else if(l-sum<=10)D-=c;
                else D+=(l-sum-10)*(l-sum-10);
                ret=min(ret,min_cost(i+1,lecs+1,D));
        }
        else break;
    }
    return ret;
}
int main()
{
    int f=0;
    int t=0;
    freopen("out.txt","w",stdout);
    while(cin>>n&&n)
    {
        if(n==0)break;
        cin>>l>>c;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        memset(mem,-1,sizeof mem);
        if(f)cout<<endl;
        else f=1;
        lecs_ans=1e9;
        ans_d=(1ll<<61);
        int leccc=     min_cost(0,0,0);

//        min_D(0,0,0);
         cout << "Case " << ++t << ":" << endl;
        cout << "Minimum number of lectures: " << leccc << endl;
        cout << "Total dissatisfaction index: " << ans_d << endl;


    }
    return 0;
}
