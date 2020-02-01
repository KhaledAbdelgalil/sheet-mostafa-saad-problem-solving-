/*direct cycle::state call itself directly int f(int n){if(n==0||n==1) return 1;
    return 2*f(n-1)+2*f(n-2)-f(n);
}
//if you need to make that recurence convert it to math
f(n)=2*f(n-1)+2*f(n-2)-f(n)----->f(n)=f(n-1)+f(n-2)

write recernce and rearrange it
*/
//mohm awy to be taken before ecpc(video 29)
//to make another choice or same choice call that a variable and that a variable and reformulate
//if recurence is
/*
f(x)=a+max(b,c+0.5f(x))
then f(x)=max(a+b,a+c+0.5f(x))
f(x)=c+a+0.5f(x)
f(x)=2a+2c
f(x)=max(a+b,2a+2c)

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
