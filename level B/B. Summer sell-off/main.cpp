#include <bits/stdc++.h>

using namespace std;
int n,f;
vector<pair <long long,long long> >fs;
bool comp( pair<long long,long long> &a, pair<long long,long long> &b)
{
    return min(a.first*2,a.second)-min(a.first,a.second)>min(b.first*2,b.second)-min(b.first,b.second);
}
int main()
{
    cin>>n>>f;
    long long x,y;
    long long out=0;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x==0) continue;
        else if(x>=y) out+=y;
        else fs.push_back(make_pair(x,y));
    }
    sort(fs.begin(),fs.end(),comp);
    for(int i=0;i<fs.size();i++)
    {
        if(f>0) {out+=min(fs[i].first*2,fs[i].second); f--;}
        else out+=min(fs[i].first,fs[i].second);
    }
    cout<<out;
    return 0;
}

