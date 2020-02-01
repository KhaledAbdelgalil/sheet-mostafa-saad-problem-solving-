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
    int t;
    cin>>t;
    while(t--)
    {
        string board="";
        string row;
        for(int i=0;i<3;i++)
            cin>>row,board+=row;
        string start=".........";
        queue<string>q;
        queue<int>qq;
        qq.push(1);
        q.push(start);
        string ans="no";
        while(!q.empty())
        {
            string f=q.front();
            int p=qq.front();
            qq.pop();
            q.pop();
            if(f==board)
            {
                ans="yes";
                break;
            }
            if(is_win(f))continue;
            for(int i=0;i<9;i++)
            {
                if(f[i]=='.')
                {
                    f[i]=p?'X':'O';
                    if(f[i]==board[i])
                        q.push(f),qq.push(!p);
                    f[i]='.';
                }
            }
        }
        cout<<ans<<endl;
    }
}
//another sol

/*#include <bits/stdc++.h>

using namespace std;
int grid[3][3];// .:1   0:2      X:4
char c;
int win(int s)
{
    int res=s;
    for(int i=0;i<3;i++)
    {
        res=s;
        for(int j=0;j<3;j++)
            res&=grid[i][j];
        if(res==s)return 1;
    }
    res=s;
    for(int i=0;i<3;i++)
    {
        res=s;
        for(int j=0;j<3;j++)
            res&=grid[j][i];
        if(res==s)return 1;
    }
    int l=s;int r=s;
    for(int i=0;i<3;i++)
    {
        r&=grid[i][i];
        l&=grid[i][3-i-1];
    }
    return r||l;
}
int main()
{
    int t;
    cin>>t;
    while(t--)

    {
        int x=0,o=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
    {
        cin>>c;
        if(c=='X')
            {grid[i][j]=4;x++;}
        else if(c=='O')
            {grid[i][j]=2;o++;}
        else
            grid[i][j]=1;
    }
    int checkx=win(4);
    int checko=win(2);
    if((abs(x-o)>=2)||(checko&&checkx)||((o-x)>0))
        cout<<"no"<<endl;
    else if(checko)
    {
        if(x>o)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    else if(checkx)
    {
        if(x==o)
              cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    else
    {
        if(x==5&&o==4)
        {
            cout<<"yes"<<endl;
        }
        else if(x==o)
            cout<<"yes"<<endl;
        else if(x>o)
            cout<<"yes"<<endl;
        else
            cout<<"yes"<<endl;
    }
    cout<<endl;
    }
    return 0;
}*/
