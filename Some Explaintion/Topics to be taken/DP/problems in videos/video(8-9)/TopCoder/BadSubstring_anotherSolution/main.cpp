#include <bits/stdc++.h>
using namespace std;
map<string,long long>mp[60];
long long countt_bad(int n,string s)
{
    if(s.size()==2&&s[0]=='a'&&s[1]=='b')return 0;
    if(s.size()>1)return countt_bad(n,s.substr(1));
    if(n==0)return 1;
    if(mp[n].count(s))return mp[n][s];
    long long ret=0;
    for(char c='a';c<='c';c++)
        ret+=countt_bad(n-1,s+c);
    return mp[n][s]=ret;
}
class BadSubstring {

public:
  long long howMany(int length) {

    return countt_bad(length,"");
  }
};
int main()
{
    BadSubstring* s=new BadSubstring();
    cout<<s->howMany(0)<<" "<<s->howMany(29);
}
