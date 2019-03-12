#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,x,out1=0,out2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        out1|=x;
    }
     for(int i=0;i<n;i++)
    {
        cin>>x;
        out2|=x;
    }

    cout<<out1+out2;
    return 0;
}
