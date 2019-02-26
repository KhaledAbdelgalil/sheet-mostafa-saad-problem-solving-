#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,minn=0,maxx=0;
    cin>>n;
    int n1=n;
    while(n1>0)
    {
       if(n1>=2){ n1-=2;maxx+=2;}
        else {maxx+=n1;n1=0;}
        if(n1>=5) {n1-=5;}
        else n1=0;
    }
    n1=n;
    while(n1>0)
    {
        if(n1>=5) {n1-=5;}
        else n1=0;
        if(n1>0)
        {
            if(n1>=2)
                { n1-=2;minn+=2;}
            else {minn+=n1;n1=0;}
        }
    }
    cout<<minn<<" "<<maxx;
    return 0;
}

}
//2nd solution

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    if(n%7==0)
    cout<<2*(n/7)<<" "<<2*(n/7);
    else if(n%7==6)
    cout<<2*(n/7)+1<<" "<<2*(n+1)/7;
    else if(n%7==1)
    cout<<2*(n/7)<<" "<<2*(n/7)+1;
    else
    cout<<2*(n/7)<<" "<<2*(n/7)+2;
}
