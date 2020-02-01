//practice.geeksforgeeks.org/problems/cutting-binary-string/0)
#include <bits/stdc++.h>
using namespace std;
string in;
int mem[51][51];
int n;
bool isDiv_5(string S)
{
    if(S[0]=='0')return 0;
    if(S.size()==0)return 0;
    int val = 0;
	int pow = 1;
	for(int i = S.size()-1; i >= 0; i--)
	{
	    val = val + pow*(S[i] == '1' ? 1 : 0);
		pow *= 2;
	}

    if(val == 0)
		return 0;
	while(val > 1 && val % 5 == 0)
		val /= 5;

	return val == 1 ? 1 : 0;

}
int min_cost(int curr,int last)
{
    if(curr==n)
        return 0;
    int &ret=mem[curr][last];
    if(ret!=-1)return ret;
    ret=1e9;
    if(isDiv_5(in.substr(last,curr-last+1)))
        ret=1+min_cost(curr+1,curr+1);
    if(curr!=n-1)
        ret=min(ret,min_cost(curr+1,last));

    return ret;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>in;
        n=in.size();
        int ans=min_cost(0,0);
        if(ans==1e9)
            cout<<-1<<endl;
        else cout<<ans<<endl;

    }
    return 0;
}
