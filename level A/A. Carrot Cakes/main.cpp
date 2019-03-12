#include <bits/stdc++.h>
using namespace std;

int n,t,k,l,out;
int main()
{
int t1=0;
 cin>>n>>t>>k>>l;
 t1=t*ceil((float)n/k);
 if(t1-l>t)cout<<"YES";
 else cout<<"NO";
return 0;
}
