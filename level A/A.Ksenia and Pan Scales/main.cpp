#include <bits/stdc++.h>

using namespace std;
list<char> outl,outr;
string s,n;
int flag=1;
int main()
{
    cin>>s>>n;
    list<char>::iterator posl = outl.begin(),posr=outr.begin();
    for(int i = 0; i<s.size(); i++) {
    if(s[i]=='|'){flag=0; continue;}
    if(flag==1) {outl.insert(posl,s[i]);posl++;}
    else {outr.insert(posr,s[i]);posr++;}
	}
	//cout<<outr.size()<<" "<<outl.size()<<" "<<n.size()<<" "<<abs((int)outl.size()-(int)outr.size())<<endl;
	if(abs((int)outl.size()-(int)outr.size())>n.size()) {cout<<"Impossible";return 0;}
	flag=0;
	int i=0;
	while(outl.size()<outr.size())
    {
        outl.insert(posl,n[i]);
        i++;
    }
    while(outr.size()<outl.size())
    {
        outr.insert(posr,n[i]);
        posr++;
        i++;
    }
    if((n.size()-i)%2!=0) {cout<<"Impossible";return 0;}

    while(i!=n.size())
    {
        if(flag){outl.insert(posl,n[i]);posl++;}
        else {outr.insert(posr,n[i]); posr++;}

        flag=!flag;
        i++;
    }
    for(posl=outl.begin();posl!=outl.end();posl++)
        cout<<*posl;
    cout<<'|';
    for(posr=outr.begin();posr!=outr.end();posr++)
        cout<<*posr;
}
