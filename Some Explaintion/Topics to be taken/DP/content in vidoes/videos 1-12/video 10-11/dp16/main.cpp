//masking with dp:state is a vector of boolean
//problem uva:10651 - Pebble Solitaire
//dp is brute-force with memorization

#include <bits/stdc++.h>
using namespace std;
typedef bitset<12> MASK;
int mem[1<<12];//2^12 different state
int solve(MASK mask)
{
    int &ret=mem[mask.to_ulong()];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<10;i++)
    {
        if(mask[i]==1&&mask[i+1]==1&&mask[i+2]==0)
            {
                mask[i]=mask[i+1]=0;
                mask[i+2]=1;
                ret=max(ret,1+solve(mask));
                mask[i]=mask[i+1]=1;
                mask[i+2]=0;
            }
        if(mask[i]==0&&mask[i+1]==1&&mask[i+2]==1)
            {
                mask[i+1]=mask[i+2]=0;
                mask[i]=1;
                ret=max(ret,1+solve(mask));
                mask[i+1]=mask[i+2]=1;
                mask[i]=0;
            }
    }
    return ret;
}
int main()
{

    int t;
    char c;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        MASK mask;
        int cnt=0;
        for(int i=0;i<12;i++)
        {
            cin>>c;
            if(c=='o')
            {
                mask[i]=1;
                cnt++;
            }
            else
                mask[i]=0;
        }
        cout<<cnt-solve(mask)<<endl;
    }
    return 0;
}
