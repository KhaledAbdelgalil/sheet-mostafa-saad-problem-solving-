#include <bits/stdc++.h>
using namespace std;
const string AMP="AMBIGUOUS! ";
const string IMP="IMPOSSIBLE! ";
vector<string>dic;
map<string ,string>mp;

string rest(string m)
{
    if(m.size()==0)return m;
    if(mp.count(m)!=0)return mp[m];
    string sol=IMP;
    for(int i=0;i<dic.size();i++)
    {
        if(m.size()>=dic[i].size()&&m.substr(0,dic[i].size())==dic[i])
        {
            string tail=rest(m.substr(dic[i].size()));
            if(tail==AMP) return mp[m]=AMP;
            if(tail==IMP) continue;
            if(sol!=IMP) return mp[m]=AMP;
            sol=dic[i]+" "+tail;
        }
    }
    return mp[m]=sol;
}
class MessageMess{
public:
    string restore(vector<string> dictionary, string message)
    {
        dic=dictionary;
        string sol=rest(message);
        return sol.substr(0,sol.size()-1);
    }

};
int main()
{
    int t;
    string mm;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        vector<string>b(n);
        for(int i=0;i<n;i++)
            cin>>b[i];
        dic.clear();
        dic=b;
        cin>>mm;
        cout<<rest(mm)<<endl;
        mp.clear();
    }
    return 0;
}
