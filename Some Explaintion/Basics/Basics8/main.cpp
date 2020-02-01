//getting prime numbers using sieve
#include <iostream>

using namespace std;
bool P[100]={0};//0  prime 1 not prime
//assume good intention all is prime
void Sieve()
{
    P[0]=P[1]=1;
    for(int i=2;i<100;i++)
    {
        if(P[i]) continue;//if Prime continue
        for(int j=i*i;j<100;j+=i)
            P[j]=1;
    }
}
int main()
{
    Sieve();
    for(int i=0;i<100;i++)
        if(!P[i]) cout<<i<<" ";
    cout<<endl;
    return 0;
}
