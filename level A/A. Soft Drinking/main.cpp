#include<iostream>
using namespace std;



int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int toestliter=0,toestslice=0,toestsalt=0,toest=0;
    toestliter=(k*l)/nl;
    toestsalt=p/np;
    toestslice=(c*d);
    toest=min(toestliter,toestsalt);
    toest=min(toestslice,toest);
    cout<<toest/n;
}
