#include <bits/stdc++.h>
using namespace std;
void learn_string()
{
    string str("ahmed mostafa tat");
    cout<<str.substr(3,6)<<endl;
    cout<<int(str.find("mostafa",7))<<endl;
    cout<<int(str.find("mostafa"))<<endl;
    cout<<str.find_last_of("tat")<<endl;
    cout<<str.find_last_of("d|t")<<endl;
    cout<<str.find_first_of("d|t")<<endl;
    cout<<str.find_first_not_of("d|t")<<endl;
    str.replace(14,3,"hi");
    cout<<str<<endl;
    str.erase(12);
    cout<<endl;
    cout<<str<<endl;
    str.erase(0,2);
    cout<<str<<endl;
    //convert array of char to string and vise versa
    char arr[5]={'a','b','c','d'};
    string t=arr;
    cout<<t<<endl;
    const char* s=t.c_str();
    for(int i=0;i<4;i++)
        cout<<s[i];
}
void learn_stream()
{
    //vector printed as string
    vector<int>v;
    v.push_back(40);
    v.push_back(50);
    ostringstream oss;
    copy(v.begin(),v.end(),ostream_iterator<int>(oss,","));
    cout<<oss.str()<<endl;
    istringstream iss("10 20 30");
    int x;
    while(iss>>x)
   cout<<"readed x "<<x<<'\n';
}
bool string_startWith(string str,string path)
{
    return (int)str.find(path)==0;
}
bool string_endWith(string str,string path)
{
    int pos=str.rfind(path);
   // cout<<pos<<endl;
    return pos!=-1&&pos+path.size()==str.size();
}
void learn_operations_on_array()
{
    int val[]={1,-2,3,-4,5};
    valarray<int>v1(val,5);
    for(int i=0;i<5;i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    valarray<int>v2=abs(v1);
    for(int i=0;i<5;i++)
        cout<<v2[i]<<" ";
    cout<<endl;
    cout<<v2.sum()<<endl;

    valarray<int>v3=2*(v1+v2);
    for(int i=0;i<5;i++)
        cout<<v3[i]<<" ";
    cout<<endl;
    valarray<bool>v4=(v1==v2);
    for(int i=0;i<5;i++)
        cout<<v4[i]<<" ";
    cout<<endl;
    cout<<v4.max()<<endl;
}
int main()
{

    //learn_string();
    //learn_stream();
    //cout<<string_startWith("mostafa","st")<<endl;
    //cout<<string_startWith("mostafa","mo")<<endl;
    //cout<<string_endWith("mostafa","da")<<endl;
    //cout<<string_endWith("mostafa","fa")<<endl;
    learn_operations_on_array();
    return 0;
}
