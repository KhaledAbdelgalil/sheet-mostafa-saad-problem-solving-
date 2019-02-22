#include <bits/stdc++.h>
using namespace std;
long long s=0;
string in;


int main()
{
    cin>>in;
    if(in.size()==1){cout<<0;return 0;}
    long long out=0;

    for(long long i=0;i<in.size();i++)
    {
        s+=int(in[i])-48;
    }
    if(s/10==0){cout<<1; return 0;}
    //cout<<s;
        out++;
       long long s2=0;
       while(1)
       {
            s2+=s%10;
            s/=10;
            if(s==0)
            {
                out++;
                s=s2;
                s2=0;
                if(s/10==0) break;
            }

       }
    cout<<out;
}
