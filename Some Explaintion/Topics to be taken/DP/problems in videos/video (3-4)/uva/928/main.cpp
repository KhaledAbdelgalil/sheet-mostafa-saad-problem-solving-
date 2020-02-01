#include <bits/stdc++.h>

using namespace std;

const int OO=0x7fffffff;

void solution() {
    int x1, y1, x2, y2;

    int n, m;
    int depth;
    cin >> n >> m;
    char c;
    int vis[301][301][4];
    vector<vector<bool> > board(n, vector<bool>(m, false));
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
