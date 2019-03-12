#include <iostream>
#include <string>
using namespace std;
int main()
{
 int anton=0;
 int dankin=0;
 int games_played=0;
 string games;
 cin>>games_played>>games;
 for (int i=0 ;i<games_played;i++)
{
  if(games[i]=='A') anton++;
  else dankin++;
}

 if(anton>dankin) cout<<"Anton";
 else if(dankin>anton) cout<<"Danik";
 else cout<<"Friendship";

 return 0;
}
