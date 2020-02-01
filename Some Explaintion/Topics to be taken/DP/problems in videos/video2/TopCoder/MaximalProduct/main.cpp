#include <bits/stdc++.h>
using namespace std;

long long maxK;
long long mem[21][101];
long long max_prod(int k,int rem)
{
    if(k==maxK)
    {
        return rem==0;
    }
    if(rem==0) return 0;//invalid state
    long long &ret=mem[k][rem];
    if(ret!=-1)return ret;

    ret=0;
    for(int i=1;i<=rem;i++)
    {
        ret=max(ret,i*max_prod(k+1,rem-i));
    }
    return ret;
}
class MaximalProduct{

public:
 long long maximalProduct(int s, int k)
 {
     memset(mem,-1,sizeof mem);
     maxK=k;
     return max_prod(0,s);
 }


};
int main()
{
    int s,k;
    cin>>s>>k;
    MaximalProduct* ss=new MaximalProduct();
    cout<<ss->maximalProduct(s,k);
    return 0;
}
