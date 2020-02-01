//uva problems::10496-
#include <bits/stdc++.h>
using namespace std;
typedef bitset<12> MASK;
struct beep{
int x;
int y;
}beepers[12];
int beepers_num;
int mem[12][1<<12];
int answer(int prev,MASK bitmask)
{
    if(bitmask.to_ulong()==(1<<beepers_num)-1)
        return abs(beepers[0].x-beepers[prev].x)+abs(beepers[0].y-beepers[prev].y);
    int &ret=mem[prev][bitmask.to_ulong()];
    if(ret!=-1) return ret;
    ret=10000000;
    for(int i=0;i<beepers_num;i++)
    {
        if(bitmask[i]==0)
        {
            bitmask[i]=1;
             ret=min(ret,answer(i,bitmask)+abs(beepers[i].x-beepers[prev].x)+abs(beepers[i].y-beepers[prev].y));
             bitmask[i]=0;
        }
    }
    return ret;
}
void solve_10496()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        MASK bits;

        cin>>n>>m;
        cin>>beepers[0].x>>beepers[0].y;
        cin>>beepers_num;
        beepers_num++;
        for(int i=1;i<beepers_num;i++)
            {
            cin>>beepers[i].x>>beepers[i].y;
            bits[i]=0;
            }
            bits[0]=1;
            memset(mem,-1,sizeof mem);
        cout<<"The shortest path has length "<<answer(0,bits)<<endl;
    }


}
typedef bitset<16> MASKD;
typedef bitset<8> MASKR_C;
int board[8][8];

int ans(int col,MASKD d1,MASKD d2,MASKR_C r,int sum=0)
{
    if(col==8)
    {
        return sum;
    }

    int ret=0;
    for(int row=0;row<8;row++)
    {
        int dd1=row-col;
        int dd2=row+col-7;
        if(dd1<0)dd1+=15;
        if(dd2<0)dd2+=15;
        if(d1[dd1]==0&&d2[dd2]==0&&r[row]==0)
        {
            d1[dd1]=1;
            d2[dd2]=1;
            r[row]=1;
            ret=max(ret,ans(col+1,d1,d2,r,sum+board[row][col]));
             d1[dd1]=0;
            d2[dd2]=0;
            r[row]=0;
        }
    }
    return ret;
}
void answer_167()
{
    int k;
    cin>>k;
    while(k--)
    {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            cin>>board[i][j];
        MASKD d1;
        MASKD d2;
        MASKR_C r;
        printf("%5d\n",ans(0,d1,d2,r,0));
    }
}
int main()
{
    //solve_10496();
    answer_167();
    return 0;
}
