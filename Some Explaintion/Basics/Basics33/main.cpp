//this tutorial deals with c++11 standards you need to add this standards to your project
#include <bits/stdc++.h>
#include<tuple>
using namespace std;
void defined_macros()
{
    cout<<__FILE__<<endl;
    cout<<__TIME__<<endl;
    cout<<__DATE__<<endl;
    cout<<__LINE__<<endl;
}

 map < string, pair < int,int > > computeMp()
 {
      map < string, pair < int,int > > mp={
    {"ahmed",{0,2}
    },{"yossef",{1,2}
    }};
    return mp;
 }
void Auto_specifier_list_intializer_rangeLoop()
{
    auto mp=computeMp();

    for(auto it=mp.begin();it!=mp.end();it++)//auto deduce from its initializer
        cout<<it->first<<" : "<<it->second.first<<" "<<it->second.second<<endl;

        cout<<endl<<"rangeLoop"<<endl<<endl;
     for(auto& it:mp)//auto deduce from its initializer & for read and write without & read only
        cout<<it.first<<" : "<<it.second.first<<" "<<it.second.second<<endl;
}

void Tuple()
{
    tuple<int,char>bar;//you can define it as this
    auto tp=make_tuple("ss",10,14.4,"ssd");
    //for acess
    get<2>(tp)=2.2;
    cout<<get<2>(tp)<<endl;

    int myint;
    string mystring;
    //unpack elements
    tie(ignore,ignore,myint,mystring)=tp;
    cout<<myint<<endl<<mystring<<endl;
}
//
int sum()
{
    return 0;
}
template <typename T,typename ... Args>
T sum(T a,Args ... args)
{
    return a+sum(args...);
}
void varadic_fn()
{
    cout<<sum(2,3,4,5,1)<<endl;
    cout<<sum()<<endl;
    cout<<sum(1.1,2.1);
}
//move
vector<int>compute()
{
    return {1,2,3};
}
void move_RawString()
{
    vector<int>A=compute();
    vector<int>B=move(A);
    vector<int>C=move(compute());//better than 2 lines think why?

    string s=R"(hello\n)";

    cout<<s<<endl;
    string s2=
    R"(hello,
       safY)";
    cout<<s2<<endl;

}
bool isOdd(int i)
{
    return i%2!=0;
}
void lambda1()//fn without name
{
    vector<int>v={1,2,3,4,5};
    cout<<count_if(begin(v),end(v),isOdd)<<endl;
    cout<<count_if(begin(v),end(v),[](int i){
    return i%2!=0;})<<endl;
}
template<typename function>
void perform(function operation,vector<int>&v)
{
    for(auto &val:v)
        val=operation(val);
}
void lambda2()
{
    auto square=[](int i){return i*i;};
    auto addone=[](int i){return i+1;};
    auto print=[](int i){cout<<i<<" ";return i;};
    vector<int>v={1,2,3,4,5};
    perform(square,v);
    perform(addone,v);
    perform(print,v);


}
void lambda3()//fn see my local variables(readonly)=  update and read &
{
    int factor=1;
    auto addfactor=[=](int i){return i+factor;};
    auto print=[](int i){cout<<i<<" ";return i;};
    vector<int>v={1,2,3,4,5};
   perform(addfactor,v);
   perform(print,v);
    int sum=0;
    for_each(begin(v),end(v),[&sum,factor](int i){
             sum+=i;
             return;
             });
cout<<endl<<sum<<endl;
    sort(begin(v),end(v),[](int a,int b){return a>b;});
    perform(print,v);
}
int main()
{
    //shared_ptr<int>ptr(int int);//class let memorymanagement on c++ if you want if c++ fount internal counter of ptr 0 free it
    //@ creatin count=1 when pass to fn count=2 go out of fn count=1 main finished count=0
   //defined_macros();
   //Auto_specifier_list_intializer_rangeLoop();
   //Tuple();
   //varadic_fn();
   //move_RawString();
  // lambda1();
    //lambda2();
    lambda3();
    return 0;
}
