#include <bits/stdc++.h>
using namespace std;
int rows,cols;
int grid[11][101];
int mem[11][101];
int fix(int row)
{
    return (row%rows+rows)%rows;
}
int min_path(int r,int c)
{
    if(c==cols) return 0;
    int &ret=mem[r][c];
    if(ret!=-1)return ret;
    int path1=grid[r][c]+min_path(fix(r-1),c+1);
    int path2=grid[r][c]+min_path(fix(r),c+1);
    int path3=grid[r][c]+min_path(fix(r+1),c+1);

    return ret=min(path1,min(path2,path3));

}
void build_rec(int r,int c)
{
    if(c==cols-1) return ;

    int path1=grid[r][c]+min_path(fix(r-1),c+1);
    int path2=grid[r][c]+min_path(fix(r),c+1);
    int path3=grid[r][c]+min_path(fix(r+1),c+1);
    int ans=min_path(r,c);
    if(r==0)
    {
        if(ans==path2)
        {
            cout<<" "<<fix(r)+1;
            build_rec(fix(r),c+1);
            return;
        }
        else if(ans==path3)
        {
            cout<<" "<<fix(r+1)+1;
            build_rec(fix(r+1),c+1);
            return;
        }

        else if(ans==path1)
        {
            cout<<" "<<fix(r-1)+1;
            build_rec(fix(r-1),c+1);
            return;
        }
    }
    else if(r==rows-1)
    {
        if(ans==path3)
        {
            cout<<" "<<fix(r+1)+1;
            build_rec(fix(r+1),c+1);
            return;
        }
        else if(ans==path1)
        {
            cout<<" "<<fix(r-1)+1;
            build_rec(fix(r-1),c+1);
            return;
        }
        else if(ans==path2)
        {
            cout<<" "<<fix(r)+1;
            build_rec(fix(r),c+1);
            return;
        }

    }
    else
    {
        if(ans==path1)
        {
            cout<<" "<<fix(r-1)+1;
            build_rec(fix(r-1),c+1);
            return;
        }
        else if(ans==path2)
        {
            cout<<" "<<fix(r)+1;
            build_rec(fix(r),c+1);
            return;
        }

        else if(ans==path3)
        {
            cout<<" "<<fix(r+1)+1;
            build_rec(fix(r+1),c+1);
            return;
        }
    }
}
int main()
{


    while(true)
    {
        cin>>rows;
        if(cin.eof()) break;
        cin>>cols;
        memset(mem,-1,sizeof mem);
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                cin>>grid[i][j];



        int min_row=0;
        int min_weight=min_path(0,0);
        for(int i=1;i<rows;i++)
        {
            int weight=min_path(i,0);
            if(weight<min_weight)
            {
                min_weight=weight;
                min_row=i;
            }
        }
        cout<<min_row+1;
        build_rec(min_row,0);
        cout<<endl<<min_weight<<endl;
    }
    return 0;
}
