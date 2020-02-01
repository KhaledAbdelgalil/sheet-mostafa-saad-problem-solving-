//pointers
#include <iostream>
using namespace std;

void ptr()
{
    int val=15;
    int* ptr=&val;
    cout<<"Contents: "<<endl;
    cout<<*ptr<<" "<<val<<" "<<*&val<<endl;
    cout<<"address: "<<endl;
    cout<<ptr<<" "<<&val<<endl;
    cout<<"address of pointer: "<<endl;
    cout<<&ptr<<endl;
}
void ptr_arr()
{
    int arr[5]={8,6,2,4,3};

    cout<<arr<<endl;
    cout<<&arr[0]<<endl;

    int *pArr=&arr[0];//points to first element

    cout<<*pArr<<endl;
    cout<<pArr<<endl;
    cout<<&pArr<<endl;

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" "<<pArr[i]<<" "<<*(arr+i)<<" "<<*(pArr+i)<<endl;
    }
    pArr++;
    cout<<*pArr<<endl;
    //arr++;//compile error
}

void ptr_arr2()
{
    int arr[5]={10,20,30,40,50};
    int *ptr=arr+2;//*ptr will be 30;
    int val;
    cout<<ptr-arr<<endl;

    val=*ptr++;
    cout<<val<<" "<<ptr-arr<<endl;

    ptr=arr+2;
    val=*++ptr;
    cout<<val<<" "<<ptr-arr<<endl;

    ptr=arr+2;
    val=*ptr--;
    cout<<val<<" "<<ptr-arr<<endl;

    ptr=arr+2;
    val=*--ptr;
    cout<<val<<" "<<ptr-arr<<endl;


    //very important
    ptr=arr+2;
    cout<<arr[2]<<endl;
    val=(*ptr)++;
    cout<<val<<" "<<ptr-arr<<endl;

    cout<<arr[2];


}

void ptr_arr3()
{
    int arr[5]={1,2,3,4,5};
    int *ptr=arr;
    while(ptr != arr+5)
        cout<<*ptr++<<" ";//print and move to next

}
//please move step by step in this fn
void const_pointer_const_data()
{
    int val=2;
    const int *ptr=new int;//data is int and constant
    //cannot do that
    //*ptr=20;//read only
    cout<<ptr<<endl;
    ptr=&val;
    cout<<ptr<<endl;
    //*ptr=3;

    int* const ptr2=&val;
    *ptr2=3;
    cout<<val<<endl;
    //ptr2=ptr;//ptr2 is of constant direction
    const int* const ptr3=&val;
    cout<<*ptr3;
    //ptr3=ptr2;
    //*ptr3=43;
}
void variables_alias()
{
    int val=10;
    cout<<&val<<endl;
    int cpy=val;
    int &reff=val;//take refrence from val(automatic defrence)
    cout<<&reff<<endl;
    reff++;
    cout<<val<<" "<<reff<<endl;
    val++;
    cout<<val<<" "<<reff<<" "<<cpy<<endl;
    //int &reff2=4;
}
//alias vs pointers
void fun1(int &a){}
void fun2(const int &a){}
void fun3(int *a){}
void aliasVsPointers()
{
    int x=10;
   int *y=new int;
   fun1(x);
   //fun1(y);
   //fun1(5);

   fun2(x);
   //fun2(y);
   fun2(5);

   fun3(&x);
   fun3(y);
   //fun3(5);
}


void dynamic_alloc()
{
    int *ptr=new int[10];//create memory
    delete [] ptr;//release mempry
    int *p=new int;
    delete p;

    int arr2d[3][2];
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            cout<<&arr2d[i][j]<<endl;
    cout<<"----------------"<<endl;
    int* arr[3]={0};//array of 3 pointers initialized to null

    for(int i=0;i<3;i++)arr[i]=new int[2];

    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            cout<<&arr[i][j]<<endl;

    cout<<&arr2d[2][1]-&arr2d[0][0]<<" "<<&arr[2][1]-&arr[0][0]<<endl;
    for(int i=0;i<3;i++)delete []arr[i];

    int **ptr2d=new int*[3];
    for(int i=0;i<3;i++)
        ptr2d[i]=new int[2];

     for(int i=0;i<3;i++)
        delete [] ptr2d[i];
    delete ptr2d;
}

int** create()
{

    int **ptr2d=new int*[3];
    for(int i=0;i<3;i++)
        ptr2d[i]=new int[2];
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
        ptr2d[i][j]=i+j;
    return ptr2d;
}
void print(int ** ptr2d)
{
     for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
       cout<< ptr2d[i][j]<<" ";
       cout<<endl;
}
void free(int ** ptr2d)
{
    for(int i=0;i<3;i++)
    delete [] ptr2d[i];

    delete ptr2d;
}
void arr2d()
{
    int** arr=create();
    print(arr);
    free(arr);
}
int main()
{

    //ptr();
   // ptr_arr2();
    //ptr_arr3();
    //const_pointer_const_data();
   // variables_alias();

   //aliasVsPointers();
    //dynamic_alloc();
    //arr2d();

    return 0;
}
