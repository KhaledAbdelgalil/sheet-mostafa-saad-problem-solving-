//nested range style:problem from bottom to up
//thin up to bottom a b c d   ((a) ((b) (c))) (d)
//problem:CasketOfStar(topcoder)
#include <bits/stdc++.h>
using namespace std;
int mem[51][51];
int best(vector <int> weight,int i,int j)
{
    if(j-i+1<=2) return 0;
    if(j-i+1==3)return weight[i]*weight[j];
    int& ret=mem[i][j];
    if(ret!=-1) return ret;
    ret=0;
    for(int k=i+1;k<j;k++)
        ret=max(ret,best(weight,i,k)+best(weight,k,j)+weight[i]*weight[j]);

    return ret;
}
class CasketOfStar{
public:
     int maxEnergy(vector <int> weight)
     {
         memset(mem,-1,sizeof mem);
        return best(weight,0,weight.size()-1);
     }


};

int main()
{
    CasketOfStar* s;
    s=new CasketOfStar();
    int n;
    cin>>n;
    vector<int>w(n);
    for(int i=0;i<n;i++)
        cin>>w[i];
   cout<<s->maxEnergy(w);
    return 0;
}
