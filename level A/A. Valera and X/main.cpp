#include<iostream>
using namespace std;
 char x,y,z;
 int n,corr=1;
int main()
{
             cin>>n;
       for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                      cin>>z;
                  if(i==0&&j==0)
                  x=z;
                  else if(i==0&&j==1)
                  y=z;
                  else
                  {
                    if(i==j||i+j+1==n)
                    {if(z!=x||z==y)corr=0;}
                    else{if(z!=y||z==x)corr=0;}
                  }

                }

            }
            (corr==1&&x!=y)?cout<<"YES":cout<<"NO";

}
