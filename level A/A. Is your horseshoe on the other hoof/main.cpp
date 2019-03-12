#include<iostream>
using namespace std;


int main()
{
  int s1,s2,s3,s4;
  cin>>s1>>s2>>s3>>s4;
  int sum=0;
  if(s1==s2) sum++;
  else if(s1==s3) sum++;
  else if(s1==s4) sum++;
  if(s2==s3) sum++;
  else if(s2==s4) sum++;
  if(s3==s4) sum++;


  cout<<sum;



}
