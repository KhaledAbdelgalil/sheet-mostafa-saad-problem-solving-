#include <bits/stdc++.h>

using namespace std;
int n;
string s;

int main()
{
int flag_black;
int output[59]={0};//3dd el black in each group
int count_groups=0;
int count_black_eachGroup=0;
cin>>n>>s;
if(s[0]=='W')
    flag_black=0;
else
{
     flag_black=1;
     count_black_eachGroup++;
     if(s.size()==1)
     {
         output[count_groups]=count_black_eachGroup;
         count_groups++;
     }
}
for(int i=1;i<n;i++)
{
  if(i==n-1&&s[i]=='B')
        {
            count_black_eachGroup++;
            output[count_groups]=count_black_eachGroup;
            count_groups++;
        }
    //rai7 l abyad w gy mn aswad
    else if(flag_black==1&&s[i]=='W')
    {
        flag_black=0;
        //kda 5lst el group
        output[count_groups]=count_black_eachGroup;
        count_black_eachGroup=0;//ghz lle b3dha
        count_groups++;
    }
    else if(s[i]=='B')
    {
        flag_black=1;
        count_black_eachGroup++;
    }
}
cout<<count_groups<<endl;
for(int i=0;i<count_groups;i++)
    cout<<output[i]<<" ";

    return 0;
}
