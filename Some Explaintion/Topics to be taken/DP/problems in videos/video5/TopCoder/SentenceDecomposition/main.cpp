#include <bits/stdc++.h>

using namespace std;
map<string ,int>mp;
vector<string>dic;

int min_cost(string m)
{
    if(m=="")return 0;
    if(mp.count(m)!=0)return mp[m];
    int sol=1e9;
    for(int i=0;i<dic.size();i++)
    {
        if(m.size()>=dic[i].size())
        {
            string mm=m.substr(0,dic[i].size());
            string dd=dic[i];
            sort(mm.begin(),mm.end());
            sort(dd.begin(),dd.end());
            if(dd==mm)
            {
                mm=m.substr(0,dic[i].size());
                int cost=0;
                for(int j=0;j<dic[i].size();j++)
                    if(mm[j]!=dic[i][j])
                    cost++;
                sol=min(sol,min_cost(m.substr(dic[i].size()))+cost);
            }
        }
    }
    return mp[m]=sol;
}
class SentenceDecomposition {

public:
 int decompose(string sentence, vector <string> validWords)
    {
        dic=validWords;
        int sol=min_cost(sentence);
        if(sol==1e9)return -1;
        return sol;
    }

};
int main()
{
    SentenceDecomposition* pt=new SentenceDecomposition();
    int n;
    cin>>n;
    dic.resize(n);
    for(int i=0;i<n;i++)
        cin>>dic[i];
    string s;
    cin>>s;
    cout<<pt->decompose(s,dic);
    return 0;
}
