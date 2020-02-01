//problems on codeforces::166A-161A-279B-271B
//spoj::AGGRCOW - Aggressive cows

#include <bits/stdc++.h>
using namespace std;
struct team
{
    int problems;
    int penaltytime;
};

bool cmp(const team& left, const team& right)
{
    return left.problems > right.problems
        || (left.problems == right.problems && left.penaltytime < right.penaltytime);
}

//here concept first match and last match
void solve_166A()
{
    int n, k;
    team t[50];
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i].problems >> t[i].penaltytime;
    }
    sort(t, t + n, cmp);
    k -= 1;
    int l(k), r(k);
    while (l > 0 && t[l-1].problems == t[k].problems && t[l-1].penaltytime == t[k].penaltytime)
    {
        l -= 1;
    }
    while (r + 1 < n && t[r+1].problems == t[k].problems && t[r+1].penaltytime == t[k].penaltytime)
    {
        r += 1;
    }
    cout << r - l + 1 << endl;
}

//concept matching
void solve_161A()
{
    int n,m,x,y;
    int soldiers[100001], vests[100001];

    cin>>n>>m>>x>>y;
    for(int i=0;i<n;i++)
        cin>>soldiers[i];
    for(int i=0;i<m;i++)
        cin>>vests[i];
    int countt=0;
    for(int i=0,j=0;i<n&&j<m;)
    {
        if(soldiers[i]-x>vests[j])
        {
            j++;//this vest can't be taken for anyone
        }
        else if(soldiers[i]+y<vests[j])
        {
            i++;//this soldier will not find a vest match
        }
        else
        {

            soldiers[countt]=++i;
            vests[countt]=++j;
            countt++;
        }
    }
    cout<<countt<<endl;
    for(int i=0;i<countt;i++)
        cout<<soldiers[i]<<" "<<vests[i]<<endl;
}



//search problem for max(2 pointers technique)/(also accumulative sum)

void solve_279B()
{
    int n,t;
    cin>>n>>t;
    int arr[n],arr_sum[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0) arr_sum[i]=arr[i];
        else arr_sum[i]=arr[i]+arr_sum[i-1];
    }
    int sum=0;
    int maxx=-1;


    for(int i=0;i<n;i++)
    {

        sum=arr_sum[i];//take from first till i
         if(sum<=t)
                maxx=max(maxx,1+i);
        for(int j=i+1;j<n;j++)
        {
                sum=arr_sum[j]-arr_sum[i];
                if(sum<=t)//take subrange
                    maxx=max(maxx,j-i);

        }

    }
    cout<<maxx;
}

void solve_279B_()
{
    int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    int maxx=-1;
    int j=0;
    for(;j<n&&sum+arr[j]<=t;)
    {
        sum+=arr[j++];
    }
    maxx=j;//biggest sequence from begining
    for(int i=0;i<n;i++)
    {
        //try not taking first book of sequence
        sum-=arr[i];
        for(;j<n&&sum+arr[j]<=t;)
        {
            sum+=arr[j++];
        }
        if(j-i-1>maxx) maxx=j-i-1;
        if(j==n) break;
    }
    cout<<maxx;
}


//problem is important
const int M=100100;
bool primes[M];
void seive()
{
    primes[0]=primes[1]=false;
    fill(primes+2,primes+M,true);
    for(int i=2;i*i<M;i++)
    {
        if(primes[i])
        {
            for(int j=i+i;j<M;j+=i)
                primes[j]=false;
        }
    }
}
void solve271B()
{
    int n,m;
    cin>>n>>m;
    int a,cols[m],rows[n];
    fill(cols,cols+m,0);
    fill(rows,rows+n,0);

    seive();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            int x=a;
            while(!primes[x])
            {
                x++;
            }
            rows[i]+=x-a;
            cols[j]+=x-a;
        }
    }
    int minn1=*min_element(rows,rows+n);
    int minn2=*min_element(cols,cols+m);
    cout<<min(minn1,minn2);

}
//binary search::very important:AGGRCOW - Aggressive cows
int n,c;
bool can(int dis,int arr[])
{
    int cnt=1;
    int curr_pos=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-curr_pos>=dis)
        {
            curr_pos=arr[i];
            cnt++;
            if(cnt>=c) return 1;
        }
    }
    return 0;
}
void solve_spoj_cows()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int lw=0;
        int hg=1000000;
        while(hg-1>lw)
        {
            int mid=(lw+hg)/2;
            if(can(mid,arr)) lw=mid;
            else hg=mid-1;
        }
        if(can(hg,arr)) cout<<hg<<endl;
        else cout<<lw<<endl;
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
   // solve_166A();
   //solve_161A();
      // solve_279B_();
     // solve271B();
     solve_spoj_cows();
    return 0;
}
