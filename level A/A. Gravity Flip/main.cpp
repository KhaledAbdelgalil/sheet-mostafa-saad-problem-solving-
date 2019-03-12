#include <iostream>
#include <vector>

using namespace std;
int Number_columns;
//#include <algorithm>
int temp;
int main()
{
    cin>>Number_columns;
    vector<int> arrange_cubes(Number_columns);
    for (int i = 0;i < Number_columns;i++)
    {
        cin>>arrange_cubes[i];
    }
  // sort(arrange_cubes.begin(),arrange_cubes.end());
  for(int i=0;i<Number_columns-1;i++)
  {
      if(arrange_cubes[i+1]<arrange_cubes[i])
      {
          temp=arrange_cubes[i];
          arrange_cubes[i]=arrange_cubes[i+1];
          arrange_cubes[i+1]=temp;
          i=-1;
      }
  }

    for (int i = 0;i < Number_columns;i++)
        cout<<arrange_cubes[i]<<" ";
    return 0;
}
