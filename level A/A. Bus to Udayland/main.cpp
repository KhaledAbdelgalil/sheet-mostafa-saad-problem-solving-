#include<iostream>
using namespace std;


int main()
{
   int n,flag=0;
   cin>>n;

  string bus[n];
  for(int i=0;i<n;i++)
  cin>>bus[i];

  for(int i=0;i<n;i++)
  {
         if(bus[i][0]=='O'&&bus[i][1]=='O')
         {
           flag=1;
           bus[i][0]=bus[i][1]='+';
           break;
         }
         else if(bus[i][3]=='O'&&bus[i][4]=='O')
         {
           flag=1;
           bus[i][3]=bus[i][4]='+';
           break;
         }
  }
    (flag==0)?cout<<"NO":cout<<"YES"  ;
    if(flag==0)return 0;

    for(int i=0;i<n;i++)
 cout<<endl<<bus[i];


