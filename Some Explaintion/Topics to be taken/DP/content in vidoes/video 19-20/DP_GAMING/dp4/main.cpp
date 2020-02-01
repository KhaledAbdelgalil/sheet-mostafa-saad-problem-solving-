/*
very very important problem::https://arena.topcoder.com/#/u/practiceCode/13542/8748/9791/1/297844
*/
//strategy in playing is different one to maximize and other minimize score
//score is the same for both players so not from state
//point could be red blue white 1 2 0
//so balls are 2-12 so state 3^12
//to full understand it:use balls=2
#include <bits/stdc++.h>
using namespace std;
double dist[20][20];
const int MAX_STATES=6000000;
double mem[MAX_STATES];
int n;
double distanceCalculate(double x1, double y1, double x2, double y2)
{
	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);

	return dist;
}

double go(int state,int maxPlayer,vector< vector<int> > &points)//here when we take choice we don't calculate its cost immediatly
{
    if(points[0].size()==0)//I want to calculate on fly
        return 0;


    double &ret=mem[state];
    if(ret==ret) return ret;

    ret=maxPlayer?0:1e9;
    int id=maxPlayer?1:2;

    for(int i=0;i<points[0].size();i++)
    {
        int p=points[0][i];
        swap(points[0][i],points[0].back());
        points[0].pop_back();
        points[id].push_back(p);
        double newcst=0;
        for(int j=0;j<points[3-id].size();j++)
            newcst+=dist[p][points[3-id][j]];

        //as insert 2 into 103 to be 123
        double ans=newcst+go(state+id*pow(3.0,n-p-1),!maxPlayer,points);

        points[id].pop_back();
        points[0].push_back(p);
        swap(points[0][i],points[0].back());

        if(maxPlayer)
            ret=max(ret,ans);
        else
            ret=min(ans,ret);
    }

    return ret;
}

class PointsGame
{
 public:
    double gameValue(vector <int> pointsX, vector <int> pointsY)
     {
        //pre-processing step
        n=pointsX.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=distanceCalculate((double)pointsX[i],(double)pointsY[i],(double)pointsX[j],(double)pointsY[j]);
        memset(mem,-1,sizeof mem);
        vector< vector<int> >points(3);
        for(int i=0;i<n;i++)
            points[0].push_back(i);
        return go(0,1,points);
     }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
