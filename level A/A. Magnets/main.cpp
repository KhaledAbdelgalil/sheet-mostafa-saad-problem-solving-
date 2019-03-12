#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int x,y,c=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cin>>x;
        }
        else
        {
            y=x;
            cin>>x;
           if(y!=x)
                c++;
        }
    }
    cout<<++c;
    return 0;
}
