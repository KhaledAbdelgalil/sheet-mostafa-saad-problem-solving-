#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int n,x;
ull mem[25][151];
ull countt(int index,int sum)
{
    if(index==0)
    {
        if(sum>=x)
            return 1;
        return 0;
    }
    ull &ret=mem[index][sum];
    if(ret!=-1)return ret;
    ret=0;
    for(int j=1;j<=6;j++)
        ret+=countt(index-1,sum+j);
    return ret;
}
ull gcd(ull n, ull m) {
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
    while(cin>>n>>x)
    {
        if(n==0&&x==0)break;

        memset(mem,-1,sizeof mem);

        ull norm=countt(n,0);
        ull dem=pow(6.0,n);
        ull fact=gcd(norm,dem);
        norm/=fact;
        dem/=fact;
        if(norm==0)
            cout<<"0\n";
        else if(norm==1&&dem==1)
            cout<<"1\n";
        else
        {
            cout<<norm<<"/"<<dem<<endl;
        }
    }

    return 0;
}
