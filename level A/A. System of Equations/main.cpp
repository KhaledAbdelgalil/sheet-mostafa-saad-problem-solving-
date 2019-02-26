#include <iostream>

using namespace std;

int main()
{

    int n,m,out=0;
    cin>>n>>m;
    int y=max(n,m);
    for(int a=0;a<=y;a++)
        for(int b=0;b<=y;b++)
    {
        if(a*a+b==n&&a+b*b==m)
            out++;
    }
    cout<<out;
    return 0;
}
