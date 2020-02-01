//bits-usage:better time order
#include <bits/stdc++.h>
#include<bitset>
using namespace std;
void bits_usage()
{
    unsigned int x=3;
    unsigned int y=5;
    unsigned int z=2;
    cout<<(x&y)<<endl;
    cout<<(x|y)<<endl;
    cout<<(x^y)<<endl;
    cout<<((x^y)^(x^y^z))<<endl;//common z

}
void shift()
{
    int x=2;
    cout<<(x>>1)<<endl;
    cout<<(x<<1)<<endl;
}
void even_or_odd()
{
    //x%2^n(fail when negative) ==  x&2^n -1(works always)

    int x=2;
    int y=3;

    if(x&1) cout<<x<<" is odd"<<endl;
    else cout<<x<<" is even"<<endl;

    if(y&1) cout<<y<<" is odd"<<endl;
    else cout<<y<<" is even"<<endl;
}
void check_specific_number()
{
    int num=4; //100;
    //check bit 2
    if((num>>2)&1) cout<<"bit 2 is on"<<endl;
}
void print_number_binary(int n,int len)
{
    if(!len) return;

    print_number_binary((n>>1),len-1);//remove last bit
    cout<<(n&1);//print last bit
}
int count_bits_in_number(int mask)
{
    int ret=0;
    while(mask)
    {
        if(mask&1) ret++;//if last bit is 1 add to ret
        mask>>=1;//remove last bit
    }
    return ret;
}
//some operations on bits
int get_bit(int n,int idx)
{
    return ((n>>idx)&1)==1;
}
int set_bit(int n,int idx)
{
    n|=(1<<idx);
    return n;
}
int clear_bit(int n,int idx)
{
    n&=~(1<<idx);
    return n;
}
int flip_bit(int n,int idx)
{
    n^=(1<<idx);
    return n;
}
//I use unsigned short to see and invesgate o/p as it's easy 16 bits
unsigned short rotate_to_right(unsigned short n,int value_of_rotation)
{
    cout<<n<<endl;
    int reverse_value=16-value_of_rotation;
    n=(n>>value_of_rotation)|(n<<reverse_value);
}
int count_bits_in_number2(int mask)
{
    int ret=0;
    while(mask)
    {
        mask&=(mask-1);//remove last 1 bit if 1000&(1000-0001)=1000&0111=0 last 1 bit removed
        ret++;
    }
    return ret;
}

//print all subsets
int graycode(int i)
{
    return i^(i>>1);
}
void printAllsubsets(int len)
{
    cout<<"binary    Gray"<<endl;
    for(int i=0;i<(1<<len);i++)
        {

            print_number_binary(i,len);
            cout<<"        ";
            print_number_binary(graycode(i),len);
            cout<<endl;
        }
}
//preserve your own mask
void get_all_sub_masks(int mask)
{
    for(int submask=mask;submask;submask=(submask-1)&mask)
    {print_number_binary(submask,32);cout<<endl;}
}

//get interesction of 2 arrays:convert 2 arrays into masks and and theses masks
void interesection(int A[],int len1,int B[],int len2)
{
    int mask1=0,mask2=0;
    for(int i=0;i<len1;i++)
        mask1=set_bit(mask1,A[i]);
    for(int i=0;i<len2;i++)
        mask2=set_bit(mask2,B[i]);

    int inter=mask1&mask2;

    for(int i=0;i<32;i++)
    {
        if(get_bit(inter,i)) cout<<i<<" ";
    }
    cout<<'\n';
}
void test()
{
    //this valid if arr1 and arr2 doesn't contain more than 32 as value
    int arr1[]={32,1,2,3,4,5,6,7};
     int arr2[]={33,4,5,6,7,8,9};//here overflow
     interesection(arr1,8,arr2,7);
}
//always with bits operation put paranthesis
//in graph theory:maintain negihbours in a mask if nodes less than 64

//char is 1 byte 8 bits treat each bit as individual visit
#define N 64
char vis[64/8];//all non visited
bool isVis(int idx)
{
    return vis[(idx>>3)]&(1<<(idx&7));//i%8
}
void set_vis(int idx)
{
    vis[idx>>3]|=(1<<(idx&7));
}
void bit_set()//bitset is a mask
{
    //better in memory
    string s="1000";
    const int n=10;
    bitset<n>x(s);//
    cout<<x<<endl;
    x.set(9);
    cout<<x<<endl;
    x.flip(9);
    cout<<x<<endl;
    x|=3;
    cout<<x<<endl;
    unsigned long l=x.to_ulong();
    cout<<l<<endl;
    x.set(9);
    if(x[9]==1) cout<<"ok"<<endl;
    x=10;
    cout<<x<<endl;
}
int main()
{

    //bits_usage();
    //shift();
    //even_or_odd();
   // check_specific_number();
   //print_number_binary(5,5);
   //cout<<count_bits_in_number(7)<<endl;
  // cout<<get_bit(6,2);
  //cout<<set_bit(6,0);
  //cout<<clear_bit(7,0);
  //cout<<flip_bit(5,0);
 // cout<<rotate_to_right(3,2);
    //cout<<count_bits_in_number2(7)<<endl;
    //cout<<__builtin_popcount(7)<<endl;
   //printAllsubsets(4);
   //get_all_sub_masks(5);
  // test();
  bit_set();
    return 0;
}
