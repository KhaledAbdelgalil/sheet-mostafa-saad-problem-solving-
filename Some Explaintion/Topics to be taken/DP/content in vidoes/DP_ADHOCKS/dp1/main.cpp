//state is string and int cannot memorize in memory::so memorize in maps
//first calculate state if could memorized memorize it
//double memorization:use array and map :
/*memorize in map only big numbers:use that if algorithm timed out:
if it's small state take it from array big leave array and check on map as map o(logN)*/
//2 players play with same stratgy but different terminal
//in this problem state is very important not taken all the number
#include <bits/stdc++.h>
using namespace std;

int reverse_int(int a)
{
    ostringstream oss;
    oss<<a;
    string b=oss.str();
    reverse(b.begin(),b.end());
    istringstream iss(b);
    iss>>a;
    return a;
}
typedef pair< pair<int,int>,pair <int,int> > entry;
map<entry,int> mp;
int play(int a,int b,int player,int steps)//0 mano wins 1 losses
{
    if(a==b)return 0;
    if(steps>1000) return 1;
    entry p=make_pair(make_pair(a,b),make_pair(player,steps));
   if(mp.count(p)) return mp[p];

    if(play(b,a/10,!player,steps+1)==player)
        return mp[p]=player;

    if(play(b,reverse_int(a),!player,steps+1)==player)
        return mp[p]=player;
    return mp[p]=!player;
}
class TheNumberGame
{
public:
   string determineOutcome(int A, int B)
   {
        if(!play(A,B,0,0)) return "Manao wins";
        else return "Manao loses";
   }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
