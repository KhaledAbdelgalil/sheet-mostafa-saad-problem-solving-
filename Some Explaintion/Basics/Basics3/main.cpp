//this tutorial help to learn about assert fn and how to create test_bench for our functions
#include <bits/stdc++.h>

using namespace std;
int get_2nd_max(int arr[],int n)
{
    int  largest, second;


   if(arr[0]<arr[1]){
      largest = arr[1];
      second = arr[0];
   }
   else{
      largest = arr[0];
      second = arr[1];
   }
   for (int i = 2; i< n ; i ++)
    {
      /* If the current array element is greater than largest
       * then the largest is copied to "second" and the element
       * is copied to the "largest" variable.
       */
      if (arr[i] > largest) {
         second = largest;
         largest = arr[i];
      }
      /* If current array element is less than largest but greater
       * then second largest ("second" variable) then copy the
       * element to "second"
       */
      else if (arr[i]>second)
        {
         second = arr[i];
      }
   }
   return second;
}
void test_get_2nd_max()
{
    const int size=10;
    int arr[size];
    for(int test=0;test<1000;test++)
    {
        //build random array
        for(int i=0;i<size;i++)
            arr[i]=rand()%100;
        int myanswer=get_2nd_max(arr,size);
        sort(arr,arr+size);

        int correct_answer=arr[size-2];
        int ans=arr[size-1];
        cout<<test<<" "<<correct_answer<<" "<<myanswer<<endl;
        assert(myanswer==correct_answer);
    }
    cout<<"Perfect"<<endl;
}

void reverse_inplace(int arr[],int n)//inplace i.e without creating additional memory
{
    for(int i=0;i<n/2;i++)
        swap(arr[i],arr[n-i-1]);
}
void test_reverse_inplace()
{
    const int size=10;
    int arr[size];
    int cpy[size];
    for(int test=0;test<1000;test++)
    {
        //build random array
        for(int i=0;i<size;i++)
            cpy[i]=arr[i]=rand()%100;

        reverse(arr,arr+size);
        reverse_inplace(cpy,size);

        for(int i=0;i<size;i++)
            assert(arr[i]==cpy[i]);
    }
    cout<<"Perfect"<<endl;

}
int main()
{
    //test_get_2nd_max();
    test_reverse_inplace();
    return 0;
}
