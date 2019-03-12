#include <bits/stdc++.h>

using namespace std;

int main()
{

int vp,vd,t,f,c,out=0;
double dp=0;
cin>>vp>>vd>>t>>f>>c;
dp=t*vp;
if(vp>=vd||dp>=c){cout<<0; return 0;}

while(1)
{


   dp+=dp/(vd-vp)*vp;//a7sb hyt2blo feen el mo3dala gy mn vd*t=d+vp*t w hat el time  w ana kda swat el position elle 3ndo hyt2blo feeh
if(dp>=c){cout<<out; return 0;}//lw wslt el castle tmam
out++;//lw l2 army wahda
dp+=dp/vd*vp+f*vp;//w roo7 b2a agry fe w2t elle hyrg3 feeh w y7ot el haga fe cave w yzbtha
}
cout<<out;
}
