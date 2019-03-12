#include<bits/stdc++.h>

using namespace std;

int main()
{
    string in,out="";
    int sum1=0,sum2=0,sum3=0;
    cin>>in;
    for(int i=0;i<in.size();i++)
    {
        if(in[i]=='+') continue;
        if(in[i]=='1') sum1++;
        else if(in[i]=='2') sum2++;
        else sum3++;
    }
    if(sum1>0){out+='1';sum1--;}
    else if(sum2>0){out+='2';sum2--;}
    else if(sum3>0){out+='3';sum3--;}
    for(int i=0;i<sum1;i++)
        out+="+1";
    for(int i=0;i<sum2;i++)
        out+="+2";
    for(int i=0;i<sum3;i++)
        out+="+3";
    cout<<out;
    return 0;
}
