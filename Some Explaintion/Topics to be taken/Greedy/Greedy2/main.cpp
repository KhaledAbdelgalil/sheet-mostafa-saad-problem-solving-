//greedy:local choice in every sub-problem
//to prove greedy:
//1-make a local choice 2-solve subproblem
//you say I am sure that this a solution
//1-greedy choice property:multiple solutions/only one solution 2-optimal substructure
//to prove that this choice is a choice assume thas S is optimal solution then try replace S with S' contain choice and prove it's good
//2-optimal substructure property::it relates optimality of subproblems to problem
//an optimal solution contains optimal solutions to sub problems (remmeber shortest path)(longest path doesn't stasify this property

//prove by contraduction and induction

//have this structure for greedy in your brain:
/*
1)sort items based on some criteria
2)for every item
-canBeMyLocalOptimumSolution(item)
-add to global optimum solution
/*to prove greedy:prove that local choice is a part of solution
                  prove that solution contains solutions to subproblems


*/

//problems::codeforces:CF260-D2-C(Balls and Boxes)(think greedy as chosen box at first is the min now)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  ll arr[100005];
  ll chosen_first=(int)(1e9)+2;
  ll add_balls;
void solve_Balls_Boxes()
{

    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        chosen_first=min(arr[i],chosen_first);
    }
    for(int i=0;i<n;i++)arr[i]-=chosen_first;
    x--;
    while(x>=0)
    {
        if(arr[x]==0)
        {
            arr[x]+=chosen_first*n+add_balls;
            break;
        }
        arr[x]--;
        add_balls++;
        x--;
        if(x==-1)x=n-1;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    solve_Balls_Boxes();
    return 0;
}
