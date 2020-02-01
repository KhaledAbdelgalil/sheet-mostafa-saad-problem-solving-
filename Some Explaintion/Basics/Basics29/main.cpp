//secondByte and Headers

#include <bits/stdc++.h>
#include "MyMathLib.h"
using namespace std;

char secondByte()
{
    int val=770;//11 0000 0010
    char ch=  *(((char*)&val)+1);// result depends on architecture little endian or big endian

    return ch;
}
int main()
{
    //cout<<(int)secondByte();
    cout<<mylib::fact(5);
    return 0;
}
