//max or min:you have a number of choices and you choose this min or max
//counting:you count these choices
//uva problem:10617 - Again Palindrome
//left now:table method and third method in video 8 in dp playlist
#include <bits/stdc++.h>
using namespace std;
string str;
long long mem[61][61];
long long sol1(int i,int j)
{
    if(i==j) return 1;
    else if(i+1==j) return 2+(str[i]==str[j]);
    long long &ret=mem[i][j];
    if(ret!=-1)return ret;
    ret=0;
    if(str[i]==str[j])
        ret+=sol1(i+1,j-1)+1;
    ret+=sol1(i+1,j);
    ret+=sol1(i,j-1);
    ret-=sol1(i+1,j-1);
    return ret;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>str;
        memset(mem,-1,sizeof mem);
        cout<<sol1(0,str.size()-1)<<endl;
    }
    return 0;
}
