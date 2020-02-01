//problems: on uva(100-10344-140-167-216) some are recursion others permutation
#include <bits/stdc++.h>
#include<iomanip>
using namespace std;
//100:1-input n 2-print n 3-if n==1 stop 4-odd n=3n+1 5-even n=n/2 and 6-then goto 2

#define SIZE 10000
static unsigned save_table[SIZE];
unsigned  rec_100(unsigned  n)
{
    if (n < SIZE && save_table[n])
        return save_table[n];

    /* Check if number is odd */
    if (n&1){
        if (n < SIZE){
            /* Since 3n+1 becomes an even number, we perform the next step which is divided by two since its even, also +2 since we perform two operations */
            save_table[n] = 2 + rec_100((3 * n + 1) >> 1);
            return save_table[n];
        }else
            /* The value is bigger than table so we calculate and return */
            return 2 + rec_100((3 * n + 1) >> 1);
    }else{
        if (n < SIZE){
            /* The number is even so we perform number divided two, or bit shift left once */
            save_table[n] = 1 + rec_100(n >> 1);
            return save_table[n];
        }else
            return 1 + rec_100(n >> 1);
    }

}
void answer_100()
{
    unsigned x,y;
    save_table[1]=1;
    while (scanf("%u%u", &x, &y) == 2)
    {

        cout << x<<" "<<y<<" ";
        if(x>y) swap(x,y);
        unsigned  maxx=rec_100(x);
        for(int i=x+1;i<=y;i++)
            {
                maxx=max(maxx,rec_100(i));
            }
        cout<<maxx<<endl;
    }
}


int arr[5];
bool Possible(int sum,int len)
{
   if(len==5)
    return sum==23;
    int num = arr[len];
    return Possible(sum+num,len+1)|| Possible(sum-num,len+1)|| Possible(sum*num,len+1);
}


void answer_1034()
{
    while (scanf("%d%d%d%d%d", &arr[0], &arr[1],&arr[2],&arr[3],&arr[4]) == 5)
    {
        bool flag=false;
        if(arr[0]==0&&arr[1]==0&&arr[2]==0&&arr[3]==0&&arr[4]==0) break;

        sort(arr,arr+5);//for permutation should be sorted
        do{
            flag|=Possible(arr[0],1);

            if(flag)break;

        }while(next_permutation(arr,arr+5));

       if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}





void answer_140()
{
  char c;
  string input;
  map<char,bool> visited;
  map<char,int> pos;
  vector<char> chars;
  vector< pair<int,int> > pairs;
  vector<char> result;

  while (getline(cin, input)) {
    if (input == "#") {
      break;
    }

    chars.clear();
    visited.clear();
    pairs.clear();
    result.clear();

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] < 'A' || input[i] > 'Z') {
        input[i] = ' ';
      }
    }

    stringstream ss(input);
    while (ss >> c) {
      ss >> input;

      if (visited.find(c) == visited.end()) {
        visited[c] = true;
        chars.push_back(c);
      }

      for (int i = 0, sz = input.size(); i < sz; i++) {
        if (visited.find(input[i]) == visited.end()) {
          visited[input[i]] = true;
          chars.push_back(input[i]);
        }
        pairs.push_back(make_pair(c, input[i]));
      }
    }

    sort(chars.begin(), chars.end());

    int best = 10000000;
    do {
      int cur_best = 0;
      pos.clear();
      for (int i = 0, sz = chars.size(); i < sz; i++) {
        pos[chars[i]] = i;
      }

      for (int i = 0, sz = pairs.size(); i < sz; i++) {
        if (pairs[i].first == pairs[i].second) continue;

        if (abs(pos[pairs[i].first] - pos[pairs[i].second]) > cur_best) {
          cur_best = abs(pos[pairs[i].first] - pos[pairs[i].second]);
        }
      }

      if (cur_best < best) {
        result.clear();
        best = cur_best;
        for (int i = 0, sz = chars.size(); i < sz; i++) {
          result.push_back(chars[i]);
        }
      }
    } while (next_permutation(chars.begin(), chars.end()));

    for (int i = 0, sz = result.size(); i < sz; i++) {
        cout << result[i]<<" ";
    }
    cout << "-> " << best << endl;
  }

}




