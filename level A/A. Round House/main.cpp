#include<iostream>
#include<math.h>
using namespace std;



int main()
{
   int n,a,b;
   cin>>n>>a>>b;
   b=b%n;
   if(b<0) b=b+n;
   n=a+b>n?(a+b)%n:(a+b);
    cout<<n;

return 0;
}
