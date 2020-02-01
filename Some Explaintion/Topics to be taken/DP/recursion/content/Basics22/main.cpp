//stack overflow and intro to dynamic programming
//dp:no of states is strictly less than number of calls so we need to save answer:think of fib as tree

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define MAX 100

int i=0;
void stack_test1()
{
    cout<<i++<<endl;
    stack_test1();
}
void stack_test2()
{
    int arr;
    cout<<i++<<endl;
    stack_test2();
}
void stack_test3()
{
    int arr[50];
    cout<<i++<<endl;
    stack_test3();
}
void stack_test4()
{
    int arr[100];
    cout<<i++<<endl;
    stack_test4();
}
void stack_test5()
{
    int arr[50];
    vector<int>s(1000);//created on heap using new operator
     cout<<i++<<endl;
    stack_test5();
}

void stack_test6()
{
    int arr[50];
    vector<int>s(10000000);//created on heap using new operator
     cout<<i++<<endl;
    stack_test5();
}
void stack_test7()
{
    int arr[100000000];

     cout<<i++<<endl;
    stack_test5();
}
int save_answer[MAX];
int fib_save(int n)
{
    if(n<=1) return 1;
    if(save_answer[n]!=-1) return save_answer[n];
    return save_answer[n]=fib_save(n-2)+fib_save(n-1);
}
int fib(int n)
{
    if(n<=1) return 1;

    return fib(n-2)+fib(n-1);
}
int main()
{
    for(int i=0;i<MAX;i++)
    {
        save_answer[i]=-1;
    }

    const clock_t begin_time = clock();
    cout<<fib_save(40);
    cout<<endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
    //stack_test7();
    cout<<endl;
    const clock_t begin_time2 = clock();
    cout<<fib(40);
    cout<<endl << float( clock () - begin_time2 ) /  CLOCKS_PER_SEC<<endl;
    return 0;
}
