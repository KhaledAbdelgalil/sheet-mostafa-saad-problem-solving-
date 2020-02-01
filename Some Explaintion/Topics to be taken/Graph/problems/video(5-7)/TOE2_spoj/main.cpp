#include <bits/stdc++.h>
using namespace std;
bool is_win(string config) {

	bool rows =
		(config[0] != '.' && config[0] == config[1] && config[1] == config[2]) ||
		(config[3] != '.' && config[3] == config[4] && config[4] == config[5]) ||
		(config[6] != '.' && config[6] == config[7] && config[7] == config[8]);

	bool columns =
		(config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
		(config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
		(config[2] != '.' && config[2] == config[5] && config[5] == config[8]);

	bool diagonals =
		(config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
		(config[2] != '.' && config[2] == config[4] && config[4] == config[6]);

	return rows || columns || diagonals;
}





int main()
{
    string t="00";
    cin>>t;
    while(t!="end")
    {
        string board=t;
        string start=".........";
        queue<string>q;
        queue<int>qq;
        queue<int>depth;
        qq.push(1);
        q.push(start);
        depth.push(0);
        string ans="invalid";
        while(!q.empty())
        {
            string f=q.front();
            int p=qq.front();
            int d=depth.front();
            depth.pop();
            qq.pop();
            q.pop();

            if(f==board&&d==9)
            {
                ans="valid";
                break;
            }
            if(f==board&&is_win(f))
            {
                ans="valid";
                break;
            }
            if(is_win(f))continue;
            for(int i=0;i<9;i++)
            {
                if(f[i]=='.')
                {
                    f[i]=p?'X':'O';
                    if(f[i]==board[i])
                        q.push(f),qq.push(!p),depth.push(d+1);
                    f[i]='.';
                }
            }
        }
        cout<<ans<<endl;
        cin>>t;
    }
}
