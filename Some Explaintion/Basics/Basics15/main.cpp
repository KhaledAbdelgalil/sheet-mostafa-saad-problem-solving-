//dealing more with struct and overloading operators
//dealing with struct as fn:better than as we can store how many times this fn is called

#include <bits/stdc++.h>

using namespace std;
//in struct:default is public
typedef struct Employee{
    string name;
    double salary;
    void set_salary(double value)
    {
        salary=value;
    }
    void add_salary(double value);
    Employee(string My_name,double salary)//constructo
    {
        cout<<"Creating new object"<<endl;
        this->salary=salary;//internal pointer//useful because paramter called salary and attribute called salary
        name=My_name;
    }
    ~Employee()
    {
        cout<<"Destroying object"<<endl;
    }
    void print();
    int length_of_name()
    {
        return name_length();
    }

//overloading operator
bool operator ==(const Employee &b)
{
    return name==b.name && salary==b.salary;
}
private:
    int name_length()
    {
        return name.size();
    }

}emp;

void emp::add_salary(double value)
{
    salary+=value;
}
void emp::print()
{
    cout<<name<<" has salary: "<<salary<<endl;
}


struct SortingByName
{
    bool operator()(const emp &a,const emp &b)
    {
        if(a.name!=b.name)
            return a.name<b.name;
        return a.salary<b.salary;
    }
};
struct SortingBysalary
{
    bool operator()(const emp &a,const emp &b)
    {
        if( a.salary!=b.salary)
            return a.salary<b.salary;
        return a.name<b.name;
    }
};
void test1()
{

    emp E1("ali",120.5);
    E1.print();
    cout<<E1.length_of_name()<<endl;
    if(E1==E1) cout<<"there are same Employees"<<endl;
}
bool comp(const emp &a,const emp &b)
    {
        if( a.salary!=b.salary)
            return a.salary<b.salary;
        return a.name<b.name;
    }
void test2()
{
    emp Es[3]={{"ahmed",12.0},{"ali",10.0},{"sara",15.0}};
    sort(Es,Es+3,SortingBysalary());
    for(int i=0;i<3;i++)
        Es[i].print();
}
int main()
{
    //test1();
    test2();
    return 0;
}
