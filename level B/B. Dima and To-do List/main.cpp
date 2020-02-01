#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long minn=10000000000;
    long long sum=0;
    int index;
    for(int i=0;i<k;i++)//you need to brute force only on first k elements
    {
        sum=0;
        for(int j=i;j<n;j+=k)
            sum+=arr[j];
        if(sum<minn)
        {
            minn=sum;
            index=i+1;
        }
    }
     cout<<index;
    return 0;
}
