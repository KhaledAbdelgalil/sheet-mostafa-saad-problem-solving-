#include <bits/stdc++.h>
using namespace std;

string in;

int main()
{

    while(cin>>in)
    {
        if(in.size()==1&&in[0]=='0')break;
        int k=1;
        int dp[in.size()+1];
        memset(dp,0,sizeof dp);
        dp[0]=1;

        while(k<in.size())
        {
            if(in[k]-'0')
            dp[k]=dp[k-1];
            int num=(int)(in[k-1]-'0')*10;
            num+=(int)(in[k]-'0');
            if(num>9&&num<=26)
            {
                dp[k]+=dp[(k-2)>=0?k-2:0];
            }
            k++;
        }
        cout<<dp[in.size()-1]<<endl;
    }


    return 0;
}
