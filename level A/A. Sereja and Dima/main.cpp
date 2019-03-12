#include <bits/stdc++.h>

using namespace std;

deque<int> q;//cards_arrangement
int main()
{
    int flag_door_meen=0;//sereja=0,dima=1
    int cards_number,x,y=0;//x is temp to cin in it then used to calculate sereja score and y fpr dima score
    cin>>cards_number;
    for(int i=0;i<cards_number;i++)
    {
        cin>>x;
        q.push_front(x);
    }
    x=0;
    while(!q.empty())
    {
        switch(flag_door_meen)
        {
          case 0: if(q.front()>q.back())
                 {
                     x+=q.front();
                     q.pop_front();
                 }
                 else
                 {
                      x+=q.back();
                     q.pop_back();
                 }
                 flag_door_meen=1;
                 break;
          case 1:
                if(q.front()>q.back())
                 {
                     y+=q.front();
                     q.pop_front();
                 }
                 else
                 {
                      y+=q.back();
                     q.pop_back();
                 }
                 flag_door_meen=0;
                 break;

        }

    }


   cout<<x<<" "<<y;

    return 0;
}
