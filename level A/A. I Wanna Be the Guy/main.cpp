#include <iostream>

using namespace std;
int levels[109];
int levels_passed=0;
int main()
{
    int n,p,q;
    cin>>n>>p;
    for(int i=1;i<=p;i++)
    {
        cin>>q;
        if(!levels[q]) {levels_passed++;levels[q]=1;}
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>p;
        if(!levels[p]) {levels_passed++;levels[p]=1;}
    }
    if(levels_passed==n) cout<<"I become the guy.";
    else cout<<"Oh, my keyboard!";
    return 0;
}
