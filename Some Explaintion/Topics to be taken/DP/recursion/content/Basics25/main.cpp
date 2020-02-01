//uva problems:776
#include <bits/stdc++.h>

using namespace std;

//776
char board_forest[1000][1000];
int xx,yy;
int countt=0,len=0;
char cell;
int f=10;
int vis_char[1000][1000];
int dr[] = {0,0,1,-1,1,1,-1,-1};
int dc[] = {1,-1,0,0,1,-1,1,-1};
bool isSafe(int y,int x)
{
    if(y<0||x<0||y>=xx ||x>=yy)return false;
    return true;
}

void flood_fill(int y,int x)
{
    vis_char[y][x]=countt;
   for(int i=0;i<=7;i++)
    {
        int ny = y + dr[i];
        int nx = x + dc[i];
        if(isSafe(ny,nx)&&board_forest[ny][nx]==cell&&vis_char[ny][nx]==0)

        flood_fill(ny,nx);
    }

}

void answer_776()
{

    string line;
    while(true){
        getline(cin,line);
        if(feof(stdin)||line[0]=='%'){
            countt=0;
            f=10;
            len=0;
           for(int i=0;i<xx;i++){
                for(int j=0;j<yy;j++){
                    if(vis_char[i][j]==0){
                        countt++;
                        if(countt%f==0)
                        {
                            len++;
                            f*=10;
                        }
                        cell = board_forest[i][j];
                        flood_fill(i,j);
                        }
                }
                }

                //handling presentation error
              bool flag[yy]={0}; int flag_size_col[yy]={0};
               for(int i=0;i<yy;i++)
                {
                    stringstream ss;
                    string str;
                    ss << vis_char[0][i];
                    ss>>str;
                    int size1=str.size();
                for(int j=0;j<xx;j++)
                {
                    stringstream ss1;
                    string str2;
                    ss1 << vis_char[j][i];
                    ss1>>str2;
                    int size2=str2.size();
                    flag_size_col[i]=max(flag_size_col[i],size2);
                    if(size1!=size2)flag[i]=1;
                }
                }


            //cout<<flag[0]<<flag_size_col[1]<<endl;
              for(int i=0;i<xx;i++)
                {
                for(int j=0;j<yy;j++)
                {
                    stringstream ss;
                    string str;
                    ss << vis_char[i][j];
                    ss >> str;
                    for(int s=int(str.size());s<flag_size_col[j];s++) cout<<" ";

                   cout<<str;
                    printf("%c",(j==yy-1)?'\n':' ');
                }
                }

        printf("%c%c", '%','\n');
        if(feof(stdin))break;
        xx=0;
        }
        else {
            yy=0;
            for(int i=0,sz=line.size();i<sz;i++){
                if(line[i]!=' ')
                {
                    vis_char[xx][yy]=0;
                     board_forest[xx][yy++] = line[i];
                }
            }
        xx++;
        }
    }

}
int main()
{

   answer_776();
    return 0;
}
