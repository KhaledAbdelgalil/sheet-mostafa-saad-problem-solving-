//cyclic recurence :: your state go to subproblem then return to same state
//like :: maze call someone who calls someone who calls you
//general technique::depth trick
//you know that recursion circulates but put a depth parameter
//if you put depth 1000 to your subproblem so this subproblem put depth<1000 in order not to circulate to parent
//if depth=0 return invalid value but if it's not return so depth trick is good if you know that depth between start and base case is not>some depth
//we write code circulates and we are sure that path from state to all states doesn't exceed some known depth::->depth trick

//if your heart tell you that this problem solved by depth trick but you don't know what is the depth calculate order of code without depth then put depth with max depth you can make
#include <bits/stdc++.h>
using namespace std;
int target;
const int OO=1e9;
int rev_int(int a)
{
    ostringstream oss;
    oss<<a;
    string str=oss.str();
    reverse(str.begin(),str.end());
    istringstream iss(str);
    iss>>a;
    return a;
}
map<pair<int,int>,int>mp;
int min_steps(int a,int depth)
{
    if(a==target) return 0;
    if(depth<0) return OO;//invalid state because of cycle
    pair<int,int>p=make_pair(a,depth);
    if(mp.count(p))
        return mp[p];
    return mp[p]=1+min(min_steps(a/10,depth-1),min_steps(rev_int(a),depth-1));
}
class TheNumberGameDiv2
{
public:
     int minimumMoves(int A, int B)
     {
        target=B;
        int ret=min_steps(A,74);
        if(ret>=OO) ret=-1;
        return ret;
     }
};

int main()
{
    int a,b;
    cin>>a>>b;
    TheNumberGameDiv2* t;
    cout<<t->minimumMoves(a,b);
    return 0;
}
