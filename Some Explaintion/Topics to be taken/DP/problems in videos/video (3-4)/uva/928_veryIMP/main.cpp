#include <bits/stdc++.h>

using namespace std;

const int OO=0x7fffffff;

void solution() {
    int x1, y1, x2, y2;

    int n, m;
    int depth;
    int p;
    cin >> n >> m;
    char c;
    int vis[301][301][4];
    int board[301][301];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            if (c == '.')
                board[i][j] = true;
            else if (c == '#') board[i][j] = false;
            else if (c == 'S') {
                board[i][j] = true;
                x1 = i;
                y1 = j;
            } else {
                board[i][j] = true;
                x2 = i;
                y2 = j;
            }
        vis[i][j][0]=vis[i][j][1]=vis[i][j][2]=vis[i][j][3]=OO;
        }

        //cout<<endl;
    }
    //cout<<x1<<y1<<x2<<y2;
    pair<int, int> initial = make_pair(x1, y1);
    pair<int, int> final = make_pair(x2, y2);
    queue<pair<pair<int, int>,int> > Q;
     Q.push(make_pair(make_pair(x1,y1),0));
    vis[x1][y1][0]=0;
    int found=0;
    int a_x[]={-1,1,0,0};
 int a_y[]={0,0,1,-1};
     while(!Q.empty() && !found)
    {
        int curr_x=Q.front().first.first;
        int curr_y=Q.front().first.second;
        int jump=Q.front().second;

        p=jump%3+1;
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int next_x=curr_x+p*a_x[i];
             int next_y=curr_y+p*a_y[i];


             if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m&&board[next_x][next_y]&&vis[next_x][next_y][p]==OO)
             {
                int check =1;
                for(int t=1;t<=p;t++)
                    if(board[curr_x+t*a_x[i]][curr_y+t*a_y[i]]==0)
                    {check=0;break;}
                if(check)
                {
                    vis[next_x][next_y][p]=vis[curr_x][curr_y][jump]+1;
                    Q.push({{next_x,next_y},p});
                    if(next_x==final.first&&next_y==final.second)
                    {
                        found=1;
                        break;
                    }
                }
             }
        }


    }

    if(!found)cout<<"NO\n";
    else cout<<vis[x2][y2][p]<<endl;
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solution();
    }

}
