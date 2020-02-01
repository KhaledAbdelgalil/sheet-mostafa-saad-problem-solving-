#include <iostream>
#include <time.h>

using namespace std;


void print_row_majorOrder(int arr[12][4],int rows,int cols)
{
    const clock_t begin_time = clock();
    cout<<"row start"<<endl;
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++)
            cout<<arr[r][c]<<" ";
    cout<<endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
}
void print_col_majorOrder(int arr[12][4],int rows,int cols)
{
    const clock_t begin_time = clock();
    cout<<"col start"<<endl;
    for(int c=0;c<cols;c++)
        for(int r=0;r<rows;r++)
            cout<<arr[r][c]<<" ";
    cout<<endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
}
void flatten_2D_to_1D()
{
    const int COLS=3;
    const int Rows=3;
    int col2d=1;
    int row2d=1;
    int arr2D[Rows][COLS]={{1,2,3},{4,5,6},{7,8,9}};
    int arr1D[Rows*COLS]={1,2,3,4,5,6,7,8,9};
    //value 5 at row=1 col=1
    int index1d=row2d*COLS+col2d;
    cout<<arr2D[row2d][col2d]<<" "<<arr1D[index1d]<<endl;
    int rr=index1d/COLS;
    int cc=index1d%COLS;
    cout<<arr2D[rr][cc]<<endl;


}

void flatten_3D_to_1D()
{
    const int dim1_3D=3;
    const int dim2_3D=3;
    const int dim3_3D=3;
    //16
    int arr3d[dim1_3D][dim2_3D][dim3_3D]={{{1,2,3},{4,5,6},{7,8,9}},{{10,11,12},{13,14,15},{16,17,18}},{{19,20,21},{22,23,24},
    {25,26,27}}};
    int arr1d[dim1_3D*dim2_3D*dim3_3D]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int d1=1;
    int d2=2;
    int d3=0;
    int index1=d1*dim2_3D*dim3_3D+d2*dim3_3D+d3;
    int dd1=index1/(dim2_3D*dim3_3D);
    int dd2=index1/dim3_3D-d1*dim2_3D;
    int dd3=index1%dim3_3D;
    cout<<arr3d[d1][d2][d3]<<" "<<arr1d[index1]<<" "<<arr3d[dd1][dd2][dd3];
}
void initilization_methods()
{
    int arr1[2][3]={1,2,3,4};
    cout<<"first method"<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
            cout<<arr1[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"second method"<<endl;
    int arr2[2][3]={{4},{8}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
            cout<<arr2[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{

    //initialize multidimensional array

    /*int arr[12][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{1,2,3,4},{5,6,7,8},{9,10,11,12},{1,2,3,4},{5,6,7,8},{9,10,11,12},{1,2,3,4},{5,6,7,8},{9,10,11,12}};//braces could be eliminated

    // print_col_majorOrder(arr,12,4);//row major is faster think of cache
    //print_row_majorOrder(arr,12,4);*/
    //flatten_2D_to_1D();
    //flatten_3D_to_1D();
    initilization_methods();
    return 0;
}
