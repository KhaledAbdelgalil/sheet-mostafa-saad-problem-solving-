#include<iostream>
using namespace std;



int main()
{

    int a,b,c,d;
    cin>>a>>b>>c>>d;


     (max(a*3/10,a-a/250*c)>max(b*3/10,b-b/250*d))?cout<<"Misha":
     (max(a*3/10,a-a/250*c)<max(b*3/10,b-b/250*d))?cout<<"Vasya":cout<<"Tie";

}
