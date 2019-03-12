#include <bits/stdc++.h>
using namespace std;

const int N=1073741824;
int m;
int arr[1000009];
void d(int m)
{
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j+=i)
        arr[j]++;
}
int main()
{
int a,b,c;
long long sum=0;
cin>>a>>b>>c;
d(a*b*c);
for(int i=1;i<=a;i++)
for(int j=1;j<=b;j++)
for(int k=1;k<=c;k++)
{
    m=i*j*k;

  sum+=arr[m];
}

sum=sum%N;
cout<<sum;

return 0;
}
