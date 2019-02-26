
/*************************************************
*   author: khaledLooda                           *
*   National Egyptain                             *
*   king of suspense                              *
*************************************************/
#include<bits/stdc++.h>

using namespace std;
int computer_numbers;
typedef struct computer{

int price;
int quality;
}computer;
bool compare(const computer &a,const computer &b)
{
    if(a.price<b.price)return 1;
    return 0;
}

int main()
{
    cin>>computer_numbers;
    computer comps[computer_numbers];

    for(int i = 0 ;i < computer_numbers ;i++)
      cin>>comps[i].price>>comps[i].quality;
   sort(comps,comps+computer_numbers,compare);
   for(int i=0;i<computer_numbers-1;i++)
    if(comps[i].quality>comps[i+1].quality)
   {cout<<"Happy Alex";return 0;}

      cout<<"Poor Alex";
    return 0;
}
