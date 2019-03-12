#include <iostream>

using namespace std;

int main()
{
   string in;
   int cp=0;
   cin>>in;
   for(int i=0;i<in.size();i++)
   {
       if(isupper(in[i])) cp++;
   }
   if(cp>in.size()-cp)
   {
       for(int i=0;i<in.size();i++)
        in[i]=toupper(in[i]);
   }
   else {
       for(int i=0;i<in.size();i++)
        in[i]=tolower(in[i]);
   }
   cout<<in;
    return 0;
}
