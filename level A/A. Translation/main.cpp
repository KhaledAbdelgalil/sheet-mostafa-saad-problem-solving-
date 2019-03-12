#include<bits/stdc++.h>

using namespace std;

int main()
{
   string s,t;
   cin>>s>>t;

   reverse(t.begin(),t.end());
   (s==t)?cout<<"YES":cout<<"NO";
    return 0;
}
