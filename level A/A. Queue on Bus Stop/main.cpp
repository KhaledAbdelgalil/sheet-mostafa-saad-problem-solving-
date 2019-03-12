#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>p;
int main()
{
    int x;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        p.push_back(x);
    }
    int i=1;
    int o=p[0];
    int buses=0;
    while(i!=n)
    {
        if(o+p[i]<=m)
        {
            o+=p[i];

        }
        else {buses++;o=p[i];}
    i++;
    }
    cout<<buses+1;
}
