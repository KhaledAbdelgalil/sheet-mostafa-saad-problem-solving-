#include <iostream>

using namespace std;
int n,k;
int main()
{
    int t,f,max_joy=-1e9;
    cin>>n>>k;
    while(n--)
    {
        cin>>f>>t;
        if(t<=k) max_joy=max(max_joy,f);
        else max_joy=max(max_joy,(f-(t-k)));
    }
    cout<<max_joy;
    return 0;
}
