#include <bits/stdc++.h>

using namespace std;
int arr[1009];
int arr2[1009];
int flag_changed_or_not=1;//1 not changed
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x!=y) flag_changed_or_not=0;
        arr[i]=x;
        arr2[i]=x;
    }
    if(flag_changed_or_not==0) {cout<<"rated";return 0;}
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr2[i]) {cout<<"unrated"; return 0;}
    }
    cout<<"maybe";
    return 0;
}
