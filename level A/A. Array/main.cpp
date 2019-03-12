#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
int n;
cin>>n;
int arr[n];
int flag=0,flag_=0;
vector<int> zeros,neg,pos;
for(int i=0;i<n;i++)
{
cin>>arr[i];

}
sort(arr,arr+n);
if(arr[n-1]>0)flag=1;
for(int i=0;i<n;i++)
{
if(arr[i]==0) zeros.push_back(0) ;
   else if(arr[i]<0&&flag_==0) {neg.push_back(arr[i]);flag_=1;}
   else if(flag==1)
   {
       if(arr[i]<0)  zeros.push_back(arr[i]);
       else pos.push_back(arr[i]);
   }
   else
   {
      if(arr[i]<0)pos.push_back(arr[i]) ;
      if(pos.size()==2) flag=1;
   }
}
cout<<neg.size()<<" "<<neg[0];

cout<<endl<<pos.size()<<" ";
for(int i=0;i<pos.size();i++)
{

cout<<pos[i] <<" "  ;
}

cout<<endl<<zeros.size()<<" ";
for(int i=0;i<zeros.size();i++)
{

cout<<zeros[i] <<" "  ;
}
            return 0;
}
