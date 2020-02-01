//tutorial on recursion:problem->subproblem->subproblem until basecase(never go to infinity)
#include <bits/stdc++.h>
using namespace std;
#define N 5
void print_triangle(int n)//n is no.of rows
{
    if(n<=0)return;
    print_triangle(n-1);
    for(int i=1;i<=n;i++)
        cout<<"*";
    cout<<endl;
}
void print_triangle_reversed(int n)
{
    if(n<=0)return;
    for(int i=1;i<=n;i++)
        cout<<"*";
    cout<<endl;
    print_triangle_reversed(n-1);
}
//given grid start from (0,0) till (n,n) move only down or right bring maxSum in path
int maxpathsum(int grid[N][N],int r,int c)
{
    if(r<0||c<0||r>=N||c>=N) return 0;
    if(r==N-1&&c==N-1) return grid[r][c];
    int path1=maxpathsum(grid,r,c+1);//move to right
    int path2=maxpathsum(grid,r+1,c );//move to down
    return grid[r][c]+max(path1,path2);
}
int main()
{
    //print_triangle(5);
    //print_triangle_reversed(5);
    /*int grid[5][5]={1,2,3,4,5,
                    6,7,8,9,10,
                    11,12,13,14,15,
                    16,17,18,19,20
                    ,21,22,23,24,25
                    };
    cout<<maxpathsum(grid,0,0)<<endl;*/

    return 0;
}
