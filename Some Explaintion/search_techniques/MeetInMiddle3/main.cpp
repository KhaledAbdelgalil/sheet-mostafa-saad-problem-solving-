//spoj(SUBSUMS - Subset Sums)
#include <bits/stdc++.h>
using namespace std;
//this solution::time limit exceeded
void sol()
{
    long long n,a,b;
    long long arr[40];
    unsigned long long ans=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(unsigned long long i=0;i<(1<<n);i++)
    {
        long long sum=0;
        for(unsigned long long j=0;j<n;j++)
        {
            if(i&(1<<j))
                sum+=arr[j];
        }
        if(sum>=a&&sum<=b)
            ans++;
    }
    cout<<ans;
}

//meet in middle
long long sum1[1<<17+2];
long long sum2[1<<17+2];

void sol2()
{
    long long n,a,b;
    long long arr[40];

    unsigned long long ans=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long n1=n/2;
    long long n2=n/2;
    //odd
    if(n&1==1)n2++;
    //finding sum subset for first half
    for(int i=0;i<(1<<n1);i++)
    {
        for(int j=0;j<n1;j++)
            if(i&(1<<j))
                sum1[i]+=arr[j];
    }

     //finding sum subset for second half
    for(int i=0;i<(1<<n2);i++)
    {
        for(int j=0;j<n2;j++)
            if(i&(1<<j))
                sum2[i]+=arr[n/2+j];
    }
    //binary_search
    sort(sum1,sum1+(1<<n1));//take care
    for(int i=0;i<(1<<n2);i++)
    {
        long long* low=lower_bound(sum1,sum1+(1<<n1),a-sum2[i]);//take care
        long long* high=upper_bound(sum1,sum1+(1<<n1),b-sum2[i]);//take care
        ans+=high-low;
    }
    cout<<ans;
}
int main()
{
    //sol();
     sol2();
    return 0;
}
