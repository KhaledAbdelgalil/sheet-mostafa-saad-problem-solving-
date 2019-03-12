#include <iostream>

using namespace std;
char arr[10009];
int n;

bool valid(int i)
{
    int count_no=0;
    if(i-1>=0&&i%n!=0) if(arr[i-1]=='o') count_no++;
    if(i+1<=n*n&&(i+1)%n!=0) if(arr[i+1]=='o') count_no++;
    if(i-n>=0) if(arr[i-n]=='o') count_no++;
    if(i+n<=n*n) if(arr[i+n]=='o') count_no++;

    return count_no%2==0;
}
int main()
{
    cin>>n;
    for(int i=0;i<n*n;i++)
        cin>>arr[i];
    for(int i=0;i<n*n;i++)
    {

        if(!valid(i)){ cout<<"NO"; return 0;}
    }
    cout<<"YES";
    return 0;
}
