#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,l,maxx=0;
    double x,y,z,ans;
    scanf("%d%d",&n,&l);
     int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=1; i<n; i++)
    {
        if(a[i]-a[i-1]>maxx)
            maxx=a[i]-a[i-1];
    }
    x=maxx/2.0;
    y=a[0]-0.0;
    z=(double)l-a[n-1];
    ans=max(y,z);
    ans=max(ans,x);
    printf("%.10f\n",ans);
    return 0;
}
