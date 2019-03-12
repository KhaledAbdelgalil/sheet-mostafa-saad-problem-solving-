#include <iostream>
#include <string>
using namespace std;
string firstPresent=" ",secondPresent=" ";
int main()
{
  cin>>firstPresent>>secondPresent;

  if(firstPresent.size()==secondPresent.size()){
  for (int i=0;i<firstPresent.length();i++){
         firstPresent[i]=tolower(firstPresent[i]);
         secondPresent[i]=tolower(secondPresent[i]);
        }

        if(firstPresent<secondPresent)
            {
                cout<<-1;
            }
        else if(firstPresent>secondPresent)
            {
                cout<<1;
            }
        else
        {
         cout<<0;
        }
  }



    return 0;
}
