#include<bits/stdc++.h>

using namespace std;
string password="";
int main()
{
    int n,k;
    char start='a';
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        password+=start;
        start++;
    }
    char finish=start;
    start='a';
    for(int i=k;i<n;i++)
    {
        if(start=='z'||start==finish)
            start='a';
        password+=start;
        start++;

    }
    cout<<password;
    return 0;
}
