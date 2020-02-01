//continue on last tutorial to solve square problem using historgram(left for now)
//first of all:: problem on historgram::https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
#include <bits/stdc++.h>
using namespace std;
void sol_hist()
{

  int t;
  cin>>t;
  while(t--)
  {
        int n;
        cin>>n;
        vector<long long>hist(n+1);
        stack< pair<int,long long> >st;
        for(int i=0;i<n;i++)
            {
                cin>>hist[i];
            }
            long long mx=0;
            hist[n++]=-1;//to force to finish process assume 2 4 6 and remove that line
        for(int i=0;i<n;i++)
        {
            pair<int,long long>p=make_pair(i,hist[i]);
            while(!st.empty()&&st.top().second>p.second)
            {
                long long cmp=(i-st.top().first)*st.top().second;
                mx=max(mx,cmp);
               p.first= st.top().first;
                st.pop();

            }
            st.push(p);
        }
        while(!st.empty())
        {
             pair<int,long long>p=st.top();
             st.pop();
        }
        cout<<mx<<endl;
  }


}


int hist_max(int n,vector<int>hist)
{
        stack< pair<int,int> >st;

            long long mx=0;
            hist[n++]=-1;//to force to finish process assume 2 4 6 and remove that line
        for(int i=0;i<n;i++)
        {
            pair<int,long long>p=make_pair(i,hist[i]);
            while(!st.empty()&&st.top().second>p.second)
            {
                long long cmp=(i-st.top().first)*st.top().second;
                mx=max(mx,cmp);
               p.first= st.top().first;
                st.pop();

            }
            st.push(p);
        }
        while(!st.empty())
        {
             pair<int,int>p=st.top();
             st.pop();
        }
    return mx;
}
int A[50][50];

int rows,cols;
//rectangle or square
void solve_square_using_hist()
{
   int t;
    cin>>t;
    while(t--)
    {
        int mx=0;
        cin>>rows>>cols;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                cin>>A[i][j];
        cout<<endl;
        for(int i=rows-1;i>=0;i--)
        {
            //build histogram
            vector<int>hist(cols+1,0);
            for(int j=0;j<cols;j++)
            for(int k=i;k>=0;k--)
            {
                if(A[k][j]==1)
                    hist[j]+=A[k][j];
                else break;
            }
            for(int f=0;f<cols;f++)
                cout<<hist[f]<<" ";
            cout<<endl<<endl;

            //call fn
            cout<<hist_max(cols,hist)<<endl;
               mx=max(mx, hist_max(cols,hist));
            //maximize on all calls
        }
        cout<<mx<<endl;
    }

}
int main()
{
    //sol_hist();
    solve_square_using_hist();
    return 0;
}
