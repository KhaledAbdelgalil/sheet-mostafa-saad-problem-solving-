#include <bits/stdc++.h>

using namespace std;
string x;
int main()
{
    getline(cin,x);
    int count1=0;
    bool flag[28]={0};
    for(int i=0;i<x.size();i++)
    {


        if(x[i]>='a'&&x[i]<='z')
        {
            if(flag[(int)x[i]-97]==0)
            {
                count1++;
                flag[(int)x[i]-97]=1;
            }
        }

    }

    cout<<count1;
    return 0;
}
