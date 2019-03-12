#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,x;
    cin>>n>>x;
    long long arr[n];
    long long out=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    for(int i=0;i<n;i++)
    {
        if(x<=1) {out+=arr[i];}
        else
        {
            out+=arr[i]*x;
            x--;
        }

    }
cout<<out;
}
