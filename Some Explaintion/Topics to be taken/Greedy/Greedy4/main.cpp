//2nd method to prove :: Max Lateness Problem(exchange based on iversion swap)
//solved-problem::Job Sequencing Problem(https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0)
#include <bits/stdc++.h>
using namespace std;
struct jobs{
int p;
int d;
int id;
}job[101];
bool slots[101];
bool cmp(const jobs &a,const jobs &b)
{
    return a.p>b.p;
}
int main()
{

    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>job[i].id>>job[i].d>>job[i].p;
        sort(job,job+n,cmp);
        int elapsed_time=0;
        int ans=0;
        int profit=0;
        for(int i=0;i<n;i++)
            slots[i]=true;
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,job[i].d)-1;j>=0;j--)
            {
                if(slots[j])
                {
                    ans++;
                    profit+=job[i].p;
                    slots[j]=false;
                    break;
                }
            }
        }
        cout<<ans<<" "<<profit<<endl;
    }


    return 0;
}
