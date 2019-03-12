#include <iostream>
#include <string.h>
#include <stdlib.h> // this for abs

using namespace std;
string input;
int flag_firstTime=0;
int difference;
int steps=0;
int main()
{
    cin>>input;
    for (int i = 0;i < input.size();i++)
        {
          if (flag_firstTime == 0)
             {
               flag_firstTime=1;
               difference=abs(input[i]-'a');
               if(difference>=13)
                steps+=(26-difference);
               else steps+=difference;
             }
          else
             {
                difference=abs(input[i]-input[i-1]);
               if(difference>=13)
                steps+=(26-difference);
               else steps+=difference;
             }

        }
   cout<<steps;
    return 0;
}
