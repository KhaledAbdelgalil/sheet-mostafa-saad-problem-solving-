#include<iostream>
using namespace std;
int r,c;
char grid[9][9];
int sx,sy,ex,ey;
string in="IEHOVA#";
void sol(int i,int ix,int iy)
{
	if(i==in.size())
		return;
    if(i)cout<<" ";
	if(ix-1>=0&&grid[ix-1][iy]==in[i])
	{


		cout<<"forth";


		sol(i+1,ix-1,iy);
	}
	else if(iy-1>=00&&grid[ix][iy -1]==in[i])
	{

		cout<<"left";

		sol(i+1,ix,iy -1);
	}
	else if(iy+1 <c &&grid[ix][iy+1]==in[i])
	{

		cout<<"right";
		sol(i+1,ix,iy+1);
	}



}
int main(void) {

	int t;
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='@')
					sx=i,sy=j;
				else if(grid[i][j]=='#')
					ex=i,ey=j;
			}

		sol(0,sx,sy);
		cout<<endl;
	}
  return 0;
}
