#include <bits/stdc++.h>

using namespace std;
int n,x,y,sum=0;
int main()
{
    cin>>n>>x;
    while(n--)
    {
        cin>>y;
        sum+=y;
    }
    sum=abs(sum);
   (sum%x==0)?cout<<sum/x:cout<<sum/x+1;
    return 0;
}
