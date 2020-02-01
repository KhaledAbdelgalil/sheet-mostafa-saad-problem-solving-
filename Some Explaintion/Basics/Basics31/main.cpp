//input output stream on a file
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    /*fstream in_out;
    string path="text.txt";
    in_out.open(path.c_str(),ios::in | ios::out | ios::app );//modes of files
    string str;
    getline(in_out,str);

    cout<<str<<endl;
    in_out<<"hi hello";
    in_out.ignore(5);
    in_out>>str;
    cout<<str;*/
    freopen("text.txt","r",stdout);//redirection stream
    string str;
    cin>>str;
    freopen("text2.txt","w",stdout);
    cout<<str;
    return 0;
}
