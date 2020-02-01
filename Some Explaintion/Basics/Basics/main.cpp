#include <iostream>
#include <iomanip>//for setprecsion
#include <sstream>//for string formatting and delimeter(space)
using namespace std;


//fn to show in hex base and so on

void show_base()
{
    cout<<showbase<<hex<<15<<endl;
    cout<<15<<endl;
    cout<<showbase<<oct<<15<<endl;
    cout<<showbase<<uppercase<<hex<<15<<endl;
    cout<<showbase<<dec<<15<<endl;



}
//trying setw
void fn_setw()
{
    //set window of coming field by 3 and show right shifted
    cout<<setw(3)<<6<<endl<<setw(3)<<8<<endl<<setw(3)<<124<<endl<<"---\n"<<setw(3)<<6+8+124<<endl;
    //setw is ignoring if what will be shown is greater than window
}
//fn setPrecision
void fn_setprecision()
{
    float a=2.9578;
    cout<<setprecision(4)<<a<<endl;//show in 4 digits
    cout<<a<<endl;//a will be affected by setprecision
}
//try iosflag:reperesentation
void fn_iosflag()
{
    cout<<"|"<<setw(20)<<142.1<<"|\n";
    cout<<"|"<<setw(20)<<setiosflags(ios::left)<<142.1<<"|\n";
    cout<<"|"<<setw(20)<<setiosflags(ios::scientific)<<142.1<<"|\n";
    cout<<"|"<<setw(20)<<setiosflags(ios::right)<<142.1<<"|\n";

}
void escape_char()
{
    //see \ treat coming after sepcial treatment
    cout<<"\\"<<endl;
    cout<<2<<"\bremove:2"<<endl;
    cout<<"\a"<<endl;
}

void ASCI()
{
    cout<<(int)'0'<<endl;
    cout<<(char)48<<endl;
}
void read_fn()
{
    cout<<"Enter a long string contains space"<<endl;
    string s;
    getline(cin,s);//read enter:\n
    cout<<s<<endl;
    cout<<"Enter your name separted by | and also salary eg:ahmed|aly|150"<<endl;
    string first,second;
    float salary;
    getline(cin,first,'|');//getline read string
    getline(cin,second,'|');
    cin>>salary;
    cout<<first<<endl<<second<<endl<<salary;

}
int main()
{
    //show_base();
   // fn_setw();
   //fn_setprecision();
   //fn_iosflag();
   //escape_char();
    //ASCI();
    //read_fn();
    return 0;
}
