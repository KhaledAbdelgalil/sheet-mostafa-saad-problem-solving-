#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char x;
    char flag_c,flag_r;
    int  correct=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            if(x==flag_r&&i!=0) correct=0;
            if(j==0)
            {
                flag_c=x;
            }
            else{
                if(x!=flag_c) correct=0;
            }
        }
        flag_r=x;

    }
    (correct==1)?cout<<"YES":cout<<"NO";
    return 0;
}
