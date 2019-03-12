#include <iostream>
#include <vector>
using namespace std;
int Cookies_Bags_Number;
int ways_number=0;
int Cookies_sum=0;
int main()
{
    cin>>Cookies_Bags_Number;
    vector<int> cookies_array(Cookies_Bags_Number);
    for (int i = 0; i < Cookies_Bags_Number ;i++)
    {
        cin>>cookies_array[i];
        Cookies_sum+=cookies_array[i];
    }
   for (int i = 0; i < Cookies_Bags_Number ;i++)
   {
     if (Cookies_sum % 2 == 0 && cookies_array[i] % 2 == 0) ways_number++;
     else if (Cookies_sum % 2 != 0 && cookies_array[i] % 2 != 0) ways_number++;
   }
   cout<<ways_number;
    return 0;
}
