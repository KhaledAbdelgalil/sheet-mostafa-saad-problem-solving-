#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,i;
	string s="ROYGBIV";
cin>>n;
for (i=7;i<n;i++)
	s+=s[i-4];
cout<<s;

}
