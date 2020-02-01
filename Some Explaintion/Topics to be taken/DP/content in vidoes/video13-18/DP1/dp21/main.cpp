//epected steps to get head e(x)=1*0.5+0.5(1+e(x))
//expected steps in a graph
#include <bits/stdc++.h>
using namespace std;
vector < vector <int> > child(12);

double expectedsteps(int i,int stepsoFar)
{
    if(child[i].size()==0) return stepsoFar;
    double prop=1.0/(double)child[i].size();
    double ret=0;
    for(int j=0;j<child[i].size();j++)
        ret+=prop*expectedsteps(child[i][j],stepsoFar+1);

    return ret;
}

double expectedsteps2(int i)
{
    if(child[i].size()==0) return 0;
    double prop=1.0/(double)child[i].size();
    double ret=0;
    for(int j=0;j<child[i].size();j++)
        ret+=prop*(1+expectedsteps2(child[i][j]));

    return ret;
}

//another solution not considering coming with how many steps
int main()
{



    child[2].push_back(7);
    child[2].push_back(5);
    child[2].push_back(4);

    child[5].push_back(9);
    child[5].push_back(11);

    child[9].push_back(4);

    child[7].push_back(1);
    child[7].push_back(6);


    child[1].push_back(6);
    child[1].push_back(3);

    child[6].push_back(3);
    child[6].push_back(11);

    for(int i=0;i<12;i++)
        cout<<i<<"  "<<expectedsteps(i,0)<<" "<<expectedsteps2(i)<<endl;
    return 0;
}
