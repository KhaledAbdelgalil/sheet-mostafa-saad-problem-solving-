//continue playing with arrays:merging two sorted arrays and
#include <bits/stdc++.h>

using namespace std;
int merge_2_sorted_arrays(int arr1[],int sz1,int arr2[],int sz2,int result[],int sz3)
{
    int idx1=0;
    int idx2=0;
    int res=0;

    while(idx1<sz1&&idx2<sz2)
    {
        if(arr1[idx1]<arr2[idx2])
        {
            result[res++]=arr1[idx1++];
        }
        else   result[res++]=arr2[idx2++];
    }
    while(idx1<sz1)
    {
        result[res++]=arr1[idx1++];
    }
    while(idx2<sz2)
    {
        result[res++]=arr2[idx2++];
    }
}
void test_bench()
{
    const int sz1=10;
    const int sz2=9;
    const int sz3=sz1+sz2;
    int arr1[sz1];
    int arr2[sz2];
    int arr3[sz3];
    int result_fn[sz3];
    for(int test=0;test<100000;test++)
    {
        for(int i=0;i<sz1;i++)
        {
             arr1[i]=rand()%100;
             arr3[i]=arr1[i];
        }

        for(int i=0;i<sz2;i++)
        {
            arr3[sz1+i]=arr2[i]=rand()%100;
        }

        sort(arr1,arr1+sz1);
        sort(arr2,arr2+sz2);
        sort(arr3,arr3+sz3);
        merge_2_sorted_arrays(arr1,sz1,arr2,sz2,result_fn,sz3);
        for(int i=0;i<sz3;i++)
            assert(arr3[i]==result_fn[i]);
    }
    cout<<"Perfect Merge"<<endl;
}
int main()
{
    test_bench();
    return 0;
}
