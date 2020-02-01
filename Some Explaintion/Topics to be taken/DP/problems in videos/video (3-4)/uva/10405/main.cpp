#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int N,M;
int LCS()
{
    int table[N+1][M+1];
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i==0||j==0)
                table[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                table[i][j]=table[i-1][j-1]+1;
            else
                table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
    return table[N][M];
}
int main()
{
    while(getline(cin,s1))
    {
        if(cin.eof())break;
        getline(cin,s2);
        N=s1.size();
        M=s2.size();
        cout<<LCS()<<endl;
    }
    return 0;
}
