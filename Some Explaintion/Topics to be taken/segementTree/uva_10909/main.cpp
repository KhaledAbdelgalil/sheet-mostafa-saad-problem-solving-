#include <bits/stdc++.h>
using namespace std;

int* fn()
{
    int n=20;
    return &n;
}

int main()
{

int *ptr=fn();
cout<<*ptr;
    return 0;
}
