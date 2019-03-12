#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   string in1,in2;
   int sum=0;
   int a[26]={0}, b[26]={0};
   bool a1[26]={0},b1[26]={0};
   cin>>in1>>in2;
   for(int i=0;i<in1.size();i++)
   {
       a[(int)in1[i]-97]++;
         a1[(int)in1[i]-97]=1;
   }
   for(int i=0;i<in2.size();i++)
   {
       b[(int)in2[i]-97]++;
        b1[(int)in2[i]-97]=1;;
   }
   for(int i=0;i<26;i++)
   {
       if(a1[i]==0&&b1[i]==1)
       {
           cout<<"-1";
           return 0;
       }
       else if(a1[i]==1&&b1[i]==1)
       {
           if(a[i]>=b[i]) sum+=b[i];
           else sum+=a[i];
       }
   }
   cout<<sum;
    return 0;
}
