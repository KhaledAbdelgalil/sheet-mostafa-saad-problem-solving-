//simulation of Big factorial

#include <iostream>

using namespace std;

void check(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int mod=arr[i]%10;
        int div=arr[i]/10;
        arr[i]=mod;
        arr[i+1]+=div;
    }
}
void print_reverse(int arr[],int n)
{
    for(int i=n;i>=0;i--)
        cout<<arr[i];
    cout<<endl;
}
void Big_Factorial(int n)
{
    int arr[10000]={0};
    arr[0]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<10000;j++)
        {
            arr[j]*=i;
        }
        check(arr,10000);
    }
    print_reverse(arr,20);
}
int main()
{
    Big_Factorial(2);
    Big_Factorial(3);
    Big_Factorial(4);
    Big_Factorial(5);
    Big_Factorial(6);
    Big_Factorial(7);
    Big_Factorial(8);
    Big_Factorial(9);
    Big_Factorial(10);
    Big_Factorial(11);
    Big_Factorial(12);
    Big_Factorial(13);
    Big_Factorial(14);
    return 0;
}
