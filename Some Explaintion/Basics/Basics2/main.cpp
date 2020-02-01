#include <bits/stdc++.h>
#include <sstream>//for string formatting and delimeter(space)

using namespace std;



//fn to divide string acording to delimeter(space)
void string_formatting()
{
    string s="ahmed 12 12.5";//virtual stream
    string name;
    int num1;
    float num2;
    istringstream iss(s);
    iss>>name>>num1>>num2;
    cout<<name<<endl<<num1<<endl<<num2;
}

//fn:cin.fail and ignore to validate data
void validate_data()
{
    int n1,n2;
    cin>>n1>>n2;//cin try to read integer if 2.5 2 read 2 in n1 and try to read from .5 in n2 fail
    if(cin.fail())
    {
        cout<<"failed another time"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');//ignore that line
        cin>>n1>>n2;
        if(cin.fail()) cout<<"failed"<<endl;//2 4.5 not fail
        else cout<<n1+n2<<endl;
    }
    else cout<<n1+n2<<endl;
}

//fn:evalute expression:try it yourself && is executed befor ||
void eva()
{
    bool s ;
    s = (10>5) && (4+2*3>10) || (2*2==4) &&(5<2) && (7!=7) || (5==5) && (7+5 == 12);
    cout<<s<<endl;
}
void know_string_or_no()
{
    string line;
    getline(cin,line);
    istringstream iss(line);
    char c=iss.peek();//get first one but not consume
    cout<<c<<endl;
    if(isdigit(c)) cout<<"digit"<<endl;
    else cout<<"string"<<endl;
}

void double_difference()
{
    double a = (1.0/3.0)*11*(5.0/3.0)*(3.0/1.0)*(3.0/5.0);
   // cout<<a;
   bool comp=(a==11.0);//how come
   cout<<comp<<endl;
   double diff=fabs(a-11.0);
   cout<<diff<<endl;
   double EPSILON=1e-7;
   if(diff<EPSILON) cout<<"a Equal 11 "<<endl;
   if(fabs(a-20.0)>EPSILON && a<20 )
    cout<<"AND <20 "<<endl;
   if(fabs(a-10.9)>EPSILON && a>10.9) cout<<"AND >10.9"<<endl;
}

//repetitions:fibonacii series:
void fib()
{
    int i,a,b,temp;
    for(i=0,a=1,b=2,temp=0;i<b&&a<60;i++,temp=a+b,a=b,b=temp)
        cout<<a<< " ";
    cout<<endl<<i;
}

//template
template <class T>
T maximum(T a,T b)
{
    T ret=a>b?a:b;
    return ret;
}
//static variable
void static_var()
{
    static int x=2;//seen all time
    cout<<x<<endl;
    x++;
}
//global vs local
int x=1;
void local_vs_global()
{
    int x=10;
    cout<<x<<" "<<::x<<endl;
}

//inline fn : don't create actual fn ,copy code to caller in compiler time fn is headache in system push into stack pop from stack
inline int maximum(int a,int b)
{
    return a>b?a:b;
}
int main()
{

    //string_formatting();
    //validate_data();
    //know_string_or_no();
    //eva();
    //double_difference();
    //fib();
    //cout<<maximum(3.5,3.1);
    /*static_var();
    static_var();*/
    //local_vs_global();
    //cout<<maximum(2,3);
    return 0;
}


