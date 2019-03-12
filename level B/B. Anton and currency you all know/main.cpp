#include<bits/stdc++.h>
using namespace std;
bool digitfound[10];
vector<long long>positions[10];//shyal position el digit fe rkm
int main()
{
string s;
cin>>s;
long long pos=-1;

long long first_24680=-1,first_2460=-1,first_240=-1,first_20=-1,first_0=-1,last_all=-1;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='2'||s[i]=='4'||s[i]=='6'||s[i]=='8'||s[i]=='0')
    {
        first_24680=i;
        break;
    }
}

for(int i=0;i<s.size();i++)
{
    if(s[i]=='2'||s[i]=='4'||s[i]=='6'||s[i]=='0')
    {
        first_2460=i;
        break;
    }
}

for(int i=0;i<s.size();i++)
{
    if(s[i]=='2'||s[i]=='4'||s[i]=='0')
    {
        first_240=i;
        break;
    }
}
for(int i=0;i<s.size();i++)
{
    if(s[i]=='2'||s[i]=='0')
    {
        first_20=i;
        break;
    }
}
for(int i=0;i<s.size();i++)
{
    if(s[i]=='0')
    {
        first_0=i;
        break;
    }
}

for(int i=s.size();i>=0;i--)
{
    if(s[i]=='2'||s[i]=='4'||s[i]=='6'||s[i]=='8')
    {
        last_all=i;
        break;
    }
}

if(first_24680==-1&&first_2460==-1&&first_240==-1&&first_20==-1&&first_0==-1){cout<<-1; return 0;}
if(s[s.size()-1]=='9'){pos=first_24680;}
else if(s[s.size()-1]=='7'){if(first_2460!=-1)pos=first_2460;else pos=last_all;}
else if(s[s.size()-1]=='5'){if(first_240!=-1)pos=first_240;else pos=last_all;}
else if(s[s.size()-1]=='3'){if(first_20!=-1)pos=first_20;else pos=last_all;}
else if(s[s.size()-1]=='1'){if(first_0!=-1)pos=first_0;else pos=last_all;}
char temp=s[s.size()-1];
s[s.size()-1]=s[pos];
s[pos]=temp;

cout<<s;
}

/*for(int i=0;i<s.size();i++)
{
    if(s[i]=='2')
    {
        digitfound[2]=1;
        positions[2].push_back(i);
    }
      else if(s[i]=='4')
        {
        digitfound[4]=1;
        positions[4].push_back(i);
    }
        else if(s[i]=='6')
            {
        digitfound[6]=1;
        positions[6].push_back(i);
    }
        else if(s[i]=='8')
    {
        digitfound[8]=1;
        positions[8].push_back(i);
    }
}
if(digitfound[2]==0&&digitfound[4]==0&&digitfound[6]==0&&digitfound[8]==0){cout<<-1;return 0;}

if(s[s.size()-1]=='3')
{
    if(digitfound[2])
}
/*if(digitfound[2]==1){if(s[s.size()-1]>='3') pos=positions[2][0];
else pos=positions[2][positions[2].size()-1];
}
else if(digitfound[4]==1){if(s[s.size()-1]>='5') pos=positions[4][0];
else pos=positions[4][positions[4].size()-1];
}
else if(digitfound[6]==1){if(s[s.size()-1]>='7') pos=positions[6][0];
else pos=positions[6][positions[6].size()-1];
}
else {if(s[s.size()-1]=='9') pos=positions[8][0];
else pos=positions[8][positions[8].size()-1];
}
if(s[s.size()-1]==9)
{

}*/
