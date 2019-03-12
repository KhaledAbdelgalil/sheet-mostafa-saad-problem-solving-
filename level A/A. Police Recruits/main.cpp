#include<iostream>
using namespace std;
int polices=0;
int events,out=0;


int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {

       cin>>events;
       if(events==-1){
                  if(polices==0)  out++;
                  else polices--;
       }
       else polices+=events;

   }

       cout<<out;
}
