//11008 - Antimatter Ray Clearcutting problem uva
#include <bits/stdc++.h>
using namespace std;
int n,m;
int t;
int mem[(1<<16)+1];
int X[17],Y[17];
int treeProcessed_masks[17][17];//array of masks
const int OO=1e9;
int count_bits(int mask)
{
    int res=0;
    while(mask)
    {
        mask&=(mask-1);
        res++;
    }
    return res;
}

int solution(int mask)
{
    if(n-count_bits(mask)>=m) return 0;//enough killed trees;
    int &ret=mem[mask];
    if(ret!=-1)
        return ret;
    vector<int>v;
    for(int i=0;i<n;i++)
        if(mask&(1<<i))//trees alive
            v.push_back(i);
            ret=OO;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
            ret=min(ret,1+solution(mask&treeProcessed_masks[v[i]][v[j]]));
    }
    if(ret==OO) ret=1;//only one tree
    return ret;
}
//choose 2 trees and see what other trees are killed
void processing()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                int tempMask=(1<<n)-1;
                tempMask&=~(1<<i);
                tempMask&=~(1<<j);
                for(int k=0;k<n;k++)
                {
                    if(k!=i&&k!=j)
                    {
                        //from geometry dot product to determine three points on same line
                        int x1=X[j]-X[i];
                        int y1=Y[j]-Y[i];
                        int x2=X[k]-X[i];
                        int y2=Y[k]-Y[i];
                        if(x1*y2-x2*y1==0)
                            tempMask&=~(1<<k);
                    }
                }
                treeProcessed_masks[i][j]=tempMask;
            }
        }
    }
}
int main()
{
    cin>>t;
    int k=1;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>X[i]>>Y[i];
        processing();
        memset(mem,-1,sizeof mem);
        printf("Case #%d:\n%d\n",k++,solution((1<<n)-1));
        if(t) puts("");
    }
    return 0;
}
