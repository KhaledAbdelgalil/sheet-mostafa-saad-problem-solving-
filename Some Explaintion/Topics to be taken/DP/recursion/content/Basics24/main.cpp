//note 183,464,533 is not solved yet
//problems on UVA:(10946-183-271-441-464-533-776)
#include <bits/stdc++.h>

using namespace std;

//10946
char board[50][50];
vector<bool>appear_chars(26);
int x,y;
int cnt=0;
void init()
{
    for(int i=0;i<26;i++)
        appear_chars[i]=0;
}
void cntReachableCells(int r,int c,char cell)
{
    if(r<0||r>=x||c>=y||c<0||board[r][c]!=cell) return;
    //unmarkcell
    board[r][c]='.';
    cnt++;
    cntReachableCells(r,c-1,cell);
    cntReachableCells(r,c+1,cell);
    cntReachableCells(r-1,c,cell);
    cntReachableCells(r+1,c,cell);
}
bool cmp(const pair<char,int> &a,const pair<char,int> &b)
{
    if(a.second>b.second) return true;
    if(a.second==b.second)
    {
        if(a.first<b.first) return true;
        return false;
    }
    return false;
}
void answer_10946()
{
    int cnt_probs=0;
    while(cin>>x>>y)
    {
        if(x==0&&y==0) break;
        cnt_probs++;
        init();
        //take input
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                cin>>board[i][j];
                if(board[i][j]>='A'&&board[i][j]<='Z') appear_chars[int(board[i][j]-'A')]=1;
            }
        }
        vector< pair<char,int> >results;
        char cell;
        for(int c=0;c<26;c++)
        {
            if(appear_chars[c])
            {
                cell=char(c+65);
                for(int i=0;i<x;i++)
                {

                    for(int j=0;j<y;j++)
                    {
                        cnt=0;
                        cntReachableCells(i,j,cell);
                        if(cnt>0)
                        {
                            results.push_back({cell,cnt});
                        }
                    }
                }

            }

        }

        sort(results.begin(),results.end(),cmp);
        //print result
        cout<<"Problem "<<cnt_probs<<':'<<endl;
        for(int i=0,sz=results.size();i<sz;i++)
        {
            cout<<results[i].first<<" "<<results[i].second<<endl;
        }

    }
}

//271
void answer_271()
{
    string s;

    while(getline(cin,s))
    {
        bool flag=1;
        int good=0;
        for(int i=s.size()-1;flag&&i>=0;i--)
        {
            switch(s[i])
            {
                case 'p'...'z':good++;break;
                case 'N':if(good==0)flag=0;break;
                case 'C':
                case 'D':
                case 'E':
                case 'I':if(good<2) flag=0;good--;break;
                default:flag=0;break;
            }
        }
        flag==1&&good==1?cout<<"YES":cout<<"NO";
        cout<<endl;
    }
}

void init(bool vis[])
{
    for(int i=0;i<50;i++)
        vis[i]=0;
}
void get_comb(int i,int m,int n,int curr[],int curlen,vector<int>&in)
{
    if(curlen==m)
    {
        for(int j=0;j<5;j++)
            cout<<curr[j]<<" ";
        cout<<curr[5];
        cout<<endl;
        return;
    }
    if(i==n) return;
    curr[curlen]=in[i];
    get_comb(i+1,m,n,curr,curlen+1,in);
    get_comb(i+1,m,n,curr,curlen,in);

}
void answer_441()
{
    string line;
    int x;
    int n;
    bool vis[50];
    int curr[50];
    int count=0;
    while(cin>>n)
    {

        if(n==0) break;
        if(count++)cout<<endl;
        init(vis);

        vector<int>in;
        for(int i=0;i<n;i++)
        {
            cin>>x;
                if(!vis[x])
                {
                in.push_back(x);
                vis[x]=1;
                }
        }


        sort(in.begin(),in.end());
        get_comb(0,6,int(in.size()),curr,0,in);
        in.clear();

    }
}

int main()
{

    //answer_10946();
   // answer_271();
   answer_441();

    return 0;
}
