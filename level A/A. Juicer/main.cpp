#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=0,b=0,d=0,x=0,sumtrush=0,count1=0;
    cin>>n>>b>>d;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x<=b)
        {
            sumtrush+=x;
        }
        if(sumtrush>d)
        {
            count1++;
            sumtrush=0;
        }
    }
    cout<<count1;
    return 0;
}
