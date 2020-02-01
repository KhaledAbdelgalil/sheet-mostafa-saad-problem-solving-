#include <bits/stdc++.h>
using namespace std;
int dx[] = {1,1,-1,-1,0,0,0,1,-1}, dy[] = {0,-1,0,1,1,-1,0,1,-1};
 
int solution(int x,int y,vector<string>board,int cnt)
{
    if(cnt==8)//if you can move 8 moves without losing so you can reach as all satutus fall of board
        return 1;
    if(x<0||x>7||y<0||y>7) return 0; //out of board
    if(board[x][y]=='S') return 0;//you are dead
    vector<string>board2=board;//adjust board2 for next move of status
   for(int i = 7 ;i >= 0;i--)
    {
        for(int j = 0; j <8 ; j++){
            if(board[i][j] == 'S' && i < 7){
                board2[i][j] = '.';
                board2[i+1][j] = 'S';
            }else if(board[i][j] == 'S'){
                board2[i][j] = '.';       
            }
        }
    }
    int ans=0;
    for(int i=0;i<9;i++)
    {
        if((x+dx[i]<0||x+dx[i]>7||y+dy[i]<0&&y+dy[i]>7)) continue;
        if(board[x+dx[i]][y+dy[i]]=='S')continue;
        ans|=solution(x+dx[i],y+dy[i],board2,cnt+1);
        if(ans) return ans;
    }
  return ans;
}
int main()
{
 
    vector<string>board(8);
    for(int i=0;i<8;i++)cin>>board[i];
 
    int answer=solution(7,0,board,0);
    answer==1?cout<<"WIN":cout<<"LOSE";
    return 0;
}