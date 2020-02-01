//2D array:Spiral square array:print->move->print->move+
#include <bits/stdc++.h>

using namespace std;
enum dir {RIGHT=0,DOWN,LEFT,UP};
int dir_r[]={0,1,0,-1};
int dir_c[]={1,0,-1,0};
#define n 6
void print_spiral(int arr[n][n],int N)
{
    int r=0,c=0;
    int steps=N,dir=RIGHT;
    int cnt=0;
    while(cnt<N*N)
    {
        for(int directions=0;directions<4&&cnt<N*N;directions++)//right down left up
        {
            int m=steps-1;
            if(directions==3) m--;

            for(int i=0;i<m&&cnt<N*N;i++)
            {
                cout<<arr[r][c]<<" ";
                cnt++;r+=dir_r[dir];c+=dir_c[dir];
            }
            dir=(dir+1)%4;

        }
        cout<<arr[r][c]<<" ";//handle last op
        ++cnt;
        r+=dir_r[dir];c+=dir_c[dir];
        steps-=2;
    }
    cout<<endl;
}
int main()
{

    int arr[n][n]={
                1 , 2 , 3 , 4 , 5 , 6,
                7 , 8 , 9 , 10, 11, 12,
                13, 14, 15, 16, 17, 18,
                19, 20, 21, 22, 23, 24,
                25, 26, 27, 28, 29, 30,
                31, 32, 33, 34, 35, 36
                };

    print_spiral(arr,1);
    print_spiral(arr,2);
    print_spiral(arr,3);
    print_spiral(arr,4);
    print_spiral(arr,5);
    print_spiral(arr,6);






    return 0;
}
