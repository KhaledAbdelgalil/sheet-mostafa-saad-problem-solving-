//problem on UVA:(825)
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define MAX 101
bool grid[MAX][MAX];
bool vis_825_Bfs[MAX][MAX];
int shortest_path,Rows,Cols;
int mem[MAX][MAX];
void BFS_825()
{
    int steps=0,x_now,y_now;
    queue<int>x,y;
    x.push(0);
    y.push(0);
    vis_825_Bfs[0][0]=1;
     x.push(-1);
    y.push(-1);
    while(!x.empty())
    {
        x_now=x.front();
        y_now=y.front();
        x.pop();
        y.pop();
        if(x_now==-1&&y_now==-1) {
            steps++;
            x.push(-1);
            y.push(-1);
        }
        else if(x_now==Rows-1&&y_now==Cols-1)
        {
            shortest_path=steps ;
            return;
        }
        if(x_now+1<Rows&&x_now+1>=0&&y_now<Cols&&y_now>=0&&!vis_825_Bfs[x_now+1][y_now])
        {
            vis_825_Bfs[x_now+1][y_now]=1;
            x.push(x_now+1);
            y.push(y_now);
        }

        if(x_now<Rows&&y_now+1>=0&&y_now+1<Cols&&y_now>=0&&!vis_825_Bfs[x_now][y_now+1])
        {
            vis_825_Bfs[x_now][y_now+1]=1;
            x.push(x_now);
            y.push(y_now+1);
        }

    }
}
int countt=0;
void solve(int r,int c,int i)
{

    if(r==Rows-1&&c==Cols-1)
        if(i<=shortest_path)
            {countt++;return;}

    if(r+1>=0&&r+1<Rows&&grid[r+1][c])
    {
            grid[r+1][c]=0;
            solve(r+1,c,i+1);
            grid[r+1][c]=1;
    }
    if(c+1>=0&&c+1<Cols&&grid[r][c+1])
    {
            grid[r][c+1]=0;
            solve(r,c+1,i+1);
            grid[r][c+1]=1;
    }

}
int M[MAX][MAX];
void init()
{
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            {
                grid[i][j]=1;
                mem[i][j]=-1;
                vis_825_Bfs[i][j]=0;
                M[i][j]=0;
            }
}
void answer_825()
{
    int n,x,y;
    scanf("%d", &n);
    string s;
    stringstream ss;

    while(n--)
    {
        init();
        scanf("%d %d", &Rows, &Cols);getline(cin, s);
        for(int i=0;i<Rows;i++)
        {
        getline(cin, s);
        ss.clear();
        ss << s;
        ss >> x;
        while(ss >> y)grid[x-1][y-1] = false;
        }
        BFS_825();
        countt=0;
        solve(0,0,0);
        printf("%d\n", countt);
        if(n)puts("");
    }
};
void answer2_825()
{

    int n,x,y;
    scanf("%d", &n);
    string s;
    stringstream ss;

    while(n--)
    {
        init();
        scanf("%d %d", &Rows, &Cols);getline(cin, s);
        for(int i=0;i<Rows;i++)
        {
        getline(cin, s);
        ss.clear();
        ss << s;
        ss >> x;
        while(ss >> y)grid[x][y] = false;
        }
       for(int i=1;i<=Rows;i++)
        for(int j=1;j<=Cols;j++)
            if(grid[i][j])
            {
            if(i==1&&j==1)M[i][j]=1;
            else M[i][j]=M[i-1][j]+M[i][j-1];
            }
        printf("%d\n", M[Rows][Cols]);
        if(n)puts("");
    }
}
int main()
{
    //answer_825();
    answer2_825();
    return 0;
}
