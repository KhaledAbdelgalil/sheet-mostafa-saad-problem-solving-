#include <iostream>

using namespace std;

int main()
{
    int n,x,sum_bad=0;
    cin>>n;
    int arr[n+9]={0};//0 means good car 1 means bad car
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                cin>>x;
                if(x==1||x==3)
                    {if(arr[i]!=1) sum_bad++; arr[i]=1;}
                else if(x==2||x==3)
                    {if(arr[j]!=1) sum_bad++;arr[j]=1;}
            }

    cout<<n-sum_bad<<endl;
    for(int i=1;i<=n;i++)
        if(arr[i]==0) cout<<i<<" ";
    return 0;
}
