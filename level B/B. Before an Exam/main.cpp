#include <bits/stdc++.h>
#define taken first
#define slack second
#define ii pair<int,int>
using namespace std;
vector<pair <int,int> >out;
int main()
{
    int d,sumTime,minTime,maxTime;
    cin>>d>>sumTime;
    int sum=0,sum_slack=0;

    for(int i=0;i<d;i++)
    {
        cin>>minTime>>maxTime;
        sum+=maxTime;
        sum_slack+=maxTime-minTime;

        out.push_back(ii(maxTime,maxTime-minTime));
    }
    if((sum<sumTime)||(sum-sum_slack>sumTime)){cout<<"NO";return 0;}
    if(sum==sumTime) {cout<<"YES"<<endl;
    for(int i=0;i<d;i++)
    {
        cout<<out[i].taken<<" ";
    }
    return 0;
    }
    int difference=sum-sumTime;
    int j=0;
    while(difference!=0)
    {
        if(difference>=out[j].slack)
        {
            difference-=out[j].slack;
            out[j].taken-=out[j].slack;
        }
        else{

            out[j].taken-=difference;
             difference=0;
        }
        j++;
    }
    cout<<"YES"<<endl;
        for(int i=0;i<d;i++)
    {
        cout<<out[i].taken<<" ";
    }
    return 0;

}
