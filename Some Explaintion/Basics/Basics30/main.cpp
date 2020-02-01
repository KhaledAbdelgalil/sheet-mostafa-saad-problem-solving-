//cerr:for error o/p stream unbufferd &&clog/cout:buffered(endl forces flushing)
//streams
#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream of("out.txt");
    if(in.fail())
    {
        cout<<"cannot open file"<<endl;
        return -1;
    }
    int x;
    in>>x;
    cout<<x;
    in.close();
    if(of.fail())
    {
        cout<<"failed"<<endl;
        return -2;
    }
    of<<"output:"<<x;
    of.close();
}
