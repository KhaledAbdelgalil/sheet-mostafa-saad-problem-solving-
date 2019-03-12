#include <bits/stdc++.h>

using namespace std;
string input;
int main()
{
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    cin>>input;
    int calories=0;
    for(int i=0;i<input.size();i++)
    {
       switch(input[i])
       {
           case '1': calories+=a1;
                     break;
           case '2': calories+=a2;
                     break;
           case '3': calories+=a3;
                     break;
           case '4': calories+=a4;
                     break;
       }
    }
   cout<<calories;
    return 0;
}
