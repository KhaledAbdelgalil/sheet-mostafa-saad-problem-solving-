#include<iostream>
using namespace std;
int lucky[]={4,7,74,47,44,77,444,447,474,477,747,744,777,444};
int main()

{

     int n;
    cin>>n;
    for(int i=0;i<14;i++)
    if(n%lucky[i]==0){cout<<"YES";return 0;}
    cout<<"NO";

}
