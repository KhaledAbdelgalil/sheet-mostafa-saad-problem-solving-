#include <iostream>

using namespace std;
int money_paid=0;

int n,next_height,current_height=0,energy=0;
int main()
{

    cin>>n;
    while(n--)
    {
        cin>>next_height;
        if(current_height>=next_height)
        {
            energy+=current_height-next_height;
        }
        else
        {
            if(next_height-current_height>energy){money_paid+=next_height-current_height-energy;energy=0;}
            else energy-=next_height-current_height;
        }
        current_height=next_height;
    }
    cout<<money_paid;
    return 0;
}
/*int main()
{

    cin>>n;
    while(n--)
    {
        cin>>next_height;
        if(next_height>money_paid)
        {
            money_paid=next_height;
        }

    }
    cout<<money_paid;
    return 0;
}*/
