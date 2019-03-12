#include <bits/stdc++.h>
#include<iostream>
using namespace std;
string s;
int n;
int main()
{
    int correct=1,counter_left=0,counter_right=0;
    cin>>n;
    cin.get();
    getline(cin,s);


    for(int j=0;j<s.size();j++)
    {
        if(s[j]!='4'&&s[j]!='7')correct=0;
        if(j<s.size()/2) counter_left+=int(s[j]-'0');
        else counter_right+=int(s[j]-'0');
    }


(correct==1&&counter_right==counter_left)?cout<<"YES":cout<<"NO";
cout<<endl;
    return 0;
}
