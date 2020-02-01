//problems on topcoder:RGBstreet-MaximalProduct
#include <bits/stdc++.h>
using namespace std;
#define MAX 21
int r[MAX];
int g[MAX];
int b[MAX];
int n;
const int oo=(int)1e6;

int minCost_recursion_RGBstreet(int i,int lastColor)
{
    if(i==n) return 0;
    int ret=oo;
    if(lastColor!=0)
        ret=min(ret,r[i]+minCost_recursion_RGBstreet(i+1,0));
    if(lastColor!=1)
        ret=min(ret,g[i]+minCost_recursion_RGBstreet(i+1,1));
    if(lastColor!=2)
        ret=min(ret,b[i]+minCost_recursion_RGBstreet(i+1,2));

    return ret;
}


int mem[MAX][4];
int minCost_memorization_RGBstreet(int i,int lastColor)
{
    if(i==n) return 0;
    int &ret=mem[i][lastColor];
    if(ret!=-1) return ret;
    ret=oo;
    if(lastColor!=0)
        ret=min(ret,r[i]+minCost_recursion_RGBstreet(i+1,0));
    if(lastColor!=1)
        ret=min(ret,g[i]+minCost_recursion_RGBstreet(i+1,1));
    if(lastColor!=2)
        ret=min(ret,b[i]+minCost_recursion_RGBstreet(i+1,2));

    return ret;
}
class RGBStreet
{
public:
        int estimateCost(vector <string> houses)
        {
            for(int i=0;i<MAX;i++)
                for(int j=0;j<4;j++)
                mem[i][j]=-1;
            for(int i=0;i<houses.size();i++)
            {
                istringstream ss(houses[i]);
                ss>>r[i]>>g[i]>>b[i];
            }
            n=houses.size();
            //return minCost_recursion_RGBstreet(0,3);
            return minCost_memorization_RGBstreet(0,3);
        }
};

int maxk;
long long mem2[MAX][101];//initialize to -1
long long maxprod_recursion(int k,int rem)
{
    if(k==maxk) {
            if(rem==0) return 1;
           else return 0;
    }
    if(rem==0) return 0;//invalid case(cannot be unless end)
    long long product =0;
    for(int i=1;i<=rem;i++)
    {
        long long sol=maxprod_recursion(k+1,rem-i)*i;
        product=max(product,sol);
    }
    return product;
}

long long  max_memorize(int k,int rem)
{
    if(k==maxk) {
            if(rem==0) return 1;
           else return 0;
    }
    if(rem==0) return 0;//invalid case(cannot be unless end)
    long long &product =mem2[k][rem];
    if(product!=-1)return product;
    product=0;
    for(int i=1;i<=rem;i++)
    {
        long long sol=maxprod_recursion(k+1,rem-i)*i;
        product=max(product,sol);
    }
    return product;
}
class MaximalProduct{

public:
        long long maximalProduct(int s,int k)
        {
            maxk=k;
            for(int i=0;i<MAX;i++)
               for(int j=0;j<101;j++)
                    mem2[i][j]=-1;
            return max_memorize(0,s);
        }

};
int main()
{
    int x,y;
    MaximalProduct ss;
    cin>>x>>y;
    cout<<ss.maximalProduct(x,y);
    return 0;
}
