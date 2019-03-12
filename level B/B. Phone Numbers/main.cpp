#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define  name first.first
#define  taxi first.second
#define  girl second.first
#define  pizza second.second

vector< pair< pair<string,int>,pair<int,int> > > p;

int main()
{
    int t,n;
    cin>>t;
    string number;
    int maxtaxi=-1;
    int maxpizza=-1;
    int maxgirl=-1;
    pair< pair<string,int>,pair<int,int> > temp;

    for(int i=0;i<t;i++)
    {
        temp.taxi=0;
        temp.girl=0;
        temp.pizza=0;
        cin>>n>>temp.name;
        while(n!=0)
        {
            cin>>number;
            if(number[0]==number[1]&&number[0]==number[3]&&number[0]==number[4]&&number[0]==number[6]&&number[0]==number[7])
            {
                temp.taxi++;
            }
            else if(int(number[0])>int(number[1])&&int(number[1])>int(number[3])&&int(number[3])>int(number[4])&&int(number[4])>int(number[6])&&int(number[6])>int(number[7]))
                {
                    temp.pizza++;
                }
            else temp.girl++;
            n--;
        }
        maxpizza=max(maxpizza,temp.pizza);
        maxgirl=max(maxgirl,temp.girl);
        maxtaxi=max(maxtaxi,temp.taxi);
        p.push_back(temp);
    }
    int printcomma=0;
    cout<<"If you want to call a taxi, you should call: ";
    for(int i=0;i<t;i++)
    {
        if(p[i].taxi==maxtaxi){
            if(printcomma) cout<<", "<<p[i].name;
            else {cout<<p[i].name;printcomma=1;}
        }
    }
    cout<<'.';
    cout<<endl;
      printcomma=0;
    cout<<"If you want to order a pizza, you should call: ";
    for(int i=0;i<t;i++)
    {
        if(p[i].pizza==maxpizza){
            if(printcomma) cout<<", "<<p[i].name;
            else {cout<<p[i].name;printcomma=1;}
        }
    }
     cout<<'.';
    cout<<endl;
      printcomma=0;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i=0;i<t;i++)
    {
        if(p[i].girl==maxgirl){
            if(printcomma) cout<<", "<<p[i].name;
            else {cout<<p[i].name;printcomma=1;}
        }
    }
     cout<<'.';
    cout<<endl;
    return 0;
}
