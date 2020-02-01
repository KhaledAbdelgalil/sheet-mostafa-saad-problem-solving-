#include <bits/stdc++.h>
using namespace std;
string in[1001];
string cp[1001];
int mem_strings[1001][1001];
int M,N;
int Counting_strings(int i,int j)
{
    if(i==N||j==M) return 0;
    int &ret=mem_strings[i][j];
    if(ret!=-1) return ret;
    if(in[i]==cp[j])
        return ret=1+Counting_strings(i+1,j+1);

     return ret=max(Counting_strings(i+1,j),Counting_strings(i,j+1));
}
void solve_10100()
{
    string x;
    bool empty=false;
    int cs=1;
    while(getline(cin,x))
    {
        memset(mem_strings,-1,sizeof mem_strings);
        stringstream ss1,ss2;

        //in
        if(x.size()==0)
            empty=true;
        for(int i=0,sz=x.size();i<sz;i++)
            if(!(isalpha(x.at(i))||isdigit(x.at(i)))) x[i]=' ';
        ss1<<x;
        N=0;
        while(ss1>>x)
        {
            in[N]=x;
            N++;
        }


        //cp
        getline(cin,x);
        if(x.size()==0)
            empty=true;
        for(int i=0,sz=x.size();i<sz;i++)
            if(!(isalpha(x.at(i))||isdigit(x.at(i)))) x[i]=' ';
        ss2<<x;
        M=0;
        while(ss2>>x)
        {
            cp[M]=x;
            M++;
        }

        if(empty)  printf("%2d. Blank!\n",cs++);
        else {
            int c=Counting_strings(0,0);
            printf("%2d. Length of longest match: %d\n",cs++,c);
        }
        empty=false;
    }
}
int main()
{
    solve_10100();
    return 0;
}
