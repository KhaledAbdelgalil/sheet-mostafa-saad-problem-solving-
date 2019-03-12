#include <bits/stdc++.h>
#include<iostream>
using namespace std;
string s;
int main()
{
    int correct=1,counter=0;
for(int i=0;i<3;i++)
{
    getline(cin,s);

    counter=0;
    for(int j=0;j<s.size();j++)
    {
        if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')counter++;
    }

    if((i==0||i==2)&&counter!=5) correct=0;
    else if(i==1&&counter!=7) correct=0;
}
(correct==1)?cout<<"YES":cout<<"NO";
    return 0;
}
