#include <bits/stdc++.h>
int n,m;
using namespace std;
 typedef struct container
{
    int matchesboxes;
    int matches;
}con;
bool greedy(con a, con b)
{
    if(a.matches>b.matches) return 1;

    return false;
}
int main()
{
    cin>>n>>m;
    con s[m];
    for(int i=0;i<m;i++)
    {
        cin>>s[i].matchesboxes>>s[i].matches;
    }

    sort(s,s+m,greedy);
    //cout<<s[0].matches<<s[0].matchesboxes;
    int i=0;
    unsigned long long sum=0;
    while(n!=0&&i<m)//5ale balek momken mykonsh feeh kafia tkfy asln
    {
        if(n>s[i].matchesboxes){sum+=s[i].matches*s[i].matchesboxes;n-=s[i].matchesboxes; i++;}
        else {sum+=s[i].matches*n;n=0;}
    }
    cout<<sum;
    return 0;
}
