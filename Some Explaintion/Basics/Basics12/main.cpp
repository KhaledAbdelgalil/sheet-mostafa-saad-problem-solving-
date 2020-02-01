//continue:practice on 2D array(Magic square Matrix) and trick direction
#include <iostream>
using namespace std;

#define N 3
enum dir {DOWN=0,RIGHT,UP,LEFT,UP_LEFT,UP_RIGHT,DOWN_LEFT,DOWN_RIGHT};
int dir_r[]={1,0,-1,0,-1,-1,1,1};
int dir_c[]={0,1,0,-1,-1,1,-1,1};
int sumRow(int row_index,int arr[N][N])
{
    int sum=0;
    for(int i=0;i<N;i++)
        sum+=arr[row_index][i];
    return sum;
}
int sumCol(int col_index,int arr[N][N])
{
    int sum=0;
    for(int i=0;i<N;i++)
        sum+=arr[i][col_index];
    return sum;
}
int sumMainDiagonal(int arr[N][N])
{
    int sum=0;
    int pos=0;
    for(int i=0;i<N;i++)
        sum+=arr[pos][pos],pos++;
    return sum;
}
int sumAntiDiagonal(int arr[N][N])
{
    int sum=0;
    int pos=0;
    for(int i=0;i<N;i++)
        sum+=arr[pos][N-pos-1],pos++;
    return sum;
}
bool Magic_Or_not(int arr[N][N])
{
    int val=sumRow(0,arr);
    for(int i=0;i<N;i++)
    {
        if(sumCol(i,arr)!=val) return false;
        if(sumRow(i,arr)!=val) return false;
    }
    if(sumAntiDiagonal(arr)!=val) return false;
    if(sumMainDiagonal(arr)!=val) return false;

    return true;
}
int test_magic()
{
    int arr[N][N]={8,1,6,3,5,7,4,9,2};
    cout<<Magic_Or_not(arr);
}

int sumWithDir(int r,int c,int dir,int steps,int arr[N][N])
{
    int sum=0;
    for(int i=0;i<steps;i++)
    {
        sum+=arr[r][c];
        r+=dir_r[dir];
        c+=dir_c[dir];
    }
    return sum;
}
int Test_sumWithDir()
{
    int arr[N][N]={1,2,3,4,5,6,7,8,9};
    cout<<sumWithDir(0,0,RIGHT,3,arr)<<endl;
    cout<<sumWithDir(1,0,RIGHT,3,arr)<<endl;
    cout<<sumWithDir(2,0,RIGHT,3,arr)<<endl;
    cout<<sumWithDir(0,0,DOWN_RIGHT,3,arr)<<endl;
    cout<<sumWithDir(0,0,DOWN,3,arr)<<endl;

}
int main()
{
    //test_magic();
    Test_sumWithDir();
    return 0;
}
