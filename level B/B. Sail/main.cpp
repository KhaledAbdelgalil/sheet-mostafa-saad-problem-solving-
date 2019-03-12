#include <bits/stdc++.h>
using namespace std;
int t,xi,yi,xe,ye;
int t1,t2;
string m;
int main()
{
cin>>t>>xi>>yi>>xe>>ye>>m;
int diffx=xe-xi;
int diffy=ye-yi;
int right_or_left=(diffx>0)?1:0;
int up_or_down=(diffy>0)?1:0;
if(diffx==0) right_or_left=-1;
if(diffy==0) up_or_down=-1;
if(right_or_left==-1&&up_or_down==-1) {cout<<0;return 0;}

for(int i=0;i<t;i++)
{
    if(right_or_left==1&&m[i]=='E'&&diffx>0)
    {

        diffx--;
        t1=i+1;

    }
    else if(right_or_left==0&&m[i]=='W'&&diffx<0)
    {

        diffx++;
        t1=i+1;

    }
    else if(up_or_down==1&&m[i]=='N'&&diffy>0)
    {

        diffy--;
        t2=i+1;

    }
   else if(up_or_down==0&&m[i]=='S'&&diffy<0)
    {

        diffy++;
        t2=i+1;

    }
    if(diffx==0&&diffy==0) { cout<<max(t1,t2);return 0;}
}


 cout<<-1;
    return 0;
}
