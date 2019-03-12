#include<bits/stdc++.h>
using namespace std;

int main() {
	map<char,int>c;
	c['A']=0,c['B']=0;
	c['C']=0;
	string s;
	for (int i=0;i<3;i++){
		cin>>s;
	if (s[1]=='>')
    c[s[0]]++;
	else c[s[2]]++;
	}
	//if((c['A']==1 && c['C']==1)|| (c['B']==1 && c['C']==1)||(c['A']==1 && c['B']==1)){
	/*cout<<"Impossible"; return 0;
	}*/
	if((c['A']==2&&(c['B']==1||c['C']==1))||(c['B']==2&&(c['A']==1||c['C']==1))||(c['C']==2&&(c['A']==1||c['B']==1)))
	for (int i=0;i<3;i++)
		if(c['A']==i)cout<<'A';
		else if (c['B']==i)cout<<'B';
		else cout<<'C';
    else cout<<"Impossible";
	return 0;
}
