//============================================================================
// Name        : uva333.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char grid[30][30];
bool seen[30][30];

void dfs(int x,int y)
{
	seen[x][y]=1;

	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			if(x+i>=0&&x+i<n&&y+j<n&&y+j>=0&&!seen[x+i][y+j]&&grid[x+i][y+j]=='1')
				dfs(x+i,y+j);

}
int main() {

    int c=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>grid[i][j];

		memset(seen,0,sizeof seen);
		int cnt=0;
		for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
					{

						if(!seen[i][j]&&grid[i][j]=='1')
						{dfs(i,j),cnt++;}

					}
		cout<<"Image number "<<c++<<" contains "<<cnt<<" war eagles."<<endl;
	}
	return 0;
}
