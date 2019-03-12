#include <iostream>
#include <string.h>
using namespace std;

int stones_number;//size of string i.e size of array of characters
string color_of_stones;
int output_count=0;

int main()
{
    cin>>stones_number>>color_of_stones;
    for(int i=1;i<stones_number;i++)
    {
        if(color_of_stones[i]==color_of_stones[i-1])
            output_count++;
    }
    cout<<output_count;
    return 0;
}
