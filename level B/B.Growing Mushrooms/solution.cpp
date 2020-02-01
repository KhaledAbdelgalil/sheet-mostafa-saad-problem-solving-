/******************************************************************************
                     Khaled ahmed abdelgalil
                          Ain Shams 
                     Computer Enginnering
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include<vector>
#include <iomanip>

using namespace std;

class competitors 
{
public:
    double score;
    int index;
    
};
bool compare(competitors s1, competitors s2)
{
    if(s1.score>s2.score) return true;
    if(s1.score==s2.score&&s1.index<s2.index) return true;
    return false;
}
double s1,s2;
int main()
{
    int n;
    double t1,t2,k;
    cin>>n>>t1>>t2>>k;
    std::vector<competitors >result(n);
    for(int i=0;i<n;i++)
    {
        cin>>s1>>s2;
        result[i].index=i+1;
        result[i].score=max(s1*t1*(100-k)/100.0+s2*t2,s2*t1*(100-k)/100.0+s1*t2);
    }
    sort(result.begin(),result.end(),compare);
    for(int j=0;j<n;j++)
    {
     cout<<fixed<<setprecision(2);
    cout<<result[j].index<<" "<<result[j].score;
    //if(result[j].score==int(result[j].score))
    //cout<<".00";
    cout<<endl;
    }
    return 0;
}
