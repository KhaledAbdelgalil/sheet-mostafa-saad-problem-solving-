//LIS don't solve it using memorization solve using table method

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t,n;
    cin>>t;
    getchar();
    char c[20];
    gets(c);
    while(t--)
    {
        int a;
        vector<int>arr;
        while(gets(c)&&strlen(c))
        {
            arr.push_back(atoi(c));
        }
        int DP[arr.size()];
        int path[arr.size()];
        memset(path,-1,sizeof path);
        DP[0]=1;

        for(int i=1;i<arr.size();i++)
        {
            DP[i]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i]&&DP[i]<DP[j]+1)
                {
                    DP[i]=DP[j]+1;
                    path[i]=j;
                }
            }
        }
        int idx=distance(DP,max_element(DP,DP+arr.size()));

        cout<<"Max hits: "<<DP[idx]<<endl;
        vector<int>sol;
        while(idx!=-1)
        {
            sol.push_back(arr[idx]);
            idx=path[idx];
        }
        reverse(sol.begin(),sol.end());
        for(int i=0;i<sol.size();i++)
            cout<<sol[i]<<endl;

        if(t!=0)cout<<endl;
    }
    return 0;
}
