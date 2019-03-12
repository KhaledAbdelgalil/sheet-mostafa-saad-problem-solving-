#include<iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    if(n>=m){
        cout<<n-m;
        return 0;
    }
    int k = 0;
    while(m>n){
        if(m%2!=0){
            m = m+1;
        }
       else m = m/2;
        k++;
    }
    if(m==n){
        cout<<k;
        return 0;
    }
    k = k + n-m;
    cout<<k;


}
