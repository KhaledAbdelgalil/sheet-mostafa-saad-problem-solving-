#include <bits/stdc++.h>
using namespace std;
//dp:consider all choices
//greedy:consider all choices but chooses one(greedy choice) to continue with
//greedy and dp ::interconnceted with eachother
//greedy based on intuitions
//in competition:think based on intuitions try to prove if not try this solution w 5alas
//local optimum choice give global optimum choice(not always)
//1st problem:activity selection
/*Let the given set of activities be S = {1, 2, 3, ..n} and
activities be sorted by finish time. The greedy choice is to always pick activity 1. How come the activity 1
 always provides one of the optimal solutions.
 We can prove it by showing that if there is another solution B with the first activity other than 1,
 then there is also a solution A of the same size with activity 1 as the first activity.
 Let the first activity selected by B be k, then there always exist A = {B – {k}} U {1}.
 (Note that the activities in B are independent and k has smallest finishing time among all.
  Since k is not 1, finish(k) >= finish(1))
  */
//link:https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
struct meeting{
    int s;
    int f;
    int index;
}m[1000];
bool cmp(const meeting& a,const meeting &b)
{
    return a.f<b.f;
}
void solve_1stProblem()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            {
                cin>>m[i].s;
                m[i].index=i+1;
            }
        for(int i=0;i<n;i++)
            cin>>m[i].f;
        sort(m,m+n,cmp);

        int selected=0;
        cout<<m[selected].index<<" ";
        for(int i=1;i<n;i++)
        {
            if(m[i].s>=m[selected].f)//no overlap
            {
                cout<<m[i].index<<" ";
                selected=i;
            }
        }
        cout<<endl;
    }
}

//2-problem two:fractional knapsack
struct house{
    double v;
    double w;
    double v2;//v/unit of w
}h[100];

bool cmp2(const house& a,const house &b)
{
    return (a.v2)>(b.v2);
}
void solve_2ndProblem()
{
    int t,n;
    double W;
    cin>>t;
    while(t--)
    {
        cin>>n>>W;
        double ans=0;
        for(int i=0;i<n;i++)
            {
                cin>>h[i].v>>h[i].w;
                h[i].v2=(h[i].v)/(h[i].w);
            }
        sort(h,h+n,cmp2);

            for(int i=0;i<n&&W>0;i++)
            {
                if(W>h[i].w)
                {
                    ans+=h[i].v;
                    W-=h[i].w;
                }
                else
                {
                   ans+=h[i].v2*W;
                   W=0;
                }
            }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
}
int main()
{
    //solve_1stProblem();
    solve_2ndProblem();
    return 0;
}
