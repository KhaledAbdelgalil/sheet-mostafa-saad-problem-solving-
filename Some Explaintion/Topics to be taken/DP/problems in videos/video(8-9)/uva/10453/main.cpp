#include <bits/stdc++.h>
using namespace std;
string in;
string out;
int mem[1001][1001];
int min_add(int i,int j)
{
    if(i>=j)return 0;
    int &ret=mem[i][j];
    if(ret!=-1)return ret;

    if(in[i]==in[j])return ret=min_add(i+1,j-1);
    int c1=1+min_add(i,j-1);
    int c2=1+min_add(i+1,j);
    return ret=min(c1,c2);
}
void build_str(int i,int j,int left ,int right)
{
    if(i>=j)return;


    if(in[i]==in[j]){
            left++;
            right--;
            build_str(i+1,j-1,left,right);

            return;
    }

    int c1=1+min_add(i,j-1);
    int c2=1+min_add(i+1,j);
    int sol=min_add(i,j);
    if(sol==c1)
    {
        //cout<<"a"<<endl;
        out.insert(left,1,in[j]);
        left++;
        build_str(i,j-1,left,right);
        return;
    }
    else
    {
               // cout<<"b"<<endl;

        out.insert(right+1,1,in[i]);
        left++;
        build_str(i+1,j,left,right);
        return;
    }
}
int main()
{

    while(cin>>in)
    {
        memset(mem,-1,sizeof mem);
        min_add(0,in.size()-1);
        out=in;
        build_str(0,in.size()-1,0,in.size()-1);
        printf("%d %s\n",min_add(0,in.size()-1),out.c_str());
    }
    return 0;
}
