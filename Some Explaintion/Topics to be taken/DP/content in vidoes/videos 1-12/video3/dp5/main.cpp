//UVA problems(111-562-10100 )
#include <bits/stdc++.h>
using namespace std;
//111

int t[21], s[21], lcs[21][21];
int LCS(int i, int j){
    if(i == 0 || j == 0) return 0;
    if(lcs[i][j] != -1)return lcs[i][j];
    if(s[i] == t[j]) return lcs[i][j] = 1 + LCS(i-1, j-1);
    int x = LCS(i-1, j);
    int y = LCS(i, j-1);
    return lcs[i][j] = max(x, y);
}
void solve_111()
{
    int N, item;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &item);
        s[item] = i;
        }
    while(scanf("%d", &item) == 1)
    {
        t[item] = 1;
        for(int i = 2; i <= N; i++ ) {
            scanf("%d", &item);
            t[item] = i;
        }
        memset(lcs, -1, sizeof lcs);
       printf("%d\n", LCS(N, N));
    }
}


//562 important problem
int N;
int arr_wt[101];
int sum_coins;
int mem_coins[101][25000+1];
int dividing_coins_rec_knap(int i,int W)
{
    if(i==N) return 0;
    int &ret=mem_coins[i][W];
    if(ret!=-1) return -1;
    ret=0;
    if(arr_wt[i]>W)
       return ret=dividing_coins_rec_knap(i+1,W);
    else
        return ret=max(dividing_coins_rec_knap(i+1,W-arr_wt[i])+arr_wt[i],dividing_coins_rec_knap(i+1,W));
}

void solve_562()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
    sum_coins=0;
    memset(mem_coins, -1, sizeof mem_coins);

     cin>>N;
     for(int i=0;i<N;i++)
        {
            cin>>arr_wt[i];
            sum_coins+=arr_wt[i];
        }
    int knapped=dividing_coins_rec_knap(0,sum_coins/2);
    cout<<sum_coins-2*knapped<<endl;
    }
}


//10100

string in[1001];
string cp[1001];
int mem_strings[1001][1001];
int M;
int Counting_strings(int i,int j)
{
    if(i==N||j==M) return 0;
    int &ret=mem_strings[i][j];
    if(ret!=-1) return ret;
    //int answer=0;
    if(in[i]==cp[j])
        return ret=1+Counting_strings(i+1,j+1);
     //answer=max(answer,);

     return ret=max(Counting_strings(i+1,j),Counting_strings(i,j+1));
}
void solve_10100()
{
    string x;
    bool empty=false;
    int cs=1;
    while(getline(cin,x))
    {
        memset(mem_strings,-1,sizeof mem_strings);
        stringstream ss1,ss2;

        //in
        if(x.size()==0)
            empty=true;
        for(int i=0,sz=x.size();i<sz;i++)
            if(!(isalpha(x.at(i))||isdigit(x.at(i)))) x[i]=' ';
        ss1<<x;
        N=0;
        while(ss1>>x)
        {
            in[N]=x;
            N++;
        }


        //cp
        getline(cin,x);
        if(x.size()==0)
            empty=true;
        for(int i=0,sz=x.size();i<sz;i++)
            if(!(isalpha(x.at(i))||isdigit(x.at(i)))) x[i]=' ';
        ss2<<x;
        M=0;
        while(ss2>>x)
        {
            cp[M]=x;
            M++;
        }
        /*for(int i=0;i<N;i++)
            cout<<in[i]<<" ";
        for(int i=0;i<M;i++)
            cout<<cp[i]<<" ";*/
        if(empty)  printf("%2d. Blank!\n",cs++);
        else {
            int c=Counting_strings(0,0);
            printf("%2d. Length of longest match: %d\n",cs++,c);
        }
        empty=false;
    }
}
int main()
{
    //solve_111();
    //solve_562();
    solve_10100();
    return 0;
}
