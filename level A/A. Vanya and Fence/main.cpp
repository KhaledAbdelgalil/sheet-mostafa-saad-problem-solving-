#include <bits/stdc++.h>

using namespace std;

int main()
{
    int width=0;
    int number_of_friends,Height_of_fence,height_of_friend;
    cin>>number_of_friends>>Height_of_fence;
    for(int i=0;i<number_of_friends;i++)
    {
        cin>>height_of_friend;
        if(height_of_friend<=Height_of_fence)
            width++;
        else width+=2;
    }
    cout<<width;
    return 0;
}
