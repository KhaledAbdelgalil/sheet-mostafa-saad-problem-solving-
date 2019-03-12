#include <bits/stdc++.h>
using namespace std;

int n,m;
priority_queue<int>q,q1;


int main()
{

scanf("%d %d",&n,&m);
int sum_min=0;
int sum_max=0;
int x;
for(int i=0;i<m;i++)
{
  scanf("%d",&x);
  q.push(x);
  q1.push(-x);
}
    while(n!=0)
    {
        sum_max+=q.top();
        q.push(q.top()-1);
        q.pop();
        int y=-q1.top();
        sum_min+=y;
        q1.pop();
        if(y!=1) q1.push(-(y-1));
        n--;
    }
    printf("%d %d",sum_max,sum_min);
return 0;
}
