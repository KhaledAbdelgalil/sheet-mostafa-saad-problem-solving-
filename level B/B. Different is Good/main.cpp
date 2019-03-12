#include <bits/stdc++.h>

using namespace std;
string input;
set<char>in;

int main()
{
    int n;
    cin>>n;
    cin>>input;

    for(int i=0;i<input.size();i++)
       in.insert(input[i]);

    if(input.size()>26) cout<<-1;
    else cout<<input.size()-in.size();

    return 0;
}
