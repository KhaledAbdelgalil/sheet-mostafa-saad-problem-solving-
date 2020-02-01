//general range style
//you have a big range take it all and move into internal
//uva problem:(10739)
#include <bits/stdc++.h>
using namespace std;
string in;
int mem[1001][1001];
int operations(int i,int j)
{
    if(i>=j)return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    int ret=operations(i+1,j-1)+(in[i]!=in[j]);
    ret=min(ret,operations(i+1,j)+1);
    ret=min(ret,operations(i,j-1)+1);
    return mem[i][j]=ret;

}
//solve stack-overflow problem
typedef struct state{
int i,j;
bool isProcessed;
state(int x,int y){isProcessed=0;i=x;j=y;}
}state;
int operations2(int i,int j)
{
    stack<state>st;
    state curr=state(i,j);
    st.push(curr);
    while(!st.empty())
    {
        curr=st.top();
        st.pop();
         i=curr.i;
         j=curr.j;
        if(mem[i][j]==-1)
        {
            if(i>=j)
                mem[i][j]=0;
            else if(!curr.isProcessed)
            {
                curr.isProcessed=1;
                st.push(curr);
                st.push(state(i+1,j-1));
                st.push(state(i,j-1));
                st.push(state(i+1,j));
            }
            else
                mem[i][j]=min(mem[i+1][j-1]+(in[i]!=in[j]),min(mem[i+1][j]+1,mem[i][j-1]+1));
        }
    }
    return mem[curr.i][curr.j];
}
//another solution in stack-overflow
//you start recursion from top to bottom
//so make a lop call from bottom to top many ones so when calling it you find solution in memory
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>in;
        memset(mem,-1,sizeof mem);
        //cout<<"Case "<<i<<": "<<operations(0,in.size()-1)<<endl;
        cout<<"Case "<<i<<": "<<operations2(0,in.size()-1)<<endl;

    }
    return 0;
}
