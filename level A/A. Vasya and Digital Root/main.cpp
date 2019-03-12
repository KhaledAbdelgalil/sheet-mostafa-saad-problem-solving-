#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int k,d;
    string result="";
    cin>>k>>d;

    if((k>1 && d==0)||k==0)
        {
            cout<<"No solution";
        }
    else
        {
          result+=(char)(d+48);
         for(int i=0;i<k-1;i++)
            {
                result+='0';
            }
         cout<<result;
        }
    return 0;
}
