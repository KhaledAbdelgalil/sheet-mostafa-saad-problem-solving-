#include <bits/stdc++.h>
using namespace std;

map<string ,long long >mp[60];

long long countt_notforbidden(int n,string s="")
{
    if(s.size()==3&&s[0]!=s[1]&&s[1]!=s[2]&&s[0]!=s[2])return 0;
    if(s.size()>2)return countt_notforbidden(n,s.substr(1));
    if(n==0)return 1;
    if(mp[n].count(s))return mp[n][s];
    long long ret=0;
    for(char c='A';c<='C';c++)
        ret+=countt_notforbidden(n-1,s+c);
    return mp[n][s]=ret;
}
class ForbiddenStrings
{
public:
   long long countNotForbidden(int n)
  {
    return countt_notforbidden(n);
  }
};

int main()
{
    ForbiddenStrings* s=new ForbiddenStrings();
    cout<<s->countNotForbidden(4);
    return 0;
}
