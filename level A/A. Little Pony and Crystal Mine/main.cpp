#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int up_and_down=N/2;
    //up
    for(int i=0;i<up_and_down;i++)
    {
        for(int j=i;j<up_and_down;j++)
            cout<<"*";
        for(int j=0;j<1+2*i;j++)
            cout<<"D";
        for(int j=i;j<up_and_down;j++)
            cout<<"*";
        cout<<endl;
    }

    //center
    for(int i=0;i<N;i++)
        cout<<"D";
    cout<<endl;

    //down
    for(int i=0;i<up_and_down;i++)
    {
        for(int j=0;j<i+1;j++)
            cout<<"*";
        for(int j=0;j<N-2-2*i;j++)
            cout<<"D";
         for(int j=0;j<i+1;j++)
            cout<<"*";
        cout<<endl;
    }


    return 0;
}
