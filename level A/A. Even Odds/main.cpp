#include <iostream>

using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    if(n%2!=0&&k==(n/2)+1) cout<<n;


    else if(k>n/2)
        {
            if(n%2==0)
             k=k-n/2;
            else k=k-n/2-1;
             cout<<k*2;
        }
    else cout<<k*2-1;

}
