//if you can solve problem dp/bruteforce solve it
//methods to prove greedy::1-stay ahead
/*
steps here:http://www.cs.cornell.edu/courses/cs482/2003su/handouts/greedy_ahead.pdf
*/
/*
frog problem
http://web.stanford.edu/class/archive/cs/cs161/cs161.1138/lectures/13/Small13.pdf
*/

#include <bits/stdc++.h>
using namespace std;
//1st problem::
/*
important problem(to be solved again)(not solved yet)
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
*/

void solve_min_num_jmps()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        int curr_index=0;
        int ans=0;
        bool got=0;

        for(;curr_index<=n-1;)
        {
            if(arr[curr_index]==0) {cout<<-1<<endl;got=1;}
            if(got)break;
            int power_move=arr[curr_index];
            int maxx=-1;
            int i=curr_index;
            while(power_move--)
            {
                i++;
                if(i==n-1)
                {
                    cout<<ans+1<<endl;
                    got=1;
                }
               else if(arr[i]+i>=maxx)
                {
                    maxx=arr[i]+i;
                    curr_index=i;
                }
                if(got) break;
            }
            if(got) break;
        }

    }
}
int main()
{
    solve_min_num_jmps();
    return 0;
}
