#include <bits/stdc++.h>
using namespace std;

int main()
{

    deque<int>d1;
    deque<int>d2;
    int n;
    cin>>n;
    int n1,n2,x;
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        cin>>x;
        d1.push_back(x);
    }

    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cin>>x;
        d2.push_back(x);
    }
    int steps=0;
    int depth=0;
    while(!d1.empty()&&!d2.empty()&&depth!=1000)
    {
        steps++;
        depth++;

        int v1=d1.front();
        int v2=d2.front();
        d1.pop_front();
        d2.pop_front();
        if(v1>v2)
        {
            d1.push_back(v2);
            d1.push_back(v1);
        }
        else
        {
        d2.push_back(v1);
         d2.push_back(v2);
        }
    }
    if(d1.empty())
    {
        cout<<steps<<" "<<2;
    }
    else if(d2.empty())
    {
        cout<<steps<<" "<<1;
    }
    else
        cout<<-1;
    return 0;
}
