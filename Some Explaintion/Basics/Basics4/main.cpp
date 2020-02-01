//playing with arrays

#include <iostream>

using namespace std;

int slidingWindowMax_bruteForce(int arr[],int size,int k)
{
    int maxWin=0;
    for(int i=0;i<size-k+1;i++)
    {
        int sum=0;
        for(int win=0;win<k;win++)
            sum+=arr[i+win];
        if(i==0||sum>maxWin) maxWin=sum;
    }
    return maxWin;
}
int slidingWindowMax_Modified(int arr[],int size,int k)
{
    int maxWin=0;
    //take first window
    for(int win=0;win<k;win++)
        maxWin+=arr[win];
    int sum=maxWin;
    for(int i=1;i<size-k+1;i++)
    {
        sum=sum+arr[i+k-1]-arr[i-1];
        maxWin=max(sum,maxWin);
    }
    return maxWin;
}
void test_slidingWindow()
{
    int arr[]={1,2,3,4,5,6};
    cout<<slidingWindowMax_bruteForce(arr,6,3)<<endl<<slidingWindowMax_Modified(arr,6,3)<<endl;
}

void InsertionSort(int arr[],int n)
{
    int j,key;
    for(int i=1;i<n;i++)//first element is sorted
    {
         key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void test_insertion_sort()
{
    int arr[]={80,90,60,30,50,70,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    //test_slidingWindow();
    //test_insertion_sort();
    return 0;
}
