/*#include <bits/stdc++.h>

using namespace std;
vector< int > brothers[100+9];
int candy[10000+9];//max size n*n+slack
int n;
init()
{
for(int i=0;i<n*n;i++)
    candy[i]=i+1;
}
int main()
{
    cin>>n;
    init();//initalize candy bags
    int bag_position=0;
    for(int i=0;i<n/2;i++)//n bags needed for each brothers n*n/n I will add 2 at once one from beginning and one from end
    {
        for(int j=0;j<n;j++)//n brothers every time give him 2 bags
        {
            brothers[j].push_back(candy[bag_position]);
            brothers[j].push_back(candy[n*n-1-bag_position]);
            bag_position++;
        }
    }

    for(int i=0;i<n;i++)//i  brother
    {
        for(int j=0;j<n;j++)//j bag
        cout<<brothers[i][j]<<" ";

        cout<<endl;
    }
    return 0;
}
*/



/*
2nd solution after modification to 1st if you have 4 brothers then you have 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 candies
then give each brother 2 bags from start and 2 bags from end
1+16 and 2+15 i.e 17 and 17
3+14 and 4+13 i.e 17 and 17 so add 1 to start and subtract one from finish


*/



#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin>>n;
    int start=1,finish=n*n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)//2 bags each time
            cout<<start++<<" "<<finish--<<" ";

        cout<<endl;
    }
    return 0;
}
