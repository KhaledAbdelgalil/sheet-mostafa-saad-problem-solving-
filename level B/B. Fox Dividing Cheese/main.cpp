#include <bits/stdc++.h>
int a,b,a2=0,a3=0,a5=0,b2=0,b3=0,b5=0;

using namespace std;

int main()
{
    cin>>a>>b;

    while(a%2==0){a=a/2;a2++;}
    while(b%2==0){b=b/2;b2++;}

    while(a%3==0){a=a/3;a3++;}
    while(b%3==0){b=b/3;b3++;}

    while(a%5==0){a=a/5;a5++;}
    while(b%5==0){b=b/5;b5++;}


   (a==b)?cout<<abs(a2-b2)+abs(a3-b3)+abs(a5-b5):cout<<-1;
    return 0;
}
