#include <bits/stdc++.h>

using namespace std;
int n;
int libyear[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int nonlibyear[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int year)
{
    return (((year%4==0)&& (year%100!=0))||year%400==0);
}
int main()
{
    cin>>n;
    int d1,m1,y1,c1,d2,m2,y2,c2;
   unsigned long long sum=0;
   unsigned long long countt=0;

    while(n!=0)
    {
        sum=0;
        countt=0;
        cin>>d1>>m1>>y1>>c1;
        for(int i=1;i<n;i++)
        {
            cin>>d2>>m2>>y2>>c2;
            if(y1==y2)
            {
                if(m1==m2)
                {
                    if(d2-d1==1)
                    {
                        countt++;
                        sum+=c2-c1;
                    }
                }
                else
                {
                    if(m2-m1==1)
                    {
                        if(isleap(y1))
                        {
                            if(libyear[m1]==d1&&d2==1){
                                countt++;
                                sum+=c2-c1;
                            }
                        }
                        else
                        {
                            if(nonlibyear[m1]==d1&&d2==1){
                                countt++;
                                sum+=c2-c1;
                            }
                        }

                    }
                }
            }
            else if(y2-y1==1)
            {
                if(m1==12&&m2==1)
                {
                    if(d1==31&&d2==1)
                        {
                                countt++;
                                sum+=c2-c1;
                        }
                }
            }
            d1=d2;
            m1=m2;
            y1=y2;
            c1=c2;
        }
            cout<<countt<<" "<<sum;
        cin>>n;
        if(n!=0)cout<<endl;
    }
    return 0;
}
