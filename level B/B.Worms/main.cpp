#include <bits/stdc++.h>
using namespace std;
int n,q,m,x;
int main()
{
    cin>>n;
    int worms[n+9];
    worms[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        worms[i+1]=worms[i]+x;
    }
   cin>>m;
    int arr[m+3];
    for(int i=0;i<m;i++)
    {
        cin>>x;
        arr[i]=lower_bound(worms,worms+n+1,x)-worms;
    }
for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
    return 0;
}
