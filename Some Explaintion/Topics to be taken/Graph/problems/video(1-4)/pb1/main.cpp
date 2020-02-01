//spoj problem::https://www.spoj.com/problems/GALOU/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>v;
    int n;
    unsigned long long in;
    cin>>n>>in;
    for(int i=0;i<n;i++)
    {
        int f=in%10;
        in/=10;
        switch(f)
        {
            case 9:v.push_back(7);
                   v.push_back(3);
                   v.push_back(3);
                   v.push_back(2);
                   break;
            case 8:v.push_back(7);
                   v.push_back(2);
                   v.push_back(2);
                   v.push_back(2);
                   break;
            case 7:
            case 5:
            case 3:
            case 2:v.push_back(f);
                    break;
            case 4:
                    v.push_back(2);
                     v.push_back(2);
                      v.push_back(3);
                     break;
            case 6: v.push_back(5);
                    v.push_back(3);
                    break;
        }
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++)
        cout<<v[i];
    return 0;
}
