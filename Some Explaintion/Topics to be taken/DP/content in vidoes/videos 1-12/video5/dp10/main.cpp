//problems on geeksforgeeks(CuttingBitString:https://practice.geeksforgeeks.org/problems/cutting-binary-string/0)
#include <bits/stdc++.h>
using namespace std;
#define table
int mem[51][51];
const int OO=(int)1e9;
bool isDiv(string S)
{
    if(S[0]=='0')return 0;
    if(S.size()==0)return 0;
    int val = 0;
	int pow = 1;
	for(int i = S.size()-1, loop_ends_here = (int)0; i >= 0; i--)
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
int answer(string S,int curr,int last)
{
    if(curr==S.size()) return 0;
    int &ret=mem[curr][last];
    if(ret!=-1)return ret;
    ret=OO;
    if(isDiv(S.substr(last,curr-last+1)))
        ret=1+answer(S,curr+1,curr+1);
    if(curr!=S.size()-1)
        ret=min(ret,answer(S,curr+1,last));
    return ret;
}

class CuttingBitString
{
public:
	int getmin(string S);
};

int CuttingBitString::getmin(string S)
{
    memset(mem,-1,sizeof mem);
    int ans=answer(S,0,0);
    return ans==OO?-1:ans;
}
int main()
{
    int t;
    string S;

    CuttingBitString *obj;
    obj = new CuttingBitString();
    cin>>t;
    while(t--)

    {
    cin>>S;
    cout<<obj->getmin(S)<<endl;
    }
    return 0;
}
