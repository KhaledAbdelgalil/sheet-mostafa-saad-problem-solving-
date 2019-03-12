#include <bits/stdc++.h>
#include<vector>
using namespace std;

int n,m,x,q,steps;
char keys[31][31];
char in[1000000];
bool visited[26];
bool can[26];
typedef pair<int,int> ii;
vector< pair <int,int> > shift_pos;
vector< pair <int,int> > keys_pos[26];
bool check(int i,int j)
{
    for (int k = 0;k<shift_pos.size(); k++)
    {
        if((shift_pos[k].first-i)*(shift_pos[k].first-i)+(shift_pos[k].second-j)*(shift_pos[k].second-j)<=x*x) return 1;
    }
    return 0;
}

void check_all_keys()
{

    for (int i = 0;i<26; i++)
		for (int j = 0;j <keys_pos[i].size() && !can[i]; j++)
		{                                                                         //check of each key if can press on it with one hand
			can[i] = can[i] | check(keys_pos[i][j].first, keys_pos[i][j].second);
		}
}

int main()
{
    scanf("%d %d %d",&n,&m,&x);
    for(int i=0;i<n;i++)
        scanf("%s",keys[i]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(keys[i][j]=='S')
        {
            shift_pos.push_back(ii(i,j));
        }
        else
        {
            keys_pos[keys[i][j]-'a'].push_back(ii(i,j));
        }
    }
    check_all_keys();
    scanf("%d%s",&q,in);
    for(int i=0;i<q;i++)
    {
        if(isupper(in[i]))//check shift
        {
            if(shift_pos.empty()||keys_pos[in[i]-'A'].empty())
            {
                steps=-1;
                break;
            }
            else
            {
                if(!can[in[i]-'A']) steps++;
            }
        }
        else
        {
            if(keys_pos[in[i]-'a'].empty())
                {
                    steps=-1;
                    break;
                }
        }
    }
printf("%d",steps);
    return 0;
}
