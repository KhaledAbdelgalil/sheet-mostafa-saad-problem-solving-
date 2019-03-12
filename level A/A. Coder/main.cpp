#include<iostream>
using namespace std;


int main(void)
{
    int n,out=0,flag_order=0;
    cin>>n;
    out=n%2==0?(n*n)/2:((n*n)/2)+1;
   cout<<out;
   cout<<endl;
    for (int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
             if(flag_order==0)
      {
      cout<<'C';
      flag_order=1;
      out++;
      }
      else
      {
      cout<<'.';
      flag_order=0;
      }
        }
        cout<<endl;
        if(n%2==0)
        flag_order=!flag_order;

    }

return 0;
}
