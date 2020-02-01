//continue recursion
#include <iostream>

using namespace std;
//maze start from S till E pass by . blocked by # find if there's is path or not
#define MAX 5
char maze[MAX][MAX]={'.','S','x','.','.',
                    '.','.','x','.','E',
                    '.','.','.','.','x',
                    'x','.','x','x','.',
                    'x','x','x','x','x'
};
//backtracking
bool findEnd(int r ,int c)
{
    if(r<0||c<0||r>=MAX||c>=MAX||maze[r][c]=='x') return false;
    if(maze[r][c]=='E') return true;
    maze[r][c]='x';//mark

    if(findEnd(r,c-1)) return true;
    if(findEnd(r,c+1)) return true;
    if(findEnd(r-1,c)) return true;
    if(findEnd(r+1,c)) return true;
    maze[r][c]='.';//unmark
    return false;

}
//floodfill:count number of connected components and count reachable cells from starting position
int cnt=0;
char maze2[3][3]={
                '.','x','.',
                '.','x','x',
                '.','x','.'
                };

void cntReachable(int r,int c)
{
    if(r>=3||c>=3||r<0||c<0||maze2[r][c]=='x') return;

    //if not you reach it mark it with x to not visit it again
    cnt++;
    maze2[r][c]='x';
    //try 4 neighbour cells
    cntReachable(r,c-1);
    cntReachable(r,c+1);
    cntReachable(r-1,c);
    cntReachable(r+1,c);

}
int cntConnectedComponents()
{
    int comps=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cnt=0;
            cntReachable(i,j);
            if(cnt>0) comps++;
        }
    return comps;
}
//generate binary of length:? guess answer
void generateBinary(int len,string curr="")
{
    if(len==0)
    {
        cout<<curr<<'\n';
        return;
    }
    generateBinary(len-1,curr+'0');
    generateBinary(len-1,curr+'1');

}
void perm(int i,int n,bool vis[],int curr[])
{
    if(i==n)
    {
        for(int j=0;j<n;++j)
            cout<<curr[j];
        cout<<"\n";
        return;
    }
    for(int j=0;j<n;++j)if(!vis[j])
    {
        vis[j]=1;
        curr[i]=j;
        perm(i+1,n,vis,curr);
        vis[j]=0;
    }
}
void test_perm()
{
    bool vis[3]={0,0,0};
    int curr[3];
    perm(0,3,vis,curr);
}
void test_perm2()
{
    bool vis[2]={0,0};
    int curr[2];
    perm(0,2,vis,curr);
}
//combination
void comb(int i,int n,int m,int curr[],int curlen)
{
    if(curlen==m)
    {
        for(int j=0;j<m;j++)
            cout<<curr[j];
        cout<<'\n';
        return;
    }
    if(i==n) return;//reach end but current combination is incorrect
    //take it
    curr[curlen]=i;
    comb(i+1,n,m,curr,curlen+1);
    //don't take it
    comb(i+1,n,m,curr,curlen);

}

void test_comb()
{
    int curr[3];
    comb(0,3,2,curr,0);
}
void test_comb2()
{
    int curr[3];
    comb(0,3,3,curr,0);
}
int main()
{
    //cout<<findEnd(0,0)<<endl;
    /*cntReachable(0,0);
    cout<<cnt<<endl;
    cnt=0;*/
    /*cntReachable(0,2);
    cout<<cnt<<endl;*/
   // cout<<cntConnectedComponents()<<endl;
    //generateBinary(3);//guess start as binary tree its root is "" and 2 children 0 and 1
   // test_perm();
  // test_perm2();
  //test_comb2();
  test_comb();
    return 0;
}
