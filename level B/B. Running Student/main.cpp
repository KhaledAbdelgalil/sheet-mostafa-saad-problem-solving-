#include <bits/stdc++.h>

using namespace std;

int main()
{
int n;
double vs,vb;
cin>>n>>vb>>vs;
double arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
double x,y;
cin>>x>>y;
double time=1000000000000000 ,distance=10000000000000;
int index=-1;
for(int i=1;i<n;i++)
{

    double t=sqrt((arr[i]-x)*(arr[i]-x)+y*y)/vs;
    double d=sqrt((arr[i]-x)*(arr[i]-x)+y*y);
    t+=arr[i]/vb;
    if(t<=time &&d<distance){time=t;index=i+1;d=distance;}
}
cout<<index;
    return 0;
}
