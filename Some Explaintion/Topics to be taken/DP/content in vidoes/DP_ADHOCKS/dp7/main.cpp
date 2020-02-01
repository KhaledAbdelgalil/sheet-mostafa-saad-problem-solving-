//problem from usaco:Cow Pedigrees

#include <bits/stdc++.h>
using namespace std;
//if you you go to implement something exact think of atmost and see what is good for you


/*
 * Exact & atmost relationship
 *
 * E.g. Exact could be, How many ways to pick k balls out of n balls. Then Exact(K) = N choose K
 * 		Atmost could be, How many ways to pick maximum k balls out of n balls. Then Atmost(K) = SUM Exact(i) where i = [0-k]
 *
 *
 * 	Why important? Cause we could get one from another. Sometimes doing exact is easier/more efficint...some times reverse is true.
 *
 * 	Exact(k) = Atmost(k) - Atmost(k-1)
 * 	Atmost(k) = SUM Exact(i) where i = [0-k]
 *
 * 	SUM Exact(i) where i = [start-end] =  Atmost(end) - Atmost(start-1)
 *
 * 	Notice how having atmost could answer us exact, and range sums in O(1)!
 */
//equal to ===exact

//the problem is you have n nodes how many ways you can implement binary tree such that its height =k
//height is the number of nodes from root on longest path to leaf
//you have node so left may be of exact k-1 height right atmost k-1 right exact k-1 and left atmost k-1 left exact k-1 and right exact k-1 and remove duplicate
long long treesExactHeight(int n,int k);

long long mem1[100][100];
long long mem2[100][100];
long long mem3[100][100];

long long nwaysATmost(long long n,long long k)
{
    if(n==1) if(k==1)return 1;//only one node
    if(k==1) return 0;//we cannot go anymore

    long long &ret=mem3[n][k];
    if(ret!=-1) return ret;


    for(int t=1;t<=n-1;t++)
        ret+=nwaysATmost(t,k-1)*nwaysATmost(n-t-1,k-1),ret%=9901;

        return ret;

}
long long treesAtmost(long long n,long long k)//if writing to exact recurence no need to write to atmost recurrence
{
    if(k<=0) return 0;
    long long &ret=mem2[n][k];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=1;i<=k;i++)
        ret=(ret+treesExactHeight(n,i))%9901;
    return ret;
}
long long treesExactHeight(int n,int k)
{
    if(n==1)
        return k==1?1:0;
    if(k<0||n<0) return 0;
    long long &ret=mem1[n][k];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=1;i<=n-1;i+=2)//n always odd
    {
        long long a=treesExactHeight(n-1-i,k-1)*treesAtmost(i,k-1);
        long long b=treesAtmost(n-1-i,k-1)*treesExactHeight(i,k-1);
        long long c=treesExactHeight(n-1-i,k-1)*treesExactHeight(i,k-1);//duplication
        ret=(ret+a+b-c)%9901;
    }
    return ret;
}


int main()
{
    memset(mem1,-1,sizeof mem1);
    memset(mem2,-1,sizeof mem2);
    memset(mem3,-1,sizeof mem3);
    long long n,k;
    while(cin>>n)
    {
    cin>>k;
    cout<<treesExactHeight(n,k)<<endl;
    cout<<treesAtmost(n,k)-treesAtmost(n,k-1)<<endl;
    }

    return 0;
}
