#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x;
    int t=0;
    while(cin>>x)
    {
        if(x==-1)break;
        vector<int>arr;
        arr.push_back(x);
        while(cin>>x)
        {
            if(x==-1)break;
            arr.push_back(x);
        }
        int DP[arr.size()];
        DP[0]=1;
        int ans=1;
        for(int i=1;i<arr.size();i++)
        {
            DP[i]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[j]>arr[i]&&DP[i]<1+DP[j])
                {
                  DP[i]=1+DP[j];
                  ans=max(ans,DP[i]);
                }
            }
        }
        if(t)cout<<endl;
        cout<<"Test #"<<++t<<":\n";
        cout<<"  maximum possible interceptions: "<<ans<<endl;
    }
    return 0;
}
