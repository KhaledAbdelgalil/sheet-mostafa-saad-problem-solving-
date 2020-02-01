//stls

#include <bits/stdc++.h>
using namespace std;

#define all(v)  ((v).begin()),((v).end())
#define sz(v)   ((int)((v).size()))
typedef vector<int> vi;
bool is_odd(int n){if(n==0) return 0;return n%2!=0;}
bool is_even(int n){if(n==0) return 0;return n%2==0;}
bool is_zero(int n){return n==0;}
void print_vect(vi &v)
{
    vi :: iterator it=v.begin();
    while(it!=v.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
}
void learn_vector1()
{

    vi v(10);//initialize 10 elements with zero
    vi v1(10,7);//initialize 10 elements with 7

    //building vector from array
    const int length=6;
    int arr[length]={5,2,7,2,0,2};
    vi v2(arr,arr+length);
    //building vector from vector
    vi v3(all(v));

    //resize vector from 10 to 25
    v.resize(25);
    vi :: iterator it=v2.begin();
    while(it!=v2.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    //sorting decreasing
    sort(all(v2),greater<int>());
    cout<<endl;
    it=v2.begin();
    while(it!=v2.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    sort(v2.rbegin(),v2.rend());
    cout<<endl;
    it=v2.begin();
    while(it!=v2.end())
    {
        cout<<*it<<" ";
        ++it;
    }
}

void learn_vector2()
{
    //create 2d vector of bool 10*20 filled with trues;
    vector< vector <bool> > vbs(10,vector <bool>(20,true));

    const int length=6;
    int arr[length]={5,2,7,2,0,2};
    vi v2(arr,arr+length);

    //remove second element
    v2.erase(v2.begin()+1);
    print_vect(v2);

    //insert at element 3
    v2.insert(v2.begin()+2,20);
    print_vect(v2);

    //append
    v2.push_back(20);
    print_vect(v2);

    //find element
    if(find(all(v2),7)!=v2.end())
        cout<<"found"<<endl;
    //reverse vector
    reverse(all(v2));
    print_vect(v2);

    //remove last element
    v2.pop_back();
    print_vect(v2);

    //clear vector
    cout<<"sizeBeforeClearing:"<<sz(v2)<<endl;
    v2.clear();
    cout<<"sizeAfterClearing:"<<sz(v2)<<endl;
}

void learn_vector3()
{
    const int length=6;
    int arr[length]={5,2,7,2,0,2};
    vi v2(arr,arr+length);

    //distance between 2 iterators
    cout<<"distance: "<<distance(v2.begin()+4,v2.begin())<<endl;
    cout<<"distance: "<<distance(v2.begin(),v2.begin()+4)<<endl;

    //copy
    vi v2_cpy=v2;
    print_vect(v2_cpy);

    //replace every 2 with 4
    replace(all(v2_cpy),2,4);
    print_vect(v2_cpy);

    //replace on certain condition even==1 odd==-1 zero==0
    replace_if(all(v2_cpy),is_odd,-1);
    replace_if(all(v2_cpy),is_even,1);
    replace_if(all(v2_cpy),is_zero,0);
    print_vect(v2_cpy);
}
void learn_vector4()
{

    const int length=7;
    int arr[length]={5,2,2,2,0,3,5};
    vi v2(arr,arr+length);
    vi v2_sub(arr+3,arr+6);
    print_vect(v2_sub);

    //search 3 consecutive elements
    vi::iterator it=search_n(all(v2),3,2);
    it--;
    cout<<*it<<endl;
    it=search_n(all(v2),3,5);
    it--;
    cout<<*it<<endl;

    //search for subvector in vector
    it=search(all(v2),all(v2_sub));
    cout<<*(it+3)<<endl;


}
void learn_vector5()
{
    const int length=9;
    int arr[length]={5,2,2,2,2,2,0,3,5};
    vi v2(arr,arr+length);
    //unique method try to guess it
    vi::iterator it=unique(all(v2));
    print_vect(v2);

    //interesection
    const int length_inters=6;
    int arr1[length_inters]={1,2,3,4,5,6};
    int arr2[length_inters]={5,6,7,8,9,10};

    vi v_int1(arr1,arr1+length_inters);
    vi v_int2(arr2,arr2+length_inters);
    vi v;
    set_intersection(all(v_int1),all(v_int2),back_inserter(v));
    print_vect(v);
}


void learn_vector6()
{
    const int length_inters=6;
    int arr1[length_inters]={1,2,3,4,5,6};
    int arr2[length_inters]={5,6,7,8,9,10};
    //difference:nums in v1 not in v2:its application to know if v2 found in v1 or not if returned is an empty vector ok
    vi v_int1(arr1,arr1+length_inters);
    vi v_int2(arr2,arr2+length_inters);
    vi v;
    set_difference(all(v_int1),all(v_int2),back_inserter(v));
    print_vect(v);
    //union
    v.clear();
    set_union(all(v_int1),all(v_int2),back_inserter(v));
    print_vect(v);

    //max element
    vi::iterator it=max_element(v.begin(),v.end());
    cout<<*it<<endl;

    //swap Ranges
    cout<<"Swapping:"<<endl;
    print_vect(v_int1);
    print_vect(v_int2);
    swap_ranges(v_int1.begin(),v_int1.end(),v_int2.begin());
    print_vect(v_int1);
    print_vect(v_int2);
    //accumulate
    int sum=accumulate(all(v_int2),0);
    cout<<sum;
    int product=accumulate(all(v_int2),1,multiplies<int>());
    cout<<endl<<product<<endl;

    int inner_prod=inner_product(v_int1.begin(),v_int1.begin()+1,v_int2.begin(),0);
    cout<<inner_prod<<endl;
    cout<<inner_product(v_int1.begin(),v_int1.begin()+1,v_int2.begin(),1,multiplies<int>(),plus<int>())<<endl;

}



bool cond(const int&a,const int &b)
{
    if(b==6&&a==5)
        return true;
    return false;
}

void learn_vector7()
{
    const int length_inters=6;
    int arr1[length_inters]={1,2,3,4,5,6};
    vi v(arr1,arr1+length_inters);
    vi v_partial_sum;
    partial_sum(all(v),back_inserter(v_partial_sum));
    print_vect(v_partial_sum);
    ostringstream ss;
    partial_sum(all(v),ostream_iterator<int>(ss," "));
    cout<<ss.str()<<endl;

    //adjacent difference
    vi v3(6);
    adjacent_difference(all(v_partial_sum),v3.begin());
    //adjacent_difference(all(v_partial_sum),v3.begin(),plus<int>());
    print_vect(v3);

    //find first matching condition
    vi::iterator it=adjacent_find(all(v3),cond);
    cout<<*it<<endl;

    //count number of 6 in a vector
    int countt=count(all(v3),6);
    cout<<countt<<endl;
    //remove number and put it at v.end() and decrement v.end()
   v3.erase( remove(all(v3),1),v3.end());
   for(it=v3.begin();it!=v3.end();it++)
    cout<<*it<<" ";

}


int main()
{
    //learn_vector1();
    //learn_vector2();
    //learn_vector3();
    //learn_vector4();
    //learn_vector5();
    //learn_vector6();
    learn_vector7();
    return 0;
}
