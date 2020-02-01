#include <bits/stdc++.h>
using namespace std;
bool grid[100][100];
int mem[100][100];
int Rows,Cols;
int countt_paths_of_minimal(int r,int c)
{
    if(r>=Rows||r<0||c<0||c>Cols||grid[r][c])
        return 0;
    int &ret=mem[r][c];
    if(ret!=-1)return ret;
    if(r==Rows-1&&c==Cols-1) return ret=1;
    ret=countt_paths_of_minimal(r+1,c)+countt_paths_of_minimal(r,c+1);
    return ret;
}
int main()
{
    int n,x,y;
    scanf("%d", &n);
    string s;
    stringstream ss;

    while(n--)
    {
        memset(grid,0,sizeof grid);
        memset(mem,-1,sizeof mem);
        scanf("%d %d", &Rows, &Cols);
        getline(cin, s);
        for(int i=0;i<Rows;i++)
        {
        getline(cin, s);
        ss.clear();
        ss << s;
        ss >> x;
        while(ss >> y)grid[x-1][y-1] = true;
        }

        printf("%d\n", countt_paths_of_minimal(0,0));
        if(n)puts("");
    }
    return 0;
}
