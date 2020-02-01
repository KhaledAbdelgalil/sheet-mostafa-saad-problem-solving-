#include <bits/stdc++.h>

using namespace std;

//joseph problem:n men in circle joseph start at 1 count k kill him then repeat until one remains
int JosephSol(int n ,int k)
{
    int* arr;
    arr=new int(n);
    for(int i=0;i<n;i++)
        arr[i]=i+1;
    int i=0;
    while(n!=1)
    {

        for(int c=0;c<k-1;i++,i=i%n,c++);

        for(int j=i;j<n-1;j++)
            arr[j]=arr[j+1];
        n--;
         for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
         cout<<endl;
    }
    int ret=arr[0];
    free(arr);
    return ret;
}
int main()
{
    cout<<JosephSol(7,3);
    return 0;
}
