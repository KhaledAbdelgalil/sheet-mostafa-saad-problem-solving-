#include<bits/stdc++.h>
using namespace std;
bool visited[109];

struct tree{

int pos;
int apples;

};
bool sort_struct(struct tree t1,struct tree t2)
{
    return t1.pos<=t2.pos;
}
int main()
{
        int n;
        int number_negative=0,number_positive=0;
        long long out=0;
            cin>>n;

        struct tree arr[n]  ;
        for(int i=0;i<n;i++)
            {
            cin>>arr[i].pos;
            cin>>arr[i].apples;
            if(arr[i].pos<0)
                number_negative++;
            else number_positive++;
            }
        sort(arr,arr+n,sort_struct);

if(number_negative==0)
{
    cout<<arr[0].apples;
    return 0;
}
if(number_negative==n)
{
    cout<<arr[n-1].apples;
    return 0;
}
out=0;
if(number_negative<=number_positive)
{
    for(int i=0;i<number_negative*2+1;i++)
    {
        if(i==n) break;
        out+=arr[i].apples;
    }
    cout<<out;
    return 0;
}
for(int i=n-1-2*number_positive;i<n;i++)
    out+=arr[i].apples;

    cout<<out;
}
