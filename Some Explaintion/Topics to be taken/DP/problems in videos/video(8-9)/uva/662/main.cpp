#include <bits/stdc++.h>

using namespace std;
int s[201][201];
int d[201];
int mid[201][201];
int n;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
            cin>>d[i];
 memset(s, 0, sizeof(s));
        for(int i=1; i<=n; i++){
            mid[i][i]=i;
            for(int j=i+1; j<=n; j++){
                int tmp=(i+j)/2;
                mid[i][j]=tmp;
                for(int u=i; u<=j; u++)
                    s[i][j]+=abs(d[u]-d[tmp]);}}
                    for(int i=1;i<=n;i++)
                        for(int j=1;j<=n;j++)
                        cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
}
