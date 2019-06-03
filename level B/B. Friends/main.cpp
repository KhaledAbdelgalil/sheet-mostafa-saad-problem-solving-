#include <iostream>

using namespace std;
bool s[5][5];
int main()
{
    int m;
    int x,y;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        s[x-1][y-1]=s[y-1][x-1]=true;
    }

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(i!=j)
            for(int k=0;k<5;k++)
                {
                    if(i!=k&&j!=k&&((s[i][j]&&s[j][k]&&s[k][i])||(!s[i][j]&&!s[j][k]&&!s[k][i])))
                    {
                        cout<<"WIN";return 0;
                    }

                }
                cout<<"FAIL";
    return 0;
}