int board[8][8];
bool rows[8],diagonals1[15],diagonals2[15];
int maxx=0;
int ans[8];
void solve_board(int col,int sum=0)
{
    if(col==8)
    {
        //cout<<sum<<endl;
        if(sum>maxx)maxx=sum;
        return;
    }
    for(int row=0;row<8;row++)
    {
        int d1=row-col,d2=row+col-7;
        if(d1<0) d1+=15;
        if(d2<0)d2+=15;

        if(!rows[row]&&!diagonals1[d1]&&!diagonals2[d2])
        {
            rows[row]=diagonals1[d1]=diagonals2[d2]=true;
            solve_board(col+1,sum+board[row][col]);
            rows[row]=diagonals1[d1]=diagonals2[d2]=false;
        }
    }
}
void answer_167()
{
    int k;
    cin>>k;
    while(k--)
    {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            cin>>board[i][j];
        solve_board(0);//col==player,sum=0
        printf("%5d\n", maxx);
        maxx=0;
    }



}

struct point{
    float x;
    float y;
};

int n,networks_count=0;
vector<struct point>in;
vector<struct point>result;
vector<float>distances;
vector<float>distances_result;
float minn=1000000;
float d;

float norm(float x1,float x2,float y1,float y2)
{
    float s=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return float(sqrt(s));
}
void get_all_perm(int i,int n,bool vis[],struct point curr[])
{
    if(i==n)
    {
        float sum=0;
            distances.clear();
            for(int i=0,sz=in.size();i<sz-1;i++)
            {
                d=norm(curr[i].x,curr[i+1].x,curr[i].y,curr[i+1].y);
                distances.push_back(d+16.0);
                sum+=d+16;
            }
            if(sum<minn)
            {
                distances_result.clear();
                result.clear();
                minn=sum;
                for(int i=0,sz=in.size();i<sz;i++)
                    result.push_back(curr[i]);
                for(int i=0,sz=distances.size();i<sz;i++)
                    distances_result.push_back(distances[i]);
            }
            return;
        }

    for(int j=0;j<n;j++)
    {
        if(!vis[j])
        {
            vis[j]=1;
            curr[i]=in[j];
            get_all_perm(i+1,n,vis,curr);
            vis[j]=0;
        }
    }

}
void answer_216()
{

    struct point p;
    while(cin>>n)
    {
        if(n==0)break;
        struct point curr[n];
        bool vis[n];
        networks_count++;
        for(int i=0;i<n;i++)
        {
            cin>>p.x>>p.y;
            in.push_back(p);
            vis[i]=0;
        }

        /*do
        {
            distances.clear();
            for(int i=0,sz=in.size();i<sz-1;i++)
            {
                d=norm(in[i].x,in[i+1].x,in[i].y,in[i+1].y);
                distances.push_back(d);
                sum+=d;
            }
            if(sum<minn)
            {
                distances_result.clear();
                result.clear();
                minn=sum;
                for(int i=0,sz=in.size();i<sz;i++)
                    result.push_back(in[i]);
                for(int i=0,sz=distances.size();i<sz;i++)
                    distances_result.push_back(distances[i]);
            }
        }while(next_permutation(in.begin(),in.end(),cmp1));*/
        get_all_perm(0,n,vis,curr);
        in.clear();
        //show result
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<networks_count<<endl;
        for(int i=0,sz=result.size();i<sz-1;i++){
            cout<<"Cable requirement to connect (";
            cout<<(int)result[i].x;
            cout<<',';
            cout<<(int)result[i].y;
            cout<<") to (";
            cout<<(int)result[i+1].x;
            cout<<",";
            cout<<(int)result[i+1].y;
            cout<<") is ";
            cout<<fixed<<setprecision(2)<<distances_result[i];
            cout<<" feet."<<endl;
        }
       cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<minn<<"."<<endl;
       minn=1000000;
    }
}





int main()
{
    //answer_100();
    // answer_1034();
    //answer_140();
    //answer_167();
    //answer_216();
    return 0;
}
