#include<bits/stdc++.h>
using namespace std;


int holes[1000000];//0 not a hole 1 a hole
int main()
{
    int n,m,k,f,l;//f,l is dummy to take input
    int notInHole=1;
    scanf("%d %d %d",&n,&m,&k);//scanf asr3 mn cout w lw 7ltha b cout time limit excedded
    for(int i=0;i<m;i++)
    {
        scanf("%d",&f);
        holes[f]=1;//f is hole
    }
    int posBone=1;
    for(int i=0;i<k;i++)
    {
        scanf("%d %d",&f,&l);
        if(holes[posBone]) notInHole=0;//afrd bone fe bdya abl mt5osh as2l w ab2a 7ot el condition da fe a5er sa3at shr7 pixels w a2olhom meen ygbha w y5od choclate

        if(notInHole)
        {
            if(f==posBone) posBone=l;
            else if(l==posBone) posBone=f;

        }
    }
    cout<<posBone;
}
