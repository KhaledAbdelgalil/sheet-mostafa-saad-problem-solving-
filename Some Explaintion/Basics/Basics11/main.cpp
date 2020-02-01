/*Applications on 2D arrays*/

#include <bits/stdc++.h>

using namespace std;
const int ROWS=2,COLS=3;
void add_matrix(int arr1[ROWS][COLS],int arr2[ROWS][COLS],int arr3[ROWS][COLS])
{
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            arr3[i][j]=arr1[i][j]+arr2[i][j];
}
void simulation_matrices(int arr1[ROWS][COLS],int arr2[ROWS][COLS],int arr3[ROWS][COLS])
{
    for(int i=0;i<ROWS;i++)
    {
        cout<<"|";
        for(int j=0;j<COLS;j++)
            cout<<arr1[i][j]<<" ";
        cout<<"|"<<endl;
    }
    cout<<"   +  "<<endl;

    for(int i=0;i<ROWS;i++)
    {
        cout<<"|";
        for(int j=0;j<COLS;j++)
            cout<<arr2[i][j]<<" ";
        cout<<"|"<<endl;
    }
    cout<<"----------------"<<endl;
     for(int i=0;i<ROWS;i++)
    {
        cout<<"|";
        for(int j=0;j<COLS;j++)
            cout<<arr3[i][j]<<" ";
        cout<<"|"<<endl;
    }
}
const int r1=2,c1=3,r2=3,c2=2;
void multiply_matrix(int arr1[r1][c1],int arr2[r2][c2],int arr3[r1][c2])
{
    assert(c1==r2);//verify
    for(int r=0;r<r1;r++)
        for(int c=0;c<c2;c++)
            arr3[r][c]=0;
    //for each cell in arr3
    for(int r=0;r<r1;r++)
        for(int c=0;c<c2;c++)
           for(int k=0;k<c1;k++)
            arr3[r][c]+=arr1[r][k]*arr2[k][c];

      for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    /*int arr1[ROWS][COLS]={1,2,3,4};
    int arr2[ROWS][COLS]={{4},{8}};
    int arr3[ROWS][COLS];
    add_matrix(arr1,arr2,arr3);
    simulation_matrices(arr1,arr2,arr3);*/

    int arr1[r1][c1]={1,2,3,4,5,6};
    int arr2[r2][c2]={7,8,9,10,11,12};
    int arr3[r1][c2];
    multiply_matrix(arr1,arr2,arr3);

    return 0;
}
