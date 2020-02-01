#include <bits/stdc++.h>
using namespace std;
int N;
vector<int>nums;
vector<int>L;
 /*void LIS_sol(vector<int>&DP)
 {
     DP[0]=1;
     for(int i=1;i<N;i++)
     {
         DP[i]=1;
         for(int j=0;j<i;j++)
            if(nums[j]<nums[i]&&DP[i]<DP[j]+1)
                DP[i]=DP[j]+1;
     }
 }
*/
void LIS_sol(vector<int>& length)
{
    L.clear();

    for (int i = 0; i < N; ++i)
    {
        const int num = nums[i];

        // Change to upper_bound for not strictly increasing
        int pos = lower_bound(L.begin(), L.end(), num) - L.begin();
        if (pos == L.size())
        {
            cout<<"here i="<<i;
            L.push_back(num);
        }
        else
        {
            L[pos] = num;
        }

        length[i] = pos + 1;
    }
}
int main()
{

    vector<int>LIS;
    vector<int>LDS;
    while(cin>>N)
    {
        if(cin.eof())break;
        LIS.resize(N);
        LDS.resize(N);
        nums.resize(N);
        for(int i=0;i<N;i++)
            cin>>nums[i];

        LIS_sol(LIS);
        reverse(nums.begin(),nums.end());
        LIS_sol(LDS);
        int sol=-1;
        for(int i=0;i<N;i++)
            sol=max(sol,2*min(LIS[i],LDS[N-1-i])-1);

        cout<<sol<<endl;
    }
    return 0;
}
