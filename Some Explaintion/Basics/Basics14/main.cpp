//discuss struct,union,enum,pointer to fn,data aligment

#include <iostream>

using namespace std;

int sum(int a,int b)
{
    return a+b;
}
typedef struct Employee{
    string name;
    double salary;
    int luckyNums[3];
    void set_salary(double value)
    {
        salary=value;
    }
}emp;
void print_s(emp &e)
{
    cout<<"name: "<<e.name<<endl<<"salary: "<<e.salary<<endl<<"lucky:"<<e.luckyNums[0]<<" "<<e.luckyNums[1]<<" "<<e.luckyNums[2]<<endl;
}
struct A
{
    char x;
    char y;
    int z;
};
struct B
{
    char x;
    int z;
    char y;
};
union s{
int ival;
double dval;
};
int main()
{
    emp e1={"ahmed",120.5,{10,2,3}};
    emp* e=&e1;
    print_s(e1);
    e->name="khaled";
    e->set_salary(140.5);
    print_s(e1);
    int (*ptrFn)(int,int)=&sum;
    cout<<ptrFn(2,3)<<endl;
    cout<<sizeof(A)<<" "<<sizeof(B)<<endl;
    cout<<sizeof(int)<<" "<<sizeof(double)<<" "<<sizeof(s)<<endl;
    union s s1;
    s1.ival=2;
    s1.dval=3;
    cout<<s1.ival<<" "<<s1.dval<<endl;
    return 0;
}
