#include <bits/stdc++.h>
using namespace std;
int main()
{
    char op;
    long long n,f,x;
    cin>>n>>f;
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>op>>x;
        if(op=='+') f+=x;
        else if(x<=f) f-=x;
        else c++;
    }
    cout<<f<<" "<<c;
    return 0;
}
